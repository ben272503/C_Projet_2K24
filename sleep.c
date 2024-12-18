#include "sleep.h"
#include <time.h>

void sleep_ms(int ms) {
    struct timespec req = {0, ms * 1000000};
    nanosleep(&req, NULL);
}