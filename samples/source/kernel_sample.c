#include <stm32/usart.h>
#include <stm32/gpio.h>
#include <stm32/rcc.h>
#include <threads.h>
#include <timers.h>
#include <debug.h>
#include <tools.h>

void debug_put(void *data, char value)
{
    while (~USART1->SR & USART_SR_TXE)
        continue;

    USART1->DR = value;
}

struct stream debug_stream = {debug_put, 0};

struct data
{
    const char *name;
    u32_t count;
    u32_t interval;
    u32_t pins;
};

static struct thread thread_1;
static u8_t stack_1[256];
static struct data data_1 = {"blink 1", 20, 200, GPIO_ODR_ODR_14};

static struct thread thread_2;
static u8_t stack_2[256];
static struct data data_2 = {"blink 2", 10, 300, GPIO_ODR_ODR_15};

static void blink(struct data *data)
{
    u32_t count = data->count;
    struct timer timer;

    debug("%s: hello\n", data->name);
    start_timer(&timer, data->interval);
    while (count--)
    {
        wait_timer(&timer);
        debug("%s: count {%d}\n", data->name, count);

        GPIOA->ODR ^= data->pins;
    }

    stop_timer(&timer);
    debug("%s: bue\n", data->name);
}

void main(void)
{
    u32_t count = 20;

    RCC->AHBENR = RCC_AHBENR_SRAMEN;
    RCC->APB2ENR = RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN;

    GPIOA->CRL = GPIO_CRL_CR0_FI | GPIO_CRL_CR1_FI | GPIO_CRL_CR2_FI | GPIO_CRL_CR3_FI | GPIO_CRL_CR4_FI | GPIO_CRL_CR5_FI | GPIO_CRL_CR6_FI | GPIO_CRL_CR7_FI;
    GPIOA->CRH = GPIO_CRH_CR8_FI | GPIO_CRH_CR9_PPA | GPIO_CRH_CR10_FI | GPIO_CRH_CR11_FI | GPIO_CRH_CR12_FI | GPIO_CRH_CR13_FI | GPIO_CRH_CR14_PPO | GPIO_CRH_CR15_PPO;

    USART1->CR1 = USART_CR1_UE ;
    USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_PCE | USART_CR1_M;
    USART1->CR2 = 0;
    USART1->CR3 = 0;
    USART1->BRR = 8000000 / 115200 + 1;

    start_timers_clock(8000);

    debug("main: hello\n");

    debug("[%s] [%2s] [%6s] [%*s]\n", "abcd", "abcd", "abcd", 5, "abcd");
    debug("[%d] [%d] [%d] [%4d] [%12d] [%*d]\n", 0, 1, -1, 654321, 654321, 9, 654321);
    debug("[%d] [%d] [%d] [%4d] [%12d] [%*d]\n", 0, 1, -1, -654321, -654321, 9, -654321);
    debug("[%u] [%u] [%u] [%4u] [%12u] [%*u]\n", 0, 1, -1, 654321, 654321, 9, 654321);
    debug("[%x] [%x] [%x] [%4x] [%12x] [%*x]\n", 0, 1, -1, 654321, 654321, 9, 654321);
    debug("[%c] [%3c] [%*c]\n", '.', '.', 9, '.');

    start_thread(&thread_1, (function_t)blink, &data_1, stack_1, sizeof(stack_1));
    start_thread(&thread_2, (function_t)blink, &data_2, stack_2, sizeof(stack_2));

    while (count--)
    {
        sleep(250);
        GPIOA->BSRR = GPIO_BSRR_BS_0;
        debug("main: count {%d}\n", count);
        GPIOA->BSRR = GPIO_BSRR_BR_0;
    }

    debug("main: bue\n");
    sleep(10);
}
