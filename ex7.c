#include <stdio.h>
#include <stdbool.h> // Tarvitaan tosi ja epätosi

// Nappaa syötteen ja tarkistaa onks se positiivinen
bool lue_positiivinen(int *arvo) {
    if (arvo == NULL) { // Ei tyhjään osoittimeen
        return false;
    }

    int syote = scanf("%d", arvo); // Haetaan luku
    
    if (syote != 1) { // Jos ei numero
        while (getchar() != '\n'); // Tyhjennetään bufferi
        return false;
    }
    
    return (*arvo > 0); // Palauttaa tosi jos yli nolla
}

int main(void) {
    int virhelaskuri = 0; // Hutien määrä
    
    while (1) {
        printf("Hei kaveri! Arvaa paljonko mulla on massia!\n");
        printf("Heitä joku positiivinen numero: ");
        
        int numero;
        if (lue_positiivinen(&numero)) {
            int rahat = (numero * 2) + 20; // Lasketaan massi
            printf("pieleen meni! Mulla on %d euroa.\n", rahat);
        } else {
            virhelaskuri++;
            printf("ei noin!!! Kokeile uudestaan!\n");
            if (virhelaskuri == 3) { // Kolme hutia ja poikki
                printf("ei tästä tuu mitään, Nähdään joskus!\n");
                break;
            }
        }
    }
    return 0;
}