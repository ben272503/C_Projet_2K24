#include "mqtt.c"

int main() {
    const char* broker = "localhost"; // Adresse du broker MQTT
    int port = 1883;                  // Port par défaut de Mosquitto
    printf("Démarrage du programme MQTT -> Morse...\n");
    mqtt_start(broker, port);
    return 0;
}