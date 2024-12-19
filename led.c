#include <fcntl.h>
#include <unistd.h>
#include "led.h"
#include "sleep.h"

#define LED_BRIGHTNESS_PATH "/sys/class/leds/led0/brightness"

static void write_to_file(const char* path, const char* value) {
    int fd = open(path, O_WRONLY);
    if (fd != -1) {
        write(fd, value, 1);
        close(fd);
    } else {
        perror("Error accessing the LED file");
    }
}

void led_init() {
    printf("LED initialized\n");
}

void led_on() {
    write_to_file(LED_BRIGHTNESS_PATH, "1");
}

void led_off() {
    write_to_file(LED_BRIGHTNESS_PATH, "0");
}

void led_light_short() {
    write_to_file(LED_BRIGHTNESS_PATH, "1");
    sleep_ms(200);  // Dot
    write_to_file(LED_BRIGHTNESS_PATH, "0");
    sleep_ms(200);  // Pause after the signal
}

void led_light_long() {
    write_to_file(LED_BRIGHTNESS_PATH, "1");
    sleep_ms(600);  // Dash
    write_to_file(LED_BRIGHTNESS_PATH, "0");
    sleep_ms(200);  // Pause after the signal
}

void led_pause_between_letters() {
    sleep_ms(400);  // Short pause
}

void led_pause_between_words() {
    sleep_ms(1400); // Long pause
}
