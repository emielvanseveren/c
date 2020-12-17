/*
    Schrijf een programma dat aan de gebruiker vijf positieve gehele getallen vraagt. Geeft de gebruiker echter een
    negatief getal in, dan stopt het programma met getallen opvragen. Nadien schrijft het programma uit of de gebruiker
    inderdaad vijf positieve gehele getallen opgaf. Tot slot wordt de som van de ingegeven positieve gehele getallen
    uitgeschreven (ook als er niet genoeg ingegeven werden). Test uit, onder andere met de getallenreeks 1 2 3 4 -5.
*/


#include <stdio.h>


int main(){

    int getal;
    int som = 0;
    int aantal = 1;
    printf("Geef een positief getal in: ");
    scanf("%i", &getal);

    while(aantal < 5 && getal >=0){
        som +=getal;
        aantal++;
        printf("Geef een positief getal in: ");
        scanf("%d", &getal);
    }

    if(getal < 0){
        printf("U gaf een negatief getal in");
    }
    else {
        som +=getal;
        printf("U gaf %i positieve gehele getallen op.\n", aantal);
    }
    printf("De som van de positieve getallen is %d", som);
    return 0;
}

/* Opmerking
 *  Je zou kunnen denken dat we hier een for loop moeten gebruiken. Aangezien we weten dat de gebruiker 5 getallen moet opgeven.
 *  Maar we weten niet of hij altijd 5 getallen zal ingeven. Het kunnen er ook 0,1,2,3 of 4 zijn. Dus we weten eigenlijk hoeveel
 *  keer de loop moet uitgevoerd worden.
 *  For met
*/