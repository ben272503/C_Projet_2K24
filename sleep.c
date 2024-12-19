#include "sleep.h"
#include <time.h>

void sleep_ms(int ms) {
    struct timespec req = {0, ms * 1000000};
    nanosleep(&req, NULL);
}

void sleep_seconds(int seconds) {
    sleep_ms(seconds * 1000); // Convert to milliseconds
}
