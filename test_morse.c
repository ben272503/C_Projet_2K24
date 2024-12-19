#include <stdio.h>
#include <string.h>
#include "morse.h"

// Callback pour gérer les événements Morse
void morse_event_handler(morse_event_t event) {
    switch (event) {
        case MORSE_DOT:
            printf(".");
            break;
        case MORSE_DASH:
            printf("-");
            break;
        case MORSE_WSEP:
            printf(" ");  // Séparation entre lettres ou mots
            break;
        default:
            printf("?");
            break;
    }
}

// Fonction principale de test
void run_tests() {
    printf("Test 1 : \"HELLO\"\n");
    ascii_to_morse("HELLO", morse_event_handler);
    printf("\nAttendu : .... . .-.. .-.. ---\n");

    printf("\nTest 2 : \"SOS\"\n");
    ascii_to_morse("SOS", morse_event_handler);
    printf("\nAttendu : ... --- ...\n");

    printf("\nTest 3 : \"123\"\n");
    ascii_to_morse("123", morse_event_handler);
    printf("\nAttendu : .---- ..--- ...--\n");

    printf("\nTest 4 : \"Hello, World!\"\n");
    ascii_to_morse("Hello, World!", morse_event_handler);
    printf("\nAttendu : .... . .-.. .-.. ---   .-- --- .-. .-.. -.. (et avertissements pour ',' et '!')\n");

    printf("\nTest 5 : Caractères non pris en charge \"@#$%\"\n");
    ascii_to_morse("@#$%", morse_event_handler);
    printf("\nAttendu : Aucun code Morse (uniquement avertissements)\n");
}

int main() {
    printf("Démarrage des tests pour morse.c\n");
    run_tests();
    printf("\nTests terminés.\n");
    return 0;
}
