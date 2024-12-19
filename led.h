#ifndef LED_H
#define LED_H

// fake led
void led_init();
void led_on();
void led_off();

// real led
void led_light_short();
void led_light_long();
void led_pause_between_letters();
void led_pause_between_words();

#endif // LED_H
