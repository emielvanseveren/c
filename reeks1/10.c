
/*
    Herneem oefening 6, maar los dit nu op met twee functies:

    De functie faculteit(x) berekent de faculteit van een gegeven geheel getal x.
    De functie faculteit_rec(x) doet een recursieve berekening.

    Controleer in een eenvoudig hoofdprogramma.
 */


#include <stdio.h>

unsigned long long int faculteit(int getal){
    int i;
    unsigned long long int fac = 1;
    for(i=2; i<=getal;i++){
        fac *= i;
    }
    return fac;
}

unsigned long long int faculteit_rec(unsigned long long int getal){
    if(getal == 1) { return getal; }
    return getal * faculteit(getal-1);
}

int main(){
    printf("%i!: %llu\n", 5, faculteit(5));
    printf("Recursief %i!: %llu\n", 5, faculteit_rec(5));
    return 0;
}


/* Opmerkingen
 * Recursief kan trager zijn dan iteratie. Naast de inhoud van de functie, moet de recursie ook de stack pointer bijhouden
 * van de functie. Dit betekent dat hij extra code moet runnen, en dus trager kan zijn.
 */