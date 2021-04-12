#ifndef led_included
#define  led_included




#define LED_RED BIT0        // P1.0
#define LED_GREEN BIT6     // P1.6
#define LEDS (BIT0 | BIT6)

// these are boolean flags
extern unsigned char red_on,green_on,led_changed;


void led_init();/* initialize LEDs */
void led_update();/* update leds */

#endif
