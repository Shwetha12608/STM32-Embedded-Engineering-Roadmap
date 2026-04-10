Overview
Bypassing high-level libraries (HAL) to talk directly to the STM32C031 hardware. This project focuses on Surgical Bit Manipulation—the art of modifying hardware registers without disturbing neighboring peripherals.

In production firmware, a "Sledge hammer" approach (REG = Value) is dangerous. I used the Read-Modify-Write (RMW) pattern:

**1.Clear (&= ~)**: Punching a hole in specific bits (Reset).
**2.Set (|=)**: Stamping the new configuration (Commit).
**3.Toggle (^=)**: Flipped the LED state using XOR logic for maximum efficiency.

**Challenges & Solutions**
The Problem: The compiler was "too smart" and deleted my delay loop because it looked empty, making the LED blink invisible.

The Solution:
1.volatile keyword: Told the compiler: "Don't touch this variable; the hardware needs it."
2.__asm("nop"): Forced the CPU to physically wait for one clock cycle per loop.

**Technical Specs**
MCU: STM32C031C6 (ARM Cortex-M0+)
Interface: Direct Memory-Mapped I/O (MMIO)
Registers: RCC_IOPENR, GPIOx_MODER, GPIOx_ODR
Efficiency: Zero library overhead. Tiny memory footprint.

wowki project link: )[https://wokwi.com/projects/460920059684641793](url)
