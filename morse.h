#ifndef MORSE_H
#define MORSE_H

typedef enum {
    MORSE_DOT,    // Signal court
    MORSE_DASH,   // Signal long
    MORSE_WSEP,   // Séparateur entre lettres
    MORSE_LSEP    // Séparateur entre mots
} morse_event_t;

// Définition du type callback pour Morse
typedef void (*morse_callback_t)(morse_event_t event);

// Fonction de conversion ASCII → Morse
void ascii_to_morse(const char* text, morse_callback_t callback);

#endif // MORSE_H