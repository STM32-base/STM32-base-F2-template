#include "STM32F2xx.h"

// Quick and dirty delay
static void delay (unsigned int time) {
    for (unsigned int i = 0; i < time; i++)
        for (volatile unsigned int j = 0; j < 2000; j++);
}

int main (void) {
    // Turn on the GPIOC peripheral
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // Put the pin in general purpose output mode
    GPIOC->MODER |= GPIO_MODER_MODE13_0;

    while (1) {
        // Reset the bit for port C13
        GPIOC->BSRR = GPIO_BSRR_BR13;

        delay(500);

        // Set the bit for port C13
        GPIOC->BSRR = GPIO_BSRR_BS13;

        delay(500);
    }
}
