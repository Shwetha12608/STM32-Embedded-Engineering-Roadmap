**Asynchronous GPIO Task Manager**

The LED is blinking without the button being pressed is exactly what demonstrate THE Polling concept.

In the code, the LED blink is "Automatic" (it happens inside the while(1) loop no matter what). The button check only happens after the blink delay is over.

The "Polling" Logic is as follows:
1. Blink: The CPU toggles the LED.

2. Wait: The CPU gets stuck in the delay() loop for 500ms.

3. Check: Only now does the CPU look at the button.

4. Repeat: It goes back to Step 1 and blinks again.

**This is why Polling is bad for real-time systems: The LED doesn't care about the button; it just follows the loop.**

Demo link:https://wokwi.com/projects/461195193249408001
