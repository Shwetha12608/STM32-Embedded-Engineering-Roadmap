while (1) {
        // --- STEP A: BLINK THE LED ---
        GPIOA_ODR ^= (1 << 5); 
        
        // --- STEP B: THE "TRAP" ---
        // The CPU stays here for ~500ms. 
        // It CANNOT see the button while inside this delay!
        delay(1000000); 

        // --- STEP C: CHECK THE BUTTON ---
        // This only happens once every half-second.
        if (!(GPIOC_IDR & (1 << 13))) {
            printf("Button press detected! (Finally...)\n");
        }
