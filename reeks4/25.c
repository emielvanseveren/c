#include <stdio.h>
#define AANTAL 5

// signaturen
void vul_array(int *, int*, int*, int, int (*)(int,int));

int som(int a, int b){ return a+b;}
int product(int a, int b){ return a*b;}
int verschil(int a, int b){ return a-b;}


void schrijf(const int * t, int aantal){
    int i;
    for(i=0; i<aantal; i++){
        printf("%i ",t[i]);
    }
    printf("\n");
}

int main(){
    int a[AANTAL];
    int b[AANTAL];
    int c[AANTAL];
    int i;

    // Dit vult de array met startwaarden.
    for(i=0; i<AANTAL; i++){
        a[i] = 10*i;
        b[i] = i;
    }

    vul_array(a,b,c,AANTAL,som);
    schrijf(c,AANTAL);

    vul_array(a,b,c,AANTAL,product);
    schrijf(c,AANTAL);

    vul_array(a,b,c,AANTAL,verschil);
    schrijf(c,AANTAL);
    return 0;
}

void vul_array(int *a, int *b, int *c, int size, int (*fn)(int, int)){
    int i;
    for(i=0;i<size;i++){
       c[i] = fn(a[i],b[i]);
    }
}