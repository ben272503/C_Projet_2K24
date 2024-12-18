#ifndef MORSE_H
#define MORSE_H

typedef enum {
    MORSE_DOT,    // short signal
    MORSE_DASH,   // long signal
    MORSE_WSEP,   // letter separator
    MORSE_LSEP    // words separator
} morse_event_t;

//   Morse callback
typedef void (*morse_callback_t)(morse_event_t event);

// Conversion ASCII → Morse
void ascii_to_morse(const char* text, morse_callback_t callback);

#endif // MORSE_H