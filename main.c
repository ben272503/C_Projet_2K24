#include "mqtt.c"
#include <stdio.h>

int main() {
    const char* broker = "localhost"; // mqtt broker
    int port = 1883;                  // mosquitto default port
    printf("Mqtt starting msg -> Morse...\n");
    mqtt_start(broker, port);
    return 0;
}