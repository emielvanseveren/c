#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ONDERGRENS 0

typedef struct Node Node;
struct Node {
    int value;
    Node *next;
};

Node* maak_gesorteerde_lijst_automatisch(int, int);
void verwijder_dubbels(Node*);
void print_lijst(Node*);
void free_nodes(Node**);

int main() {
    srand(time(NULL));
    Node *l = maak_gesorteerde_lijst_automatisch(10, 100);
    print_lijst(l);

    printf("\nDubbels verwijderen\n");
    verwijder_dubbels(l);

    print_lijst(l);
    free_nodes(&l);
    return 0;
}

Node * maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens){
    Node *root = 0; // start pointer.
    Node *helper;
    int i, num;

    for(i=0;i<aantal;i++){
        Node *n = malloc(sizeof(Node)); // pointer naar een geheugenplaats grootte van een Node.
        n->value = ((rand() % bovengrens - ONDERGRENS+1) + ONDERGRENS);
        helper = root;

        if(root == 0 || num < root->value){
                root = n;
                root->next = helper;
                continue;
            }

            while(helper->next && num > helper->next->value){ // zolang root != null
                helper = helper->next;
            }
        n->next = helper->next;
        helper->next = n;
    }
    return root;
}

void verwijder_dubbels(Node *l){
    Node *t = l;
    while(t){
        while(t->next && t->value == t->next->value){
            Node *weg = t->next;
            t->next = t->next->next;
            free(weg);
        }
        t = t->next;
    }
}

void print_lijst(Node *l){
    while(l){
        printf("%d ", l->value);
        l = l->next;
    }
}

void free_nodes(Node **l){
    Node *t;
    while(*l){
        t = *l;
        *l = (*l)->next;
        free(t);
    }
}
