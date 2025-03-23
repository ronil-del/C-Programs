#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

static const char CHARSET[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "!@#$%^&*()-_=+[]{};:,.<>/?"
    "€§";

// Funktio salasanan luomiseen
bool generate_password(char *output, int max_size, const char *input_word) {
    //  tarvittava pituus käyttäjän syötteelle
    int input_len = strlen(input_word);
    int required_size = (input_len * 2) + 1;

    // että tilaa on riittävästi
    if (required_size + 1 > max_size) {
        return false;
    }

    // luodaa uus salasana: parilliset indeksit satunnaisilla merkeillä, parittomat käyttäjän sanalla
    for (int i = 0; i < required_size; i++) {
        if (i % 2 == 0) {
            int random_index = rand() % (sizeof(CHARSET) - 1);
            output[i] = CHARSET[random_index];
        } else {
            output[i] = input_word[i / 2];
        }
    }
    output[required_size] = '\0'; // lisätään null-terminaattori loppuun
    return true;
}

int main(void) {
    // asetetaan satunnaislukugeneraattori
    srand(time(NULL));

    char input[100];
    char generated_password[201];

    while (true) {
        printf("Enter a word to generate a password ('stop' to quit): \n");
        if (scanf("%s", input) != 1) {
            fprintf(stderr, "Failed to read input.\n");
            return 1;
        }

        // Lopetetaan, käyttäjä syöttää 'stop'
        if (strcmp(input, "stop") == 0) {
            printf("Exiting the program...\n");
            break;
        }

        //  luodaa salasana ja tulostetaan se
        if (!generate_password(generated_password, sizeof(generated_password), input)) {
            printf("Password generation failed, not enough space.\n");
        } else {
            printf("Your generated password is: %s\n", generated_password);
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

static const char CHARSET[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "!@#$%^&*()-_=+[]{};:,.<>/?"
    "€§";

// Funktio salasanan luomiseen
bool generate_password(char *output, int max_size, const char *input_word) {
    //  tarvittava pituus käyttäjän syötteelle
    int input_len = strlen(input_word);
    int required_size = (input_len * 2) + 1;

    // että tilaa on riittävästi
    if (required_size + 1 > max_size) {
        return false;
    }

    // luodaa uus salasana: parilliset indeksit satunnaisilla merkeillä, parittomat käyttäjän sanalla
    for (int i = 0; i < required_size; i++) {
        if (i % 2 == 0) {
            int random_index = rand() % (sizeof(CHARSET) - 1);
            output[i] = CHARSET[random_index];
        } else {
            output[i] = input_word[i / 2];
        }
    }
    output[required_size] = '\0'; // lisätään null-terminaattori loppuun
    return true;
}

int main(void) {
    // asetetaan satunnaislukugeneraattori
    srand(time(NULL));

    char input[100];
    char generated_password[201];

    while (true) {
        printf("Enter a word to generate a password ('stop' to quit): \n");
        if (scanf("%s", input) != 1) {
            fprintf(stderr, "Failed to read input.\n");
            return 1;
        }

        // Lopetetaan, käyttäjä syöttää 'stop'
        if (strcmp(input, "stop") == 0) {
            printf("Exiting the program...\n");
            break;
        }

        //  luodaa salasana ja tulostetaan se
        if (!generate_password(generated_password, sizeof(generated_password), input)) {
            printf("Password generation failed, not enough space.\n");
        } else {
            printf("Your generated password is: %s\n", generated_password);
        }
    }

    return 0;
}
