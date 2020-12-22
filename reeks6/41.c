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
Node* merge(Node **, Node**);


int main(){
    srand(time(NULL));
    Node * m = maak_gesorteerde_lijst_automatisch(10,1000);
    Node * n = maak_gesorteerde_lijst_automatisch(5,1000);
    printf("\nLIJST m:\n");    print_lijst(m);
    printf("\nLIJST n:\n");    print_lijst(n);
    printf("\nDeze worden gemerged. \n\n");
    Node * mn = merge(&n,&m);
    printf("\nLIJST m:   \n");	print_lijst(m);
    printf("\nLIJST n:   \n");	print_lijst(n);
    printf("\nRESULTAAT: \n");	print_lijst(mn);

    printf("\nVerwijder dubbels\n");
    verwijder_dubbels(mn);
    printf("\nRESULTAAT: \n");	print_lijst(mn);

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

Node * merge(Node **pa, Node **pb){
    Node *l;
    Node *i = *pa;
    Node *j = *pb;
    Node *k;

    if(i == 0){
        l = *pb;
        *pb = 0;
        return l;
    }
    else if(j == 0){
        l = *pa;
        *pa = 0;
        return l;
    }

    if((*pa)->value < (*pb)->value){
        l = *pa;
        i = (*pa)->next;
        k = l;
    }
    else{
        l = *pb;
        j = (*pb)->next;
        k = l;
    }

    while(i != 0 && j != 0){
        if(i->value < j->value){
            k -> next = i;
            i = i -> next;
        }
        else{
            k -> next = j;
            j = j -> next;
        }
        k = k -> next;
    }
    if(i != 0){
        k -> next = i;
    }
    if(j != 0){
        k -> next = j;
    }

    *pa = 0;
    *pb = 0;
    return l;
}

