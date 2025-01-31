#include <stdio.h>

// Funktio lukee luvun tietyltä väliltä
int get_number_in_range(int min, int max) {
    int input;
    while (1) {
        printf("Please enter a number between %d and %d: ", min, max);
        scanf("%d", &input);
        if (input >= min && input <= max) {
            printf("A number was successfully read\n");
            printf("The number was in the specified range\n");
            break;
        }
        printf("The number was not in the specified range\n");
        printf("Please try again\n");
    }
    return input;
}

int main(void) {
    int min_value = 1, max_value = 6;
    printf("Let's play!!\n");

    for (int round = 1; round <= 3; round++) {
        printf("Roll a dice and enter your result.\n");
        int player_roll = get_number_in_range(min_value, max_value);

        if (player_roll == 6) {
            printf("I got %d. It is a tie\n", player_roll);
        } else {
            printf("I got %d. I win\n", player_roll + 1);
        }
    }

    printf("Better luck next time...\n");
    return 0;
}

