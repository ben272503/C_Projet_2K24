#include "morse.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Morse Dictionary
static const char* morse_dict[128] = {
    ['A'] = ".-", ['B'] = "-...", ['C'] = "-.-.", ['D'] = "-..",
    ['E'] = ".", ['F'] = "..-.", ['G'] = "--.", ['H'] = "....",
    ['I'] = "..", ['J'] = ".---", ['K'] = "-.-", ['L'] = ".-..",
    ['M'] = "--", ['N'] = "-.", ['O'] = "---", ['P'] = ".--.",
    ['Q'] = "--.-", ['R'] = ".-.", ['S'] = "...", ['T'] = "-",
    ['U'] = "..-", ['V'] = "...-", ['W'] = ".--", ['X'] = "-..-",
    ['Y'] = "-.--", ['Z'] = "--..",
    
    ['1'] = ".----", ['2'] = "..---", ['3'] = "...--", ['4'] = "....-",
    ['5'] = ".....", ['6'] = "-....", ['7'] = "--...", ['8'] = "---..",
    ['9'] = "----.", ['0'] = "-----", [' '] = " "
};

void ascii_to_morse(const char* text, morse_callback_t callback) {
    for (size_t i = 0; i < strlen(text); i++) {
        char c = toupper(text[i]);
        if (c < 128 && morse_dict[(unsigned char)c] != NULL) {
            const char* morse = morse_dict[(unsigned char)c];
            for (size_t j = 0; j < strlen(morse); j++) {
                if (morse[j] == '.') {
                    callback((morse_event_t)MORSE_DOT);
                } else if (morse[j] == '-') {
                    callback((morse_event_t)MORSE_DASH);
                }
            }
            callback((morse_event_t)MORSE_WSEP);  // Separation between letters
        } else {
            fprintf(stderr, "Warning: unsupported character '%c'\n", text[i]);
        }
    }
}
