#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Käytetään aikaa satunnaislukujen alustukseen

// Funktio printtaa listan luvut
void tulosta_luvut(int *lista, int koko) {
    for (int i = 0; i < koko; i++) {
        printf("%8d \n", lista[i]); // Näytetään listan i:s alkio
    }
}

int main(void) {
    srand(time(0)); // Alustetaan random luku generaattori ajan perusteella
    int satunnaisluvut[15]; // Lista, johon tulee 15 lukua
    
    for (int i = 0; i < 15; i++) {
        satunnaisluvut[i] = rand() % 100000; // Täytetään random luvuilla 0-99999
    }
    
    int *osoitin_listaan = satunnaisluvut; // Osoitin listaan
    tulosta_luvut(osoitin_listaan, 15); // Kutsutaan funktiota
    
    return 0;
}
