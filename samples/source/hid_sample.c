/*
 * Swamp - cooperative multitasking operating system
 * Copyright (c) 2016 rksdna
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stm32/usart.h>
#include <stm32/gpio.h>
#include <stm32/rcc.h>
#include <stm32/flash.h>
#include <threads.h>
#include <timers.h>
#include <debug.h>
#include <tools.h>
#include <hid.h>

void debug_put(void *data, char value)
{
    while (~USART1->SR & USART_SR_TXE)
        continue;

    USART1->DR = value;
}

struct stream debug_stream = {debug_put, 0};

static struct hid_keyboard_report keyboard;
static struct hid_mouse_report mouse;

static void press(u8_t code)
{
    keyboard.keys[0] = code;
    write_hid_keyboard_report(&keyboard);
    keyboard.keys[0] = 0x00;
    write_hid_keyboard_report(&keyboard);
}

static void move(s8_t x, s8_t y)
{
    mouse.x = x;
    mouse.y = y;
    write_hid_mouse_report(&mouse);
}

static struct thread service_thread;
static u8_t stack[256];

static void service(void *data)
{
    WASTE(data);
    while (1)
    {
        if (get_hid_led_status())
            GPIOA->BSRR = GPIO_BSRR_BS_0;
        else
            GPIOA->BSRR = GPIO_BSRR_BR_0;

        sleep(100);
    }
}

void pullup_hid(u32_t state)
{
    GPIOB->BSRR = state ? GPIO_BSRR_BS_15 : GPIO_BSRR_BR_15;
}

void main(void)
{
    FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY_2;

    RCC->CFGR = RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL_MUL9 | RCC_CFGR_PPRE1_2 | RCC_CFGR_ADCPRE_DIV6;
    RCC->CR = RCC_CR_HSION | RCC_CR_HSEON;

    wait_status(&RCC->CR, RCC_CR_HSERDY);

    RCC->CR = RCC_CR_HSION | RCC_CR_HSEON | RCC_CR_PLLON;

    wait_status(&RCC->CR, RCC_CR_PLLRDY);

    RCC->CFGR = RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL_MUL16 | RCC_CFGR_PPRE1_2 | RCC_CFGR_ADCPRE_DIV6 | RCC_CFGR_SW_PLL;
    RCC->CSR = RCC_CSR_RMVF | RCC_CSR_LSION;

    RCC->AHBENR = RCC_AHBENR_SRAMEN;
    RCC->APB1ENR = RCC_APB1ENR_USBEN;
    RCC->APB2ENR = RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_USART1EN;

    GPIOA->CRL = GPIO_CRL_CR0_FI | GPIO_CRL_CR1_FI | GPIO_CRL_CR2_FI | GPIO_CRL_CR3_FI | GPIO_CRL_CR4_FI | GPIO_CRL_CR5_FI | GPIO_CRL_CR6_FI | GPIO_CRL_CR7_FI;
    GPIOA->CRH = GPIO_CRH_CR8_FI | GPIO_CRH_CR9_PPA | GPIO_CRH_CR10_FI | GPIO_CRH_CR11_FPPA | GPIO_CRH_CR12_FPPA | GPIO_CRH_CR13_FI | GPIO_CRH_CR14_FI | GPIO_CRH_CR15_FI;

    GPIOB->CRL = GPIO_CRL_CR0_FI | GPIO_CRL_CR1_FI | GPIO_CRL_CR2_FI | GPIO_CRL_CR3_FI | GPIO_CRL_CR4_FI | GPIO_CRL_CR5_FI | GPIO_CRL_CR6_FI | GPIO_CRL_CR7_FI;
    GPIOB->CRH = GPIO_CRH_CR8_FI | GPIO_CRH_CR9_FI | GPIO_CRH_CR10_FI | GPIO_CRH_CR11_FI | GPIO_CRH_CR12_FI | GPIO_CRH_CR13_FI | GPIO_CRH_CR14_FI | GPIO_CRH_CR15_PPO;

    USART1->CR1 = USART_CR1_UE;
    USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_PCE | USART_CR1_M;
    USART1->CR2 = 0;
    USART1->CR3 = 0;
    USART1->BRR = 625;

    start_timers_clock(72000);

    debug("hello\n");

    start_thread(&service_thread, service, 0, stack, sizeof(stack));

    start_hid_service();
    while (1)
    {
        wait_signal(has_hid_connection);
        debug("connected\n");

        while (has_hid_connection())
        {
            press(0x04);
            press(0x05);
            press(0x06);
            sleep(250);
            move(0, -100);
            sleep(250);
            move(-100, 0);
            sleep(250);
            move(0, 100);
            sleep(250);
            move(100, 0);
            sleep(200);
        }

        debug("disconnected\n");
    }
}
