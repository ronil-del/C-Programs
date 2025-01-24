#include <stdio.h>

int main(void) {
    int opiskelijoiden_maara;

    // Pyydetään käyttäjältä opiskelijoiden määrä
    printf("Kuinka monta opiskelijaa: ");
    scanf("%d", &opiskelijoiden_maara);

    int arvosanat[opiskelijoiden_maara];

    // Alustetaan arvosanat -1:ksi
    for (int i = 0; i < opiskelijoiden_maara; i++) {
        arvosanat[i] = -1;
    }

    int opiskelijan_numero, arvosana;

    // Jatketaan kunnes käyttäjä lopettaa
    while (1) {
        printf("Anna opiskelijan numero (1-%d) tai 0 lopettaaksesi: ", opiskelijoiden_maara);
        scanf("%d", &opiskelijan_numero);

        if (opiskelijan_numero == 0) {
            break; // Poistutaan
        }

        if (opiskelijan_numero < 1 || opiskelijan_numero > opiskelijoiden_maara) {
            printf("Virheellinen opiskelijan numero!\n");
            continue; // Siirrytään takaisin  alkuun
        }

        // Arvosanan syöttösilmukka
        while (1) {
            printf("Anna arvosana (0 - 5) opiskelijalle %d tai -1 peruuttaaksesi: ", opiskelijan_numero);
            scanf("%d", &arvosana);

            if (arvosana == -1) {
                break; // pois  arvosanan kysyntäsilmukasta
            }

            if (arvosana >= 0 && arvosana <= 5) {
                arvosanat[opiskelijan_numero - 1] = arvosana;
                break; // Arvosana tallennettu poistutaan
            } else {
                printf("Virheellinen arvosana! Syötä arvosana väliltä 0-5.\n");
            }
        }
    }

    // opiskelijoiden tiedot lista
    printf("\nOpiskelija\tArvosana\n");
    printf("------------------------\n");

    for (int i = 0; i < opiskelijoiden_maara; i++) {
        if (arvosanat[i] == -1) {
            printf("%d\tEi arvosanaa\n", i + 1);
        } else {
            printf("%d\t%d\n", i + 1, arvosanat[i]);
        }
    }
    return 0;
}