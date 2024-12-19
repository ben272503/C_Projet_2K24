#include <stdio.h>
#include <string.h>
#include <MQTTClient.h>
#include "mqtt.h"

void on_message(MQTTClient_message* message, morse_callback_t callback) {
    printf("MQTT Message received: %.*s\n", message->payloadlen, (char*)message->payload);
    ascii_to_morse((char*)message->payload, callback);
    MQTTClient_freeMessage(&message);
}

void mqtt_subscribe(const char* broker, const char* topic, morse_callback_t callback) {
    MQTTClient client;
    MQTTClient_connectOptions opts = MQTTClient_connectOptions_initializer;

    MQTTClient_create(&client, broker, "RPiMorseClient", MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTClient_connect(client, &opts);
    MQTTClient_subscribe(client, topic, 1);

    while (1) {
        MQTTClient_message* msg;
        MQTTClient_deliveryToken token;
        MQTTClient_receive(client, &msg, &token, 1000);
        if (msg) on_message(msg, callback);
    }
}
