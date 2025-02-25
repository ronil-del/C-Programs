#include <stdio.h>
#include <string.h>

int replace_char(char *str, const char *repl) {
    if (strlen(repl) != 2) return 0; // Tarkistetaan toinen merkkijono on täsmälleen kaksi merkkiä
    
    char old_char = repl[0];
    char new_char = repl[1];
    int count = 0;
    
    while (*str) {
        if (*str == old_char) {
            *str = new_char;
            count++;
        }
        str++;
    }
    return count;
}

int main(void) {
    char text[80];
    char replacement[3];
    
    printf("Syötä muokattava merkkijono: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // poistetaan rivinvaihto
    
    printf("Syötä korvattava ja korvaava merkki (esim. e3): ");
    fgets(replacement, sizeof(replacement), stdin);
    replacement[strcspn(replacement, "\n")] = '\0';
    
    int count = replace_char(text, replacement);
    
    if (count > 0) {
        printf("Korvattujen merkkien määrä: %d\n", count);
        printf("Muokattu merkkijono: %s\n", text);
    } else {
        printf("Merkkijonoa ei muokattu.\n");
    }
    
    return 0;
}
