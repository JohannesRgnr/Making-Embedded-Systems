/**
 * @file main.c
 * @author johannes regnier
 * @brief blinking, no HAL, only registers
 * @version 0.1
 * @date 2023-10-14
 *
 *
 */

#include <stdint.h>

int main(void)
{
    /**
     * Blink onboard LEDs: PD12, PD13, PD14, PD15.
     * No HAL. No Clock config.
     */

    uint32_t *pClkCtrlReg = (uint32_t *)0x40023830;   // Address of the Clock control register (AHB1ENR)
    uint32_t *pPortDModeReg = (uint32_t *)0x40020C00; // Address of the GPIOD mode register
    uint32_t *pPortDOutReg = (uint32_t *)0x40020C14;  // Address of the GPIOD output data register

    /* Enable the clock for GPIOD peripherals in the AHB1ENR */
    *pClkCtrlReg |= (1 << 3); // SET the 3rd bit position

    /* Configure the mode of the IO Pins 12, 13, 14, 15 as output */
    /* CLEAR the bits 24, 25, 26, 27, 28, 29, 30, 31 */
    *pPortDModeReg &= ~(3 << 24); // 3 is b11, changes two bits to 1. With negate, becomes 00.
    *pPortDModeReg &= ~(3 << 26);
    *pPortDModeReg &= ~(3 << 28);
    *pPortDModeReg &= ~(3 << 30);

    /* SET bits 24, 26, 28, 30, for general purpose output mode */
    *pPortDModeReg |= (1 << 24);
    *pPortDModeReg |= (1 << 26);
    *pPortDModeReg |= (1 << 28);
    *pPortDModeReg |= (1 << 30);

    while (1)
    {

        /* SET bits 12, 13, 14, 15 of the output data register to make IO Pins as HIGH --> turns LEDs on */
        *pPortDOutReg |= (1 << 12);
        *pPortDOutReg |= (1 << 13);
        *pPortDOutReg |= (1 << 14);
        *pPortDOutReg |= (1 << 15);

        // delay
        for (uint32_t i = 0; i < 600000; i++);

        /* Turn off LEDs */
        *pPortDOutReg &= ~(1 << 12);
        *pPortDOutReg &= ~(1 << 13);
        *pPortDOutReg &= ~(1 << 14);
        *pPortDOutReg &= ~(1 << 15);

        // delay
        for (uint32_t i = 0; i < 600000; i++);
    }
}
