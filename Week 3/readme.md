# Making Embedded Systems - Week 3

### LEDs and button exercises for STM32f407g-disc board

- **stm32f4disc_blink** : all 4 onboard LEDs blink
- **stm32f4disc_blink_noHal** : all 4 onboard LEDs blink, using direct access to registers, no Hal library
- **stm32f4disc_led_button** : user button turns LEDs on and off
- **stm32f4disc_led_button_irq_debounce** : user button triggers interrupt, turns LEDs on and off. Debounce of 50 ms using a timer.