#include <stdio.h>
#include <string.h>
#include "morse.h"

// Callback to handle Morse events
void morse_event_handler(morse_event_t event) {
    switch (event) {
        case MORSE_DOT:
            printf(".");
            break;
        case MORSE_DASH:
            printf("-");
            break;
        case MORSE_WSEP:
            printf(" ");  // Separation between letters or words
            break;
        default:
            printf("?");
            break;
    }
}

// Main test function
void run_tests() {
    printf("Test 1: \"HELLO\"\n");
    ascii_to_morse("HELLO", morse_event_handler);
    printf("\nExpected: .... . .-.. .-.. ---\n");

    printf("\nTest 2: \"SOS\"\n");
    ascii_to_morse("SOS", morse_event_handler);
    printf("\nExpected: ... --- ...\n");

    printf("\nTest 3: \"123\"\n");
    ascii_to_morse("123", morse_event_handler);
    printf("\nExpected: .---- ..--- ...--\n");

    printf("\nTest 4: \"Hello, World!\"\n");
    ascii_to_morse("Hello, World!", morse_event_handler);
    printf("\nExpected: .... . .-.. .-.. ---   .-- --- .-. .-.. -.. (and warnings for ',' and '!')\n");

    printf("\nTest 5: Unsupported characters \"@#$%\"\n");
    ascii_to_morse("@#$%", morse_event_handler);
    printf("\nExpected: No Morse code (only warnings)\n");
}

int main() {
    printf("Starting tests for morse.c\n");
    run_tests();
    printf("\nTests completed.\n");
    return 0;
}
