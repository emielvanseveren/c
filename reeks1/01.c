/*
 Schrijf een programma dat volgende tekst op het scherm brengt (delay bij uitschrijven van de verschillende getallen is niet nodig).

    Hello world!
    10 9 8 7 6 5 4 3 2 1
    START
*/

#include <stdio.h>

int main(){
    int i;
    printf("Hell world!\n");

    for(i=10; i>0; i--){
        printf("%i ", i);
    }
    printf("\nSTART\n");
}


/* Opmerking
 * Variabelen kunnen niet in de for loop worden gedeclareerd.
 * Moeten bovenaan de functie worden gedeclareerd.
*/