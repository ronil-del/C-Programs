#include <stdio.h>
#include <string.h>

int main(void) {
    char input[100]; // taulukko käyttäjän syötteen tallentamiseen
    
    while (1) { // Jatketaa kunnes käyttäjä syöttää lopeta
        printf("Syötä sana tai kirjoita 'lopeta' päättääksesi ohjelman:\n");
        fgets(input, sizeof(input), stdin); //  käyttäjän syöte
        input[strcspn(input, "\n")] = '\0'; //  rivinvaihto pois

        int pituus = strlen(input); // syötteen pituus
        printf("Syötetyn sanan pituus: %d\n", pituus);

        if (pituus == 0) { // jos pituus on nolla
            printf("Et syöttänyt mitään!\n");
            continue; //  looppi alusta
        }
        
        if (strcmp(input, "lopeta") == 0) break; //  syöte on "lopeta", päätetään ohjelma
    }
    
    return 0;
}