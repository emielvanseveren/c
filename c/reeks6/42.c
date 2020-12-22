#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;

struct Node {
    int value;
    Node* next;
};

void print_lijst(Node *);
void voeg_getal_toe(int, Node **);
void voeg_getal_toe_rework(int, Node **);

int main(){
    // oude methode
    Node *l = 0;
    voeg_getal_toe(5,&l);
    voeg_getal_toe(10,&l);
    voeg_getal_toe(15,&l);
    voeg_getal_toe(20,&l);
    printf("\n");
    print_lijst(l);

    // rework
    Node *m = 0;
    voeg_getal_toe_rework(5,&m);
    voeg_getal_toe_rework(10,&m);
    voeg_getal_toe_rework(15,&m);
    voeg_getal_toe_rework(20,&m);
    printf("\n");
    print_lijst(m);

    return 0;
}

void voeg_getal_toe(int g, Node **pl) {
    Node *h, *m;
    if (*pl == 0 || g <= (*pl)->value) {
        h = (Node*) malloc(sizeof(Node));
        h->value = g; h->next = *pl; *pl = h;
    }
    else {
        h = *pl;
        while (h->next != 0 && h->next->value < g)
            h = h->next;
        m = h->next;
        h->next = (Node*) malloc(sizeof(Node));
        h = h->next; h->value = g; h->next = m;
    }
}

void voeg_getal_toe_rework(int g, Node **pl){
    Node * naar_achter;
    while(*pl && (*pl)->value < g){
        pl =&((*pl)->next);
    }
    naar_achter = *pl;

    *pl = (Node*) malloc(sizeof(Node));
    (*pl)->value = g;
    (*pl)->next = naar_achter;
}

void print_lijst(Node *l){
    while(l){
        printf("%d ", l->value);
        l = l->next;
    }
}