#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Satunnaisluku 1-6
int throw_d6(void) { 
    return (rand() % 6) + 1;
}

// Satunnaisluku 1-10
int throw_d10(void) { 
    return (rand() % 10) + 1;
}

int main(void) {
    srand(time(NULL)); // Satunnaisuus

    while (1) { 
        printf("Choose an option:\n");
        printf("1. Roll a D6\n");
        printf("2. Roll a D10\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        
        int menu_option; // käyttäjän valinta
        scanf("%d", &menu_option); 

        switch (menu_option) { 
            case 1: { // 6-sivuinen noppa heitto
                int dice_result_6 = throw_d6();
                printf("You rolled a D6: %d\n", dice_result_6);
                break; 
            }
            case 2: { //  10-sivuinen noppa heitto
                int dice_result_10 = throw_d10();
                printf("You rolled a D10: %d\n", dice_result_10);
                break; 
            }
            case 3: // Lopetaa ohjelma
                printf("Goodbye!\n");
                return 0; 
            default: // Väärä vlinta
                printf("Invalid input. Please select 1, 2, or 3.\n");
        }
    }
}
