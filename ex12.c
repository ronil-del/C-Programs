#include <stdio.h>
#include <string.h>

int count_words(const char *str, const char *word) {
    int count = 0;
    size_t word_len = strlen(word);
    
    if (word_len == 0) return 0;
    
    const char *ptr = str;
    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr += word_len; // siiirrytään löydetyn sanan ohi
    }
    
    return count;
}

int main(void) {
    char text[256];
    char word[50];
    
    while (1) {
        printf("Syötä merkkijono: ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';
        
        printf("Syötä etsittävä sana: ");
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0';
        
        if (strcmp(word, "stop") == 0) break;
        
        int occurrences = count_words(text, word);
        printf("Sana '%s' esiintyy %d kertaa.\n", word, occurrences);
    }
    
    return 0;
}