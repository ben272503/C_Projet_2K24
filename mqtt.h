#ifndef MQTT_H
#define MQTT_H

#include "morse.h"

// Function to subscribe to an MQTT topic
void mqtt_subscribe(const char* broker, const char* topic, morse_callback_t callback);

#endif
