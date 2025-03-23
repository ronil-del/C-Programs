#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int number;       //  sisältämä numero
    struct node *next; // osoitin seuraavaan solmuun
} nnode;

int main(void) {
    nnode *head = NULL;  // listan ensimmäinen solmu
    nnode *tail = NULL;  // listan viimeinen solmu
    char input[100];     // läyttäjän syöte (enintään 99 merkkiä)
    char *endpointer;    // osoitin käytettäväksi strtol-funktion kanssa

    while (1) {
        printf("Enter a number or 'end' to stop:\n");
        if (scanf("%s", input) != 1) {
            fprintf(stderr, "Error reading input\n");
            return 1;  //  ei pysty lukemaan syötettä lopetetaan ohjelma
        }

        if (strcmp(input, "end") == 0) {
            break;  // syöte on 'end', lopetetaan syötteen kysyminen
        }

        // muunnetaan  kokonaisluvuksi
        long value = strtol(input, &endpointer, 10);
        if (*endpointer != '\0') {
            // jos syöte ei ollut validi kokonaisluku
            fprintf(stderr, "Error: Invalid input, please enter a number or 'end'.\n");
            continue;  // hatketaan seuraavaan syötteeseen
        }

        // luodaan uusi s
        nnode *new_node = malloc(sizeof(nnode)); // muistia 
        if (new_node == NULL) {
            fprintf(stderr, "Error allocating memory\n");
            return 1;  // JOS KÄY NIINKIN HUONOSTI ETTÄ muistin varaaminen epäonnistuu, ohjelma LOPPUU!!!!
        }

        new_node->number = (int)value;  // Asetetaan syötetty numero solmun number-kenttään
        new_node->next = NULL;           // Asetetaan seuraava solmu NULL:ksi (viimeinen solmu)

        if (head == NULL) {
            // lista on tyhjä, uusi solmu on sekä ensimmäinen että viimeinen
            head = new_node;
            tail = new_node;
        } else {
            // Lisätään uusi solmu listan loppuun
            tail->next = new_node;
            tail = new_node;
        }
    }

    //   olevat numerot tulostus
    printf("You entered the following numbers:\n");
    nnode *current = head;
    while (current != NULL) {
        printf("%d\n", current->number); // Tulostetaan  numero
        current = current->next;         // siirrytään seuraavaa 
    }

    //  varattu muisti
    current = head;
    while (current != NULL) {
        nnode *to_delete = current;
        current = current->next;
        free(to_delete);  // Vapautetaan  muisti
    }

    return 0;  // ohjelma päättyy 
}
