// main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "debug.h"

int main(void) {
    int user_debug_level;

    // Kysytään käyttäjältä debug 
    printf("Enter the debug level (0-4): ");
    if (scanf("%d", &user_debug_level) != 1 || user_debug_level < 0 || user_debug_level > 4) {
        fprintf(stderr, "Invalid debug level. Please enter a number between 0 and 4.\n");
        return 1;
    }

    // Asetetaan debug käyttämällä set_debug_level -funktiota
    set_debug_level(user_debug_level);

    // Alustetaan satunnainen lukugeneraattori
    srand(time(NULL));

    // Tulostetaan viisi viestiä satunnaisilla debug välillä 0-4
    for (int i = 1; i <= 5; i++) {
        int random_level = rand() % 5;  // Generoidaan satunnainen debug (0-4)
        dprintf(random_level, "Message %d with random debug level: %d\n", i, random_level);
    }

    return 0;
}
