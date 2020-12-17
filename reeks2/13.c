/*
    Schrijf een functie index_van(t, n, g), die de (kleinste) index teruggeeft van de plaats waarop een gegeven reëel
    getal g in een gegeven array t van n reële getallen gevonden wordt. Indien het getal niet aanwezig is, wordt er
    -1 teruggegeven.

    Test uit! Declareer een array (hardgecodeerd). Lees een getal in en zoek dit getal op in de array.
    Doe de nodige aanpassingen zodat je programma controleert of de gebruiker een reëel getal ingeeft
    (Indien iets wordt ingegeven dat niet aan de voorwaarden voldoet, dan blijft het programma vragen naar een reëel
    getal tot het ingegeven wordt).
 */
#include <stdio.h>

int index_van(double* t, double n, double g){ // n is len(arr).
    double i=0;
    while(*t != g && i <n){
        t++; // T is geen array pointer meer maar een gewone pointer. Die kan verplaatst worden.
        i++;
    }
    if(i==n){ return -1; }
    return i;;
}

int main(){
    double getallen[] = {1.1,2,3,4,4,5};
    double zoek = 2.0;
    printf("Kleinste index van het getal %f in array is: %i\n", zoek,index_van(getallen, sizeof(getallen)/sizeof(double), zoek));
    return 0;
}