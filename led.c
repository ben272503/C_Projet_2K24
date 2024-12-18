/*led_new(const char* name) : led_t*
▶ led_light_short(led_t)
▶ led_light_long(led_t)*/

#include <stdio.h>
#include <stdlib.h>// for system()
#include "led.h"
#include "sleep.h"

#ifdef FAKE_LED
// Simulation ON/OFF in file
// We don't take care of timing because we can't see it in the file. (choice made)
//we could put the same system file than the led in the raspberry but we didnt had time to implement it

void led_on() {
    FILE *file = fopen("led_.txt", "w");
    fprintf(file, "1");
    fclose(file);
}


void led_off() {
    FILE *file = fopen("led_.txt", "w");
    fprintf(file, "0");
    fclose(file);
}

// Simulation init LED
void led_init() {
    printf("Simulation : LED init (FAKE_LED ON)\n");
}

#else

// /sysconfig/atc to writte in the led folder 'brightness'
// because the GPIO is already mapped by linux and can't be used exept if we erase the config

void led_light_short() {
    system("echo 1 > /sys/class/leds/led0/brightness");
    sleep_ms(200);  // Point (caracter)
    system("echo 0 > /sys/class/leds/led0/brightness");
    sleep_ms(200);  // Pause after signal
}

void led_light_long() {
    system("echo 1 > /sys/class/leds/led0/brightness");
    sleep_ms(600);  // Line (caracter)
    system("echo 0 > /sys/class/leds/led0/brightness");
    sleep_ms(200);  // Pause after signal
}

void led_pause_between_letters() {
    sleep_ms(400);  // small Pause
}

void led_pause_between_words() {
    sleep_ms(1400); // long Pause
}
#endif