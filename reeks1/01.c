/*
 Schrijf een programma dat volgende tekst op het scherm brengt (delay bij uitschrijven van de verschillende getallen is niet nodig).

    Hello world!
    10 9 8 7 6 5 4 3 2 1
    START
*/

#include <stdio.h>
#define N 10

int main(){
    int i;
    printf("Hell world!\n");

    for(i=N; i>0; i--){
        printf("%i ", i);
    }
    printf("\nSTART\n");

    return 0;
}


/* Opmerking
 * Variabelen kunnen niet in de for loop worden gedeclareerd.
 * Moeten bovenaan de functie worden gedeclareerd.

 * DEFINE N 10 is een constante integer waardoor overal N tijdens het compilen vervangen wordt door de waarde 10.
 * Deze waarde kan dus niet meer worden aangepast.

 * In principe hoeft het niet te eindigen op return 0. Maar indien het eindigt op nul weten we eigenlijk dat alles gelukt is.
*/