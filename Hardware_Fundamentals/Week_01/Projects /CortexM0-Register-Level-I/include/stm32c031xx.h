#ifndef STM32C031XX_H
#define STM32C031XX_H

#include <stdint.h>

// --- Base Addresses ---
#define RCC_BASE      0x40021000
#define GPIOA_BASE    0x50000000

// --- Register Macros (Direct Memory Access) ---
// volatile ensures the compiler reads from physical silicon every time
#define RCC_IOPENR    (*((volatile uint32_t *)(RCC_BASE + 0x34))) 
#define GPIOA_MODER   (*((volatile uint32_t *)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR     (*((volatile uint32_t *)(GPIOA_BASE + 0x14)))

#endif
