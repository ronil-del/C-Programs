#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // satunnaislukugeneraattori ajalla
    int shift_value; // s iirtoarvon säilyttäminen

    while (1) {
        printf("Syötä luku välillä 0-15 tai negatiivinen luku lopettaaksesi: ");
        if (scanf("%d", &shift_value) != 1) {
            fprintf(stderr, "Virhe syötteessä!\n");
            continue;
        }

        // luku on negatiivinen, lopetetaan ohjelma
        if (shift_value < 0) {
            printf("Ohjelma päättyy...\n");
            break;
        }

        // luku on suurempi kuin 15, tulostetaan virheilmoitus
        if (shift_value > 15) {
            printf("Virheellinen luku\n");
            continue;
        }

        unsigned int random_number = rand(); // satunnaisluvun luonti
        printf("Satunnaisluku heksamuodossa: 0x%X\n", random_number); // tulostetaan luku heksadesimaalisena

        //  looginen oikealle siirto
        unsigned int shifted_value = random_number >> shift_value;

        //  vain alimmat 6 bittiä (maskilla 0x3F, eli binäärimuodossa 00111111)
        shifted_value &= 0x3F;

        // siirretty luku heksadesimaalisena, vähintään kahdella numerolla
        printf("Siirretty luku heksamuodossa: 0x%02X\n", shifted_value);
    }

    return 0;
}
