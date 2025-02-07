#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Käytetään aikaa satunnaisuuden varmistamiseen

// Etsii ensimmäisen esiintymän listasta
int etsi_eka(const unsigned int *lista, unsigned int etsittava) {
    for (int indeksi = 0; indeksi < 20; indeksi++) {
        if (lista[indeksi] == etsittava) {
            return indeksi; // Palautetaan indeksi, jos löytyy
        }
    }
    return -1; // Jos ei löydy, palautetaan -1
}

int main(void) {
    srand(time(0)); // Alustetaan satunnaislukugeneraattori
    int numerot[20]; // Lista, johon tallennetaan 20 numeroa
    
    for (int i = 0; i < 19; i++) {
        numerot[i] = (rand() % 20) + 1; // Täytetään luvuilla 1-20
    }
    numerot[19] = 0; // Viimeiseen alkioon asetetaan 0
    
    for (int i = 0; i < 20; i++) {
        printf("%d\n", numerot[i]); // Tulostetaan lista
    }
    
    while (1) {
        int etsittava_numero;
        printf("Minkä luvun haluat etsiä väliltä 1-20? (0 lopettaa): ");
        scanf("%d", &etsittava_numero);
        
        if (etsittava_numero == 0) {
            break; // Lopetetaan, jos käyttäjä syöttää 0
        }
        
        int tulos = etsi_eka(numerot, etsittava_numero);
        if (tulos == -1) {
            printf("Ei löytynyt\n");
        } else {
            printf("Luku löytyi indeksistä: %d\n", tulos);
        }
    }
    return 0;
}