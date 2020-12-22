#include <stdio.h>
#include <stdlib.h> // srand() rand()
#include <time.h>   // time()

void v1(){
    int i;
    int fac = 1;

    for (i=2;i<=30; i++){
        fac *= i;
        printf("%i! %i\n", i, fac);
    }
}
void v2(){
    int i;
    unsigned long long int fac = 1;

    for (i=2;i<=30; i++){
        fac *= i;
        printf("%i! %llu\n", i, fac);
    }
}

void v3(){
    int i;
    int lower = 2;          // Inclusief de boundaries (2 en 20)
    int upper = 20;
    unsigned long long int fac = 1;

    // seed random
    srand(time(NULL));
    int random = rand() % (upper - (lower+1)) + lower;

    for (i=2; i<random;i++){ fac *= i; }
    printf("%i!: %llu\n", fac);
}
void v4(){
    int getal = 0;
    int i;
    unsigned long long int fac = 1;

    printf("Geef een getal in tussen 2 en 20: ");
    while(getal<2 || getal > 20){
        scanf("%i", &getal);

        while (getchar() != '\n'); // clear input buffer.
    }

    for (i=2; i<=getal;i++){
        fac *=i;
    }
    printf("%i!: %llu", getal, fac);
}

int main(){
    v1(); v2(); v3(); v4();
    return 0;
}
