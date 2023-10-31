/**
 * Blink External LED
 * Jon Durrant - 2023
 */

#ifndef BLINK_H
#define BLINKH


#ifndef LED_PAD
#define LED_PAD 15
#endif

/***
 * Function to setup GPIO for Blink PICO inbuild LED
 */
void blinkSetup();


/***
 * Function to Blink the LED
 * @param delay: ms delay to hold led on, and off before returning
 */
void blink(int delay);

#endif
