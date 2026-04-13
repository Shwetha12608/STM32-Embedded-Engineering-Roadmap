// 1. Enable Clock for GPIOA and GPIOC
    RCC_IOPENR |= (1 << 0) | (1 << 2);

    // 2. Configure PA5 as Output (LED)
    GPIOA_MODER &= ~(0x3 << (5 * 2));
    GPIOA_MODER |=  (0x1 << (5 * 2));

    // 3. Configure PC13 as Input with Pull-up (Button)
    // Most Nucleo buttons are "Active Low" (0 when pressed)
    GPIOC_PUPDR |= (0x1 << (13 * 2)); 
