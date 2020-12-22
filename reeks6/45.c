#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AANTAL_LIJSTEN 3

/* TODO: werkt nog niet! */

typedef struct Node Node;
struct Node {
    char value[25];
    Node* next;
};

// De Dit Er zon is was schijnt een eens door goede een het zin. prinses. raam.

Node* geef_array_van_lijsten(int);
void voeg_woord_toe_achteraan(char[], Node**);
void print_lijst(Node *);

int main(){
    char woord[25]; // ik ga ervan uit dat een woord niet langer is dan 25 karakters.
    Node* lijsten = geef_array_van_lijsten(AANTAL_LIJSTEN); // we weten dus het eerste element.

    int i=0;
    printf("Geef woorden in, indien je wilt stoppen, type het woord: STOP\n");
    while(strcmp(woord, "STOP") != 0){
        scanf("%25s", woord);
        // input buffer schoonmaken
        int c;
        while(c = getchar() != '\n' &&  c != EOF);

        // we willen de correcte pointer
        Node *n = lijsten + ((i % AANTAL_LIJSTEN) * sizeof(Node));
        voeg_woord_toe_achteraan(woord, n);
        i++;
    }

    for(i=0;i<AANTAL_LIJSTEN;i++){
        Node *n = lijsten + (i*(sizeof(Node)));
        print_lijst(n);
    }
    return 0;
}

void print_lijst(Node *l){
    while(l){
        printf("%s ", l->value);
        l = l->next;
    }
    printf("\n");
}

Node* geef_array_van_lijsten(int aantal){
    Node * lijsten = malloc(sizeof(Node)*aantal);
    return lijsten; // geeft een pointer terug naar het eerste element.
}

void voeg_woord_toe_achteraan(char woord[], Node **l){
    Node *new = malloc(sizeof(Node));
    strcpy(new->value, woord);

    if(*l == 0){ // dit wil zeggen dat dit het eerste woord is
        *l = new;
        return;
    }

    Node *c = *l;
    while(c->next){
       c = c->next;
    }
    c->next = new;
}