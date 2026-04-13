**External Interrupts (EXTI)**

Concept: Moving from "Software Checking" to "Hardware Signaling."
1. Mechanism: Instead of the CPU checking the button (Polling), the EXTI Controller monitors the voltage on the physical pin.

2. The Trigger: I configured the hardware to detect a Rising Edge (the exact moment the button is pressed and the signal jumps from 0V to 3.3V).

3. The Event: The moment the edge is detected, the EXTI controller sends a high-priority "Stop" signal to the CPU, forcing it to execute the button logic immediately.

4. Zero CPU Overhead: The CPU does not spend a single clock cycle looking at the button. It can be 100% busy with complex math or 100% asleep in Low-Power Mode.

5. Instant Latency: Response time is measured in nanoseconds, not milliseconds.

6. Hardware Debouncing: Allows for more advanced handling of physical button "noise" (bouncing) using hardware timers.

**The "Bare-Metal" Workflow I Followed:**

1.SYSCFG Clock: Enabled the System Configuration clock to map PC13 to the EXTI line.

2.Edge Trigger: Programmed the RTSR (Rising Trigger Selection Register) to catch the "Press."

3.Interrupt Mask: Unmasked the interrupt in the IMR (Interrupt Mask Register) to allow the signal through.

4.NVIC Enable: Specifically enabled the EXTI4_15_IRQn line in the Nested Vectored Interrupt Controller.

**Key Takeaway:**

EXTI turns a "dumb" button into a "smart" peripheral that can wake up the entire system. This is critical for Battery-Operated Devices where every millisecond of CPU activity costs power.
