#ifndef MORSE_H
#define MORSE_Hs

// Déclaration de l'énumération
typedef enum {
    MORSE_DOT,
    MORSE_DASH,
    MORSE_WSEP
} morse_event_t;

// Prototypes
typedef void (*morse_callback_t)(morse_event_t event);
void ascii_to_morse(const char* text, morse_callback_t callback);

#endif // MORSE_H
