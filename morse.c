#include "morse.h"
#include <string.h>

typedef enum {
    MORSE_DOT,
    MORSE_DASH, 
    MORSE_WSEP  // Word Separator
} morse_event_t;

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
    ['9'] = "----.", ['0'] = "-----", [' '] = "..."
};

void ascii_to_morse(const char* text, morse_callback_t callback) {
    for (size_t i = 0; i < strlen(text); i++) {
        const char* morse = morse_dict[(unsigned char)text[i]];
        if (morse) {
            for (size_t j = 0; j < strlen(morse); j++) {
                if (morse[j] == '.') {
                    callback(MORSE_DOT);
                } else if (morse[j] == '-') {
                    callback(MORSE_DASH);
                } 

            }
            callback(MORSE_WSEP);
        }
    }
}
