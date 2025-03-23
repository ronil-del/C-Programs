#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_RIVIT 100   // maxksimi rivimäärä
#define MAX_PITUUS 81   // 80 merkkiä + null

int main(void) {
    char tiedostonimi[100];  //  muistia tiedoston nimelle
    char rivit[MAX_RIVIT][MAX_PITUUS];  //  muistia riveille
    FILE *fp;  // tiedoston osoitin
    int laskuri = 0;  // laskuri rivien määrälle

    // kyysytään käyttäjältä tiedoston nimi
    printf("Anna tiedoston nimi: ");
    if (scanf("%s", tiedostonimi) != 1) {
        fprintf(stderr, "VIRHE: Tiedostonimeä ei voitu lukea!\n");
        return -1;
    }

    // tiedosto lukutilassa
    fp = fopen(tiedostonimi, "r");
    if (fp == NULL) {
        fprintf(stderr, "VIRHE: Tiedostoa %s ei voitu avata!\n", tiedostonimi);
        return -1;
    }

    // Luetaan tiedoston rivit taulukkoon
    while (laskuri < MAX_RIVIT && fgets(rivit[laskuri], MAX_PITUUS, fp) != NULL) {
        size_t pituus = strlen(rivit[laskuri]);
        if (pituus > 0 && rivit[laskuri][pituus - 1] == '\n') {
            rivit[laskuri][pituus - 1] = '\0';  // poistetaan rivinvaihto lopusta
        }
        laskuri++;
    }
    fclose(fp);  // suljetaan tiedosto luennan jälkeen

    // muutetaan kirjaimet isoiksi
    for (int i = 0; i < laskuri; i++) {
        for (int j = 0; rivit[i][j] != '\0'; j++) {
            rivit[i][j] = toupper(rivit[i][j]);
        }
    }

    // Avataan tiedosto kirjoitustilassa
    fp = fopen(tiedostonimi, "w");
    if (fp == NULL) {
        fprintf(stderr, "VIRHE: Tiedostoa %s ei voitu avata kirjoitusta varten!\n", tiedostonimi);
        return -1;
    }

    // muutetut rivit takaisin tiedostoon
    for (int i = 0; i < laskuri; i++) {
        fprintf(fp, "%s\n", rivit[i]);
    }
    fclose(fp);  // suljetaan tiedosto kirjoituksen jälkeen

    printf("Tiedosto %s päivitettiin onnistuneesti.\n", tiedostonimi);
    return 0;
}