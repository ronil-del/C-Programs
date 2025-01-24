#include <stdio.h>

int main(void) {
    float bussilippu_hinta, taksi_hinta, rahaa;
    int valinta;

    //  hinnat ja käytettävissä olevat rahat
    printf("Anna bussilipun hinta: ");
    scanf("%f", &bussilippu_hinta);

    printf("Anna taksin hinta: ");
    scanf("%f", &taksi_hinta);

    printf("Kuinka paljon rahaa sinulla on? : ");
    scanf("%f", &rahaa);

    // onko varaa kumpaankaan
    if (rahaa < bussilippu_hinta && rahaa < taksi_hinta) {
        printf("Valitettavasti joudut kävelemään loppumatkan...\n");
        return 0;
    }

    // JATKuu kunnes rahat eivät riitä kumpaankaan kulkumuotoon
    while (rahaa >= bussilippu_hinta || rahaa >= taksi_hinta) {
        printf("Valitse kulkumuoto:\n");
        printf("1 - Taksi (%.2f euroa)\n", taksi_hinta);
        printf("2 - Bussi (%.2f euroa)\n", bussilippu_hinta);
        printf("Syötä valintasi: ");
        scanf("%d", &valinta);

        if (valinta == 1) {
            if (rahaa >= taksi_hinta) {
                printf("Valitsit taksin.\n");
                rahaa -= taksi_hinta;
            } else {
                printf("Rahasi eivät riitä taksiin.\n");
            }
        } else if (valinta == 2) {
            if (rahaa >= bussilippu_hinta) {
                printf("Valitsit bussin.\n");
                rahaa -= bussilippu_hinta;
            } else {
                printf("Rahasi eivät riitä bussiin.\n");
            }
        } else {
            printf("Virheellinen valinta, yritä uudelleen.\n");
        }

        printf("Sinulla on nyt %.2f euroa jäljellä.\n", rahaa);

        // Tarkistetaan uudelleen, onko varaa jatkaa matkustamista
        if (rahaa < bussilippu_hinta && rahaa < taksi_hinta) {
            printf("Rahasi loppuivat. Kävele loppumatka.\n");
            break;
        }
    }

    return 0;
}