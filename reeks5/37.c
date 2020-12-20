#include <stdio.h>
#include <stdlib.h>

#define N 2

typedef struct {
    int waarde, aantal_delers;
    int *delers;

} Deeltal;

void schrijf_ints(const int *, int);
void schrijf_deeltal(const Deeltal*);
void schrijf_deeltallen(const Deeltal*, int);

int aantal_delers_van(const int);
int * delers_van(const int, int);

void lees_deeltal(Deeltal *);
void lees_deeltallen(Deeltal *, int);
Deeltal* zoek(int, Deeltal*, int);

void free_delers(Deeltal *d){
   free(d->delers);
}

void free_deeltallen(Deeltal * g, int aantal){
    int i;
    printf("\nFree tabel met %d deeltallen:",aantal);
    for(i=0; i<aantal; i++){
        free_delers(&g[i]);
    }
}

int main(){
    Deeltal d = {}; // {} - BELANGRIJK
    lees_deeltal(&d);
    schrijf_deeltal(&d);


    // Lees_deeltallen
    Deeltal * deeltallen = malloc(N*sizeof(Deeltal));
    lees_deeltallen(deeltallen, N);
    schrijf_deeltallen(deeltallen, N);


    Deeltal *gezocht = zoek(20, deeltallen, N);
    if(gezocht !=0){
        schrijf_deeltal(gezocht);
    } else printf("\n 20 is niet gevonden...\n");


    // Hier loopt nog iets mis.
    free_delers(&d);
    free_deeltallen(deeltallen, N); // Het geheugen van alle delers van de deeltallen vrijgeven
    free(deeltallen);
   return 0;
}

void schrijf_ints(const int *t, int n){
    int i;
    for(i=0;i<n-1;i++){
        printf("%d-", t[i]);
    }
    printf("%d\n",t[n-1]);
}

void schrijf_deeltal(const Deeltal *d){
    schrijf_ints(d->delers, d->aantal_delers);
}
void schrijf_deeltallen(const Deeltal *t, int aantal){
    int i;
    for(i=0; i<aantal;i++){
        schrijf_deeltal(&t[i]);
    }
}

int aantal_delers_van(const int x){
    int i;
    int c=0;
    for(i=1;i<=x/2;i++){
        if(x%i==0){
            c++;
        }
    }
    return c;
}

int* delers_van(const int x, int aantal){

    int i;
    int n=0;
    int *delers = malloc(aantal*sizeof(int));

    for(i=1;i<=x/2;i++){
        if(x%i == 0){
            delers[n]=i;
            n++;
        }
    }
    return delers;
}

void lees_deeltal(Deeltal *d){
    printf("Geef een getal in:");
    scanf("%d", &d->waarde);

    if(d->waarde < 0){ d->waarde *=-1; } // Indien het getal negatief is.
    d->aantal_delers= aantal_delers_van(d->waarde);
    d->delers = delers_van(d->waarde, d->aantal_delers);
}

void lees_deeltallen(Deeltal *t, int aantal){
    int i;
    for(i=0;i<aantal;i++){
        // Het deeltal zal terug verdwijnen ds we zullen dit moeten alloceren
        lees_deeltal(&t[i]);
    }
}

Deeltal* zoek(int waarde, Deeltal*t, int aantal){
    int i;
    while((*t).waarde == waarde && i < aantal){
       i++;
       t++;
    }
    if(i==aantal) return NULL;
    else return t;
}
