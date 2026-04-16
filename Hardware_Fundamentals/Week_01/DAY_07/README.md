This documents my deep-dive into Universal Asynchronous Receiver-Transmitter (UART) communication on the STM32 (Cortex-M0+). It transitions from basic character transmission to handling real-world communication challenges like clock drift, noise, and CPU optimization.

**Technical Concepts Implemented**

**1. Bare-Metal Register Configuration**
Instead of using high-level libraries (HAL), I implemented the driver by directly manipulating the memory-mapped registers.

- Clock Management: Enabling RCC_IOPENR and RCC_APBENR2 to power the GPIO and USART peripherals.

- Pin Multiplexing: Configuring GPIOA_MODER for Alternate Function (AF) mode using non-destructive bitmasking.

- Baud Rate Calculation: Manual calculation of the USART_BRR (Baud Rate Register) based on a 16MHz internal clock to achieve 115200 bps.

**2. The Data Frame & Synchronization**: 
I mastered the "Asynchronous" nature of UART, ensuring both ends of the communication agree on:

- Start/Stop Bits: Providing the timing boundaries for the 8-bit data payload.

- Oversampling: Understanding how the hardware takes 16 samples per bit to ensure data integrity against voltage fluctuations.

**3. Transmission Logic: The "TXE" Protocol**: 
I implemented a robust UART_Write function that respects hardware speed.

Polling the TXE Flag: Checking the USART_ISR register to ensure the Transmit Data Register is empty before loading new data. This prevents data overwriting and corruption.

**4. Advanced Reliability & Error Handling:**
To make the system "industry-ready," I explored how to handle communication failures:

- Error Detection: Monitoring flags like ORE (Overrun), FE (Framing Error), and NE (Noise Error).

- Hardware Flow Control: Using RTS/CTS pins to prevent buffer overflows during high-speed data transfers.

- Clock Drift Awareness: Analyzing why 2% clock inaccuracies can lead to framing errors in serial communication.
