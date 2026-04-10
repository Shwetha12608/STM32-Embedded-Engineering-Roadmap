#include "stm32c031xx.h"

#define LED_PIN 5

// Simple delay using the Assembly NOP (No Operation) instruction
void delay(volatile int count) {
    for(int i = 0; i < count; i++) {
        __asm("nop"); 
    }
}

int main(void) {
    // 1. Enable Clock for GPIOA (Power Up)
    RCC_IOPENR |= (1 << 0);
    
    // 2. Surgical Configuration for PA5
    // Reset bits 11:10 to 00 (Clear)
    GPIOA_MODER &= ~(0x3 << (LED_PIN * 2));
    // Set bits 11:10 to 01 (Set as Output)
    GPIOA_MODER |=  (0x1 << (LED_PIN * 2));
     
    while(1) {
        // 3. Surgical Toggle (XOR)
        // Flips bit 5 without affecting other bits in the register
        GPIOA_ODR ^= (1 << LED_PIN);
        delay(100000);
    }
}
