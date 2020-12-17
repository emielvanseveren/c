/*
 * Om de grootste gemende deler (ggd) van twee getallen te berekenen, werd je allicht aangeleerd om de twee getallen
 * eerst te ontbinden in priemfactoren, om dan de gemeenschappelijke factoren te ontdekken. Het kan ook anders, met het
 * algoritme van Euclides dat gebruik maakt van volgende gelijkheid:

 ggd(a , b) = ggd(b , a mod b);

 De uitdrukking a mod b lees je als 'a modulo b' en stelt de rest van a bij deling door b voor. In de meeste
 programeertalen, ook in C (en Cpp), gebruik je de notatie % in plaats van mod.

 Het algoritme van Euclides vervangt de getallen a en b (herhaaldelijk) door de getallen b en a mod b. Indien a>b,
 zullen b en a mod b kleiner zijn dan a en b - en dus werd het probleem vereenvoudigd. Dit vervangen stopt van zodra een
 van de getallen 0 is: ggd(a,0) = a.

 Schrijf een recursieve functie ggd(a,b) die de grootste gemene deler van twee gehele getallen berekent.
*/

#include <stdio.h>
#include <stdlib.h>

int ggd(int a, int b){
    if(b == 0){ return abs(a);} // OPGELET ggd kan nooit een negatief getal zijn.
    return ggd(b, a % b);
}

int main(){
    printf("ggd(%i, %i) is: %d\n", -6, -8, ggd(-6, -8));
    printf("ggd(%i, %i) is: %d\n", 24, 18, ggd(24, 18));
    printf("ggd(%i, %i) is: %d\n", 0, -5, ggd(0, -5));
    printf("ggd(%i, %i) is: %d\n", 6, -35, ggd(6, 35));
    return 0;
}

/* Opmerking
 *  Meerdere variabelen van hetzelfde type kunnen op 1 lijn gedeclareerd worden.
*/