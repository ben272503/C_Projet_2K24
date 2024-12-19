// app_test.c : Main to test sleep and LED
#include <stdio.h>
#include "led.h" // Include functions for LED ON/OFF
#include "sleep.h" // Include functions for sleep in milliseconds
#define FAKE_LED

int main() {
    led_init();

    printf("-- LED test processing -- \n");
    for (int i = 0; i < 5; i++) {
        led_on();
        sleep_seconds(1);

        led_off();
        sleep_seconds(1);
    }

    printf("--- End of LED test ---\n");
    return 0;
}
