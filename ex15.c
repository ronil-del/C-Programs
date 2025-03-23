#include <stdio.h>

#define ITEMS_MENU 40 // ääritellään maksimimäärä ruokalista-alkioille

typedef struct menu_item_ { // määritellään rakenne (struct) ruokalistalle
    char name[50];  // ruoka nimi
    double price;   // Ruoka hinta
} menu_item;

int main(void) {
    char filename[100]; 
    FILE *fp;  // soitin
    menu_item items[ITEMS_MENU];  // Taulukko, joka pitää sisällään ruokalistan alkioita
    int counter = 0;  // Laskuri joka seuraa luettujen määrää

    printf("Enter the name of the file you want to read: ");  // Kysytään käyttäjältä tiedoston nimi
    if (scanf("%s", filename) != 1) {
        fprintf(stderr, "VIRHE!!!!! TIEDOSTOA EI VOI LUKEA!! SE ON RIKKI\n");  // Jos tiedoston nimeä ei voida lukea ilmoitetaan virhe
        return -1;
    }

    fp = fopen(filename, "r");  // ritetään avaa tiedosto lukutilassa
    if (fp == NULL) {
        fprintf(stderr, "VIRHE!!!!!! TIEDOSTOA EI VOI AVATA  %s!\n", filename);  // os tiedostoa ei voida avata ilmoitetaan virhe
        return -1;
    }

    // luetaan tiedoston sisältöä niin kauan kuin taulukossa on tilaa
    // %49[^;] lukee merkit aina puolipisteeseen asti ja %lf lukee desimaaliluvun
    while (counter < ITEMS_MENU && fscanf(fp, "%49[^;]; %lf", items[counter].name, &items[counter].price) == 2) {
        counter++;  // kasvatetaan laskuria, kun saadaan uusi ruokalista-alkio
    }
    fclose(fp);  // Sljetaan tiedosto luennan jälkeen

    // ululostetaan luetut ruokalista-alkiot muotoiltuna
    // %4.2f tarkoittaa, että hinta tulostetaan leveydellä 4 ja kahdella desimaalilla
    for (int i = 0; i < counter; i++) {
        printf("%-50s %4.2f\n", items[i].name, items[i].price);  //  nimi ja hinta ulostus
    }

    return 0;  //  päättyy onnistuneesti
}
