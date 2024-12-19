// app_test.c : Main to test sleep and led
#include <stdio.h>
#include "led.h" // Include function Led ON/OFF
#include "sleep.h" // Include function sleep in milisec
#define FAKE_LED

int main() {
    
    led_init();

    printf('-- led test processing -- \n');
    for (int i = 0; i < 5; i++) {
        led_on();
        sleep_seconds(1);

        led_off();
        sleep_seconds(1);
    }
    
    printf("--- End of LED test ---\n");
    return 0;
}