#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Jos haluttais avata tiedosto x hakemistosta, voitais tehdä:
// snprintf(fullPath, sizeof(fullPath), "exercises/%s", filename);
// fp = fopen(fullPath, "r");

int main(void){
    char filename[100]; //  muisti tiedostonimelle
    FILE *fp; // osoitin tiedostolle
    int placeholder_number; // muuttuja luetuille luvuille

    //  alustetaa maksimi ja minimiluvuilla
    int smallest_number = INT_MAX; // 
    int largest_number = INT_MIN; // 
    int counter = 0;

    printf("Anna tiedoston nimi: ");
    scanf("%s", filename); //  käyttäjän syöttämä tiedostonimi

    // avataan tiedosto jos se löytyy
    //  tiedostoa ei löydy, fopen palauttaa NULL
    fp = fopen(filename, "r");

    if(fp == NULL){
        fprintf(stderr, "Virhe avattaessa tiedostoa %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // fscanf palauttaa 1, jos luku onnistuu
    while(fscanf(fp, "%d", &placeholder_number) == 1){
        counter++;

        if(placeholder_number < smallest_number){ //  pienimpään
            smallest_number = placeholder_number;
        }
        if(placeholder_number > largest_number){ //  suurimpaan
            largest_number = placeholder_number;
        }
    }

    if (counter > 0){
        printf("Luettujen numeroiden määrä: %d\n", counter);
        printf("Pienin numero: %d\n", smallest_number);
        printf("Suurin numero: %d\n", largest_number);
    }
    else{
        printf("Tiedostossa ei ollut yhtään numeroa, mutta se avattiin onnistuneesti.\n");
    }

    fclose(fp); // suljetaan tiedosto

    return 0;
}