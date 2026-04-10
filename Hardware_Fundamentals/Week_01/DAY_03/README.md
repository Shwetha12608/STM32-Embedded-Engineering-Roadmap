Moving beyond high-level HAL (Hardware Abstraction Layer) libraries to understand how C code directly manipulates physical silicon gates. This project demonstrates Surgical Bit Manipulation on an STM32C031C6 (ARM Cortex-M0+).

**Technical Concepts Implemented**
**1. Memory-Mapped I/O (MMIO)**
Instead of using standard variables, I mapped C pointers to specific hardware addresses (Base Addresses + Offsets) defined in the STM32 Reference Manual.
a.RCC_IOPENR: Enabling the GPIO clock bus.
b.GPIO_MODER: Configuring pin modes.
c.GPIO_ODR: Manipulating output voltage levels.

**2. The "Surgical" Clear-and-Set Dance**
To ensure hardware safety, I avoided direct assignment (=). Direct assignment acts as a "sledgehammer," overwriting unintended bits. Instead, I used:
a.The Hole-Punch (Clear): REG &= ~(mask) — Resets specific bits to 0 using a negative mask.
b.The Commit (Set): REG |= (value) — Sets only the target bits to the desired configuration.

**3. The volatile Keyword**
Used to prevent the C compiler from optimizing away loops and register reads. Since hardware state can change independently of the CPU, volatile ensures the program always fetches the latest truth from the silicon.

**Code Snippet: The Logic**
// Clear bits 11:10 (Hole-punch for Pin 5)
GPIOA_MODER &= ~(0x3 << (5 * 2)); 

// Set bits 11:10 to 01 (Commit Output Mode)
GPIOA_MODER |= (0x1 << (5 * 2));

// Surgical Toggle using XOR
// This flips bit 5 without disturbing any other pins on Port A
GPIOA_ODR ^= (1 << 5);

**Hardware Setup (Wokwi / Physical)**
a.MCU: Nucleo-C031C6 (STM32C0)
b.LED: Connected to PA5 (On-board LD4)
c.Logic: Active High
