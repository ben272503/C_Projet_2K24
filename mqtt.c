#include "mqtt.h"
#include "morse.h"
#include "led.h"
#include <mosquitto.h>
#include <stdio.h>
#include <stdlib.h>

void morse_callback(morse_event_t event) {
    switch (event) {
        case MORSE_DOT: led_light_short(); break;
        case MORSE_DASH: led_light_long(); break;
        case MORSE_WSEP: led_pause_between_letters(); break;
        case MORSE_LSEP: led_pause_between_words(); break;
    }
}

void on_message(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *msg) {
    printf("Message reçu : %s\n", (char *)msg->payload);
    ascii_to_morse((char *)msg->payload, morse_callback);
}

void mqtt_start(const char* broker, int port) {
    struct mosquitto *mosq = NULL;
    mosquitto_lib_init();

    mosq = mosquitto_new(NULL, true, NULL);
    if (mosquitto_connect(mosq, broker, port, 60)) {
        fprintf(stderr, "Connexion MQTT échouée !\n");
        exit(1);
    }

    mosquitto_message_callback_set(mosq, on_message);
    mosquitto_subscribe(mosq, NULL, "morse/messages", 0);
    mosquitto_loop_forever(mosq, -1, 1);

    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
}