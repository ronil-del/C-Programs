#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEMS_MENU 40 // Määritellään maksimimäärä ruokia

// rakenteen määrittäminen menu_tavaraa varten
typedef struct menu_item_ { 
    char name[50]; // Ruoan nimi
    double price; // ruoan hinta
} menu_item;

// lajittelu nimien mukaan aakkosjärjestys
int sort_by_name(const void *a, const void *b){
    const menu_item *item_a = a;
    const menu_item *item_b = b;
    return strcmp(item_a->name, item_b->name); // vertaa nimien aakkosjärjestystä
}

// lajitellaa hinnan mukaan halvimmasta kalleimpaan
int sort_by_price(const void *a, const void *b){
    const menu_item *item_a = a;
    const menu_item *item_b = b;
    if (item_a->price > item_b->price){
        return 1; // Jos item_a on kalliimpi, palauta 1
    }
    if (item_a->price < item_b->price){
        return -1; // Jos item_b on kalliimpi, palauta -1
    }
    return 0; // Jos hinnat ovat samat, palauta 0
}

int main(void){
    char filename[100]; // Tiedoston nimi
    FILE *fp; // Tiedoston käsittelijä
    menu_item items[ITEMS_MENU]; // Taulukko, johon tallennetaan menu-tavarat
    int counter = 0; // Laskuri, joka seuraa kuinka monta ruokalajia on luettu
    int sorting_choice; // Käyttäjän valinta lajittelutavasta

    // Kysytään käyttäjältä tiedoston nimeä
    printf("Enter the name of the file you want to read: ");
    if (scanf("%99s", filename) != 1){
        fprintf(stderr, "ERROR: FILENAME COULD NOT BE READ!\n");
        return -1;
    }

    fp = fopen(filename, "r"); // Avaa tiedoston lukemista varten
    if (fp == NULL){
        fprintf(stderr, "ERROR: COULDN'T OPEN THE FILE %s!\n", filename);
        return -1;
    }

    // Luetaan tiedostosta menu-tavarat, kunnes saavutetaan maksimi tai tiedosto loppuu
    while (counter < ITEMS_MENU && fscanf(fp, "%49[^;]; %lf", items[counter].name, &items[counter].price) == 2) {
        counter++;
    }

    // Jos tiedoston lukemisessa on virhe
    if (ferror(fp)) {
        fprintf(stderr, "ERROR: File reading error occurred!\n");
        fclose(fp);
        return -1;
    }

    fclose(fp); // Suljetaan tiedosto lukemisen jälkeen

    // Kysytään käyttäjältä, miten halutaan lajitella
    printf("\nHow would you like to sort your menu?\n");
    printf("1. Sort by name\n");
    printf("2. Sort by price\n");
    printf("Enter your choice (1 or 2): ");
    if (scanf("%d", &sorting_choice) != 1){
        fprintf(stderr, "ERROR: Could not read your input.\n");
        return -1;
    }

    // Suoritetaan lajittelu käyttäjän valinnan mukaan
    switch (sorting_choice) {
        case 1:
            qsort(items, counter, sizeof(menu_item), sort_by_name); // Lajitellaan nimien mukaan
            break;
        case 2:
            qsort(items, counter, sizeof(menu_item), sort_by_price); // Lajitellaan hintojen mukaan
            break;
        default:
            fprintf(stderr, "ERROR: WRONG INPUT! Please enter 1 or 2.\n");
            return -1; // Jos syöte on virheellinen, lopetetaan
    }

    // Tulostetaan lajitteluvalinnan mukaan järjestetty menu
    printf("\nHere is the sorted menu:\n");
    for (int i = 0; i < counter; i++){
        printf("%-50s %4.2f\n", items[i].name, items[i].price); // Vasemmalle tasattu nimi, hinta kahdella desimaalilla
    }

    return 0;
}
