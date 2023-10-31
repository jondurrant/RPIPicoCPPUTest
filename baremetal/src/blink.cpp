/**
 * Blink
 * Blink External LED
 * Jon Durrant - 2023
 */

#include "blink.h"
#include "pico/stdlib.h"

/***
 * Function to setup GPIO for Blink PICO inbuild LED
 */
void blinkSetup(){
	const uint LED_PIN = LED_PAD;

	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
}


/***
 * Function to Blink the LED
 * @param delay: ms delay to hold led on, and off before returning
 */
void blink(int delay){
	const uint LED_PIN = LED_PAD;

	gpio_put(LED_PIN, 1);
	sleep_ms(delay);
	gpio_put(LED_PIN, 0);
	sleep_ms(delay);
}
