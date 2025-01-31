#include <stdio.h>

// lukee käyttäjältä kokonaisluvun
int get_number(void) {
    int input;
    printf("Enter positive numbers or negative to stop: "); //  käyttäjä syöttää numeron
    scanf("%d", &input); // tallenus käyttäjän muuttujaan
    return input; // pallautetaan syötetty arvo
}

int main(void) {
    int total = 0;    // Summa
    int positive_count = 0; // Positiivisten lukujen määrä
    float avg; // Keskiarvo

    while (1) {
        int number = get_number(); // funktion kutsu ja tallennetaan paluuarvo

        if (number < 0) { // syötetty luku on negatiivinen
            if (positive_count == 0) {
                printf("You haven't entered a single positive number yet...\n"); // positiivisia lukuja ei ole
            } else {
                avg = (float)total / positive_count; //  keskiarvo
                printf("You've entered %d positive numbers. The average is: %.3f\n", positive_count, avg);
            }
            break; // TOistolause lopetus
        }

        if (number > 0) { // luku on positiivinen
            positive_count++; //  positiivisten lukujen laskuri
            total += number; // lisätään luku summaan
        }
    }

    return 0; // loppu