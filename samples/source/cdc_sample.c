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
#include <threads.h>
#include <debug.h>
#include <tools.h>
#include <stm32/flash.h>
#include <cdc.h>

void debug_put(void *data, char value)
{
    while (~USART1->SR & USART_SR_TXE)
        continue;

    USART1->DR = value;
}

struct stream debug_stream = {debug_put, 0};

static u8_t buffer[1024];
static struct thread service_thread;
static u8_t stack[256];

static void service(void *data)
{
    WASTE(data);
    while (1)
    {
        wait_signal(has_cdc_line_coding);
        const struct line_coding *coding = get_cdc_line_coding();
        debug("baudrate: %d, data %d, parity %d, stop %d\n", coding->baud_rate, coding->data_bits, coding->parity_type, coding->stop_bits);
    }
}

void pullup_cdc(u32_t state)
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

    RCC->AHBENR = RCC_AHBENR_FLITFEN | RCC_AHBENR_SRAMEN;
    RCC->APB1ENR = RCC_APB1ENR_USBEN;
    RCC->APB2ENR = RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_USART1EN;

    GPIOA->CRL =
            GPIO_CRx_FLOATING_INPUT(0) | // SUP_LEVEL
            GPIO_CRx_FLOATING_INPUT(1) | // SUP_CHARGE
            GPIO_CRx_FLOATING_INPUT(2) | // GPS_RXD0
            GPIO_CRx_FLOATING_INPUT(3) | // GPS_TXD0
            GPIO_CRx_FLOATING_INPUT(4) | // SUP_LOCK
            GPIO_CRx_FLOATING_INPUT(5) | // GPS_GPIO8 ?
            GPIO_CRx_FLOATING_INPUT(6) | // GPS_GPIO2 ?
            GPIO_CRx_FLOATING_INPUT(7);  // GPS_GPIO3 ?
    GPIOA->CRH =
            GPIO_CRx_FLOATING_INPUT(0) | // NC
            GPIO_CRx_ALTERNATE_OUTPUT_50MHz(1) | // SYS_TXD
            GPIO_CRx_FLOATING_INPUT(2) | // SYS_RXD
            GPIO_CRx_ALTERNATE_OUTPUT_50MHz(3) | // USB_DATA- ?
            GPIO_CRx_ALTERNATE_OUTPUT_50MHz(4) | // USB_DATA+ ?
            GPIO_CRx_FLOATING_INPUT(5) | // NC
            GPIO_CRx_FLOATING_INPUT(6) | // NC
            GPIO_CRx_FLOATING_INPUT(7); // NC

    GPIOB->CRL =
            GPIO_CRx_FLOATING_INPUT(0) | // GPS_PPS ?
            GPIO_CRx_FLOATING_INPUT(1) | // GPS_STANDBY ?
            GPIO_CRx_FLOATING_INPUT(2) | // SYS_BOOT1
            GPIO_CRx_FLOATING_INPUT(3) | // LCD_CLOCK
            GPIO_CRx_FLOATING_INPUT(4) | // LCD_RESET
            GPIO_CRx_FLOATING_INPUT(5) | // LCD_DATA
            GPIO_CRx_FLOATING_INPUT(6) | // LCD_SELECT
            GPIO_CRx_FLOATING_INPUT(7);  // TMP_SUPPLY
    GPIOB->CRH =
            GPIO_CRx_FLOATING_INPUT(0) | // CNT_CADENCE
            GPIO_CRx_FLOATING_INPUT(1) | // CNT_SPEED
            GPIO_CRx_FLOATING_INPUT(2) | // GPS_RXD1
            GPIO_CRx_FLOATING_INPUT(3) | // GPS_TXD1
            GPIO_CRx_FLOATING_INPUT(4) | // GPS_CLOCK
            GPIO_CRx_FLOATING_INPUT(5) | // GPS_STATUS
            GPIO_CRx_FLOATING_INPUT(6) | // USB_PRESENT
            GPIO_CRx_OUTPUT_50MHz(7); // USB_PULLUP

    USART1->CR1 = USART_CR1_UE;
    USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_PCE | USART_CR1_M;
    USART1->CR2 = 0;
    USART1->CR3 = 0;
    USART1->BRR = 625;

    debug("hello\n");

    start_thread(&service_thread, service, 0, stack, sizeof(stack));

    start_cdc_service();
    set_cdc_timeout(10);
    while (1)
    {
        wait_signal(has_cdc_connection);
        debug("connected\n");
        while (has_cdc_connection())
        {
            const u32_t count = read_cdc_data(buffer, sizeof(buffer));
            if (count)
            {
                write_cdc_data(buffer, count);
                debug("%m\n", buffer, count);
            }
        }

        debug("disconnected\n");
    }
}
