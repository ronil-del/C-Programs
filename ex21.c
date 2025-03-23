#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// funktio laskee NMEAviestin tarkistusnumeron 
unsigned char calculate_checksum(const char *line) {
    unsigned char checksum = 0;

    // etsitään '$'-merkin jälkeiset merkit ennen '*'
    for (int i = 1; line[i] != '*'; i++) {
        checksum ^= line[i]; // XOR-operaatio kaikille merkeille '$' ja '*' väliin
    }

    return checksum; // palautetaan laskettu tarkistusnumero
}

int main(void) {
    char filename[100]; // tiedostonimi
    FILE *file;
    char line[256]; // Rivi johon luetaan tiedostosta

    // Kysyään käyttäjältä tiedoston nimeä
    printf("Enter the file name: ");
    if (scanf("%s", filename) != 1) {
        fprintf(stderr, "Error reading the filename.\n");
        return 1;
    }

    // avaa tiedoston lukemista varten
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening the file %s.\n", filename);
        return 1;
    }

    // luetaaa tiedostoa rivi kerrallaan
    while (fgets(line, sizeof(line), file)) {
        // tarkistus että rivi alkaa '$' ja sisältää '*'
        if (line[0] == '$' && strchr(line, '*') != NULL) {
            // etsitää '*'-merkkiä rivistä
            char *asterisk_pos = strchr(line, '*');
            if (asterisk_pos != NULL) {
                // lasketaa tarkistusnumero rivistä
                unsigned char calculated_checksum = calculate_checksum(line);
                // muutetaa rivin tarkistusnumero (hex-merkki) kokonaisluvuksi
                unsigned int given_checksum;
                sscanf(asterisk_pos + 1, "%2X", &given_checksum); //asteriskin jälkeinen osa on tarkistusnumero

                // Tarkistetaan onks lasketun ja annetun tarkistusnumeron arvot sama
                if (calculated_checksum == given_checksum) {
                    printf("[ OK ] %s", line); // tarkistusnumero täsmää tulostetaan OK
                } else {
                    printf("[FAIL] %s", line); // tulostetaan FAIL
                }
            }
        }
    }

    // suljetaan tiedosto
    fclose(file);

    return 0;
}
