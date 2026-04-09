**Day 2: The Surgical Tools — Bit Manipulation Mastery**
Today's focus shifted from the "Silicon Map" to the "Surgical Tools." In Embedded Engineering, you rarely overwrite a whole register. Instead, you must modify specific bits with high precision while leaving the rest of the 32-bit register untouched. 
This is the hallmark of professional firmware development.
The Bitwise Toolkit
I mastered the four fundamental operations used to control hardware registers without causing "Destructive Writes."

1. **1.The "Set" Operation (|):** :
Used to turn a feature ON.
Logic: Register |= (1 << n);Why: Using OR with a mask ensures that only the nth bit changes to 1.
All other bits remain exactly as they were (X | 0 = X).

**2. The "Clear" Operation (& ~):**
Used to turn a feature OFF.
Logic: Register &= ~(1 << n);
Why: We create a "shield" (an inverse mask) where only the target bit is 0. Performing an AND forces that bit to 0 while preserving the rest.

**3. The "Toggle" Operation (^):** 
Used to flip a state (e.g., blinking an LED).
Logic: Register ^= (1 << n);
Why: The XOR operator is the most efficient way to flip a bit's state regardless of its current value, often translating to a single assembly instruction.

**4. The "Extraction" Maneuver (& then >>):**
Used to read a specific field of bits.
Logic: value = (Register & (Mask << n)) >> n;
Why: By masking the unwanted bits and shifting the target bits to the 0th position, we can treat a bit-field as a standard integer.

The **"Golden Rule": Clear-before-Set**
The most critical takeaway today was handling multi-bit fields. Many registers (like the MODER register in STM32) use 2 bits to define a single pin's mode.

The Discovery: A simple OR cannot turn a 1 into a 0. If a pin is in "Alternate Function" (10) and I OR it with "Output" (01), the result is "Analog" (11)—an accidental error.
**The Professional Solution:**
Clear: Use a mask to wipe the target bits to 00.
Set: Use an OR to write the new value safely.

Example: Setting Pin 5 to Output (01)
GPIOA->MODER &= ~(3 << (5 * 2)); // Clear bits 10 & 11
GPIOA->MODER |= (1 << (5 * 2));  // Set bit 10

