#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float tulot_kuukausittain[12]; // määritellään taulukot
    float verot_kuukausittain[12];
    float veroaste;  // määritellään muuttujat
    float tuloraja;
    int rajan_yli_veroaste;
    int indeksi = 0;

    // kysytään tiedot ja tallennetaan taulukoihin/muuttujiin
    printf("Anna veroaste: ");
    scanf("%f", &veroaste);
    getchar();
    printf("Anna tuloraja: ");
    scanf("%f", &tuloraja);
    getchar();
    printf("Anna veroaste tuloille, jotka ylittävät rajan: ");
    scanf("%d", &rajan_yli_veroaste);
    getchar();

    // luodaan silmukka, joka kysyy kuukausitulot
    for (int i = 1; i <= 12; i++) {
        printf("Anna tulot kuukaudelle %d: ", i);
        scanf("%f", &tulot_kuukausittain[indeksi]);
        getchar();
        indeksi += 1;
    }

    // lasketaan verot ja tallennetaan ne toiseen taulukkoon
    for (int k = 0; k < 12; k++) {
        if (tulot_kuukausittain[k] <= tuloraja) {
            verot_kuukausittain[k] = tulot_kuukausittain[k] * (veroaste / 100);
        } else {
            verot_kuukausittain[k] = tuloraja * (veroaste / 100) + (tulot_kuukausittain[k] - tuloraja) * (rajan_yli_veroaste / 100);
        }
    }

    printf("\nKuukausi   Tulot      Verot\n");
    for (int i = 0; i < 12; i++) {
        printf("%8d %9.2f %9.2f\n", i + 1, tulot_kuukausittain[i], verot_kuukausittain[i]);
    }

    return 0;
}
