#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node ;

struct Node {
    int v;
    Node *next;
};

void voeg_vooraan_toe(int , Node**);
void print_lijst(const Node*);
void free_nodes(const Node**);

int main(){
    Node *l = 0; // l is de startknoop
    voeg_vooraan_toe(7, &l);
    voeg_vooraan_toe(3, &l);
    print_lijst(l);
    free_nodes(&l);
    return 0;
}

void voeg_vooraan_toe(int v, Node ** n){
    Node * even_bijhouden = *n;
    *n = malloc(sizeof(Node));
    (*n)->v = v;
    (*n)->next = even_bijhouden;
}

void print_lijst(const Node *n){
    while(n){
        printf("%d ", n->v);
        n = n->next;
    }
    printf("\n");
}

void free_nodes(const Node **n){
   Node *temp;
    while(*n){
       temp = *n;
       *n = temp->next;
       printf("Geef knoop %d vrij\n", temp->v);
       free(temp);
    }
}
