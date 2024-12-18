#include "morse.h"
#include <string.h>
#include <ctype.h>

typedef enum {
    MORSE_DOT,    // Point
    MORSE_DASH,   // line
    MORSE_WSEP,   // letter separator
    MORSE_LSEP    // word separator
} morse_event_t;

static const char* morse_dict[128] = {
    ['A'] = ".-",   ['B'] = "-...", ['C'] = "-.-.", ['D'] = "-..",
    ['E'] = ".",    ['F'] = "..-.", ['G'] = "--.",  ['H'] = "....",
    ['I'] = "..",   ['J'] = ".---", ['K'] = "-.-",  ['L'] = ".-..",
    ['M'] = "--",   ['N'] = "-.",   ['O'] = "---",  ['P'] = ".--.",
    ['Q'] = "--.-", ['R'] = ".-.",  ['S'] = "...",  ['T'] = "-",
    ['U'] = "..-",  ['V'] = "...-", ['W'] = ".--",  ['X'] = "-..-",
    ['Y'] = "-.--", ['Z'] = "--..",
    ['1'] = ".----",['2'] = "..---",['3'] = "...--",['4'] = "....-",
    ['5'] = ".....",['6'] = "-....",['7'] = "--...",['8'] = "---..",
    ['9'] = "----.",['0'] = "-----"
};

void ascii_to_morse(const char* text, morse_callback_t callback) {
    size_t len = strlen(text);
    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char)toupper((unsigned char)text[i]);
        
        // if its a space, put a word separator
        if (c == ' ') {
            callback(MORSE_LSEP);
            continue;
        }

        const char* morse = morse_dict[c];
        if (morse) {
            // creating the morse code for the word
            for (size_t j = 0; j < strlen(morse); j++) {
                if (morse[j] == '.') {
                    callback(MORSE_DOT);
                } else if (morse[j] == '-') {
                    callback(MORSE_DASH);
                }
            }
            if (i + 1 < len) {
                if (text[i+1] != ' ' && text[i+1] != '\0') {
                    callback(MORSE_WSEP);
                }
            }
        }
    }
}