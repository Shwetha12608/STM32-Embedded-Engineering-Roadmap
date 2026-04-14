This repository contains a comparative study of hardware input handling on the STM32 (Cortex-M0+). The project demonstrates the transition from inefficient "Blocking Polling" to high-performance "Interrupt-Driven" architectures.

**Features**
1. Direct Register Access: No HAL or Standard Peripheral Libraries; direct manipulation of RCC, GPIO, and EXTI registers.

2. Concurrency Simulation: Running a background task (LED Heartbeat) while monitoring user input.

3. Low-Level Bitmasking: Efficient use of bitwise operators to configure hardware parameters.

**Concepts Explored**
1. The Polling Limitation (The "Trap")
- Initially, the system used a while(1) loop to check the button status.
- The Issue: Using delay() for the LED creates a "blocking" state. If the button is pressed while the CPU is inside the delay loop, the press is ignored.
- Outcome: High input latency and poor user experience.

2. External Interrupts (EXTI): To solve the latency issue, I implemented External Interrupts.

- Mechanism: The NVIC (Nested Vectored Interrupt Controller) monitors the pin.
- Trigger: Configured for a Rising Edge (Active High logic).
- Outcome: Zero CPU overhead. The LED blinks independently, and the button response is instantaneous because it triggers a hardware interrupt.
