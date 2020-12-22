


#include <stdio.h>
#include <stdlib.h>

int cijfersom(int getal){
    int som = 0; // OPGELET: vergeet dit niet gelijk te stellen aan 0. Dit wordt niet bij het initialiseren op 0 gezet. Het bevat rommel.

    while (getal>0){
        som += getal%10;            // De rest is altijd het laatste cijfer.
        getal /= 10;                // By default integer is always truncated towards 0. Het deel na de komma verdwijnt. 12345/10 = 1234,5 (het wordt => 1234)
    }
    return som;
}
int cijfersom_rec(int getal){
    if(getal<10) return getal;
    return getal%10 + cijfersom_rec(getal/10);
}

int main(){
    int getal = 12345;
    printf("De cijfersom van %d     is %d  \n",getal, cijfersom(getal));
    printf("De cijfersom_rec van %d is %d \n",getal,cijfersom_rec(getal));
    return 0;
}

/* Opmerkingen:
 * Bijvoorbeeld het getal 12345
 *
 * 1. cijfersom: Het getal is > 0
 * 2. som = 0 + 12345 module 10 => 5 Wat gelijk is aan het laatste getal
 * 3. 12345 / 10 het gedeelte na de komma wordt weggelaten. => 1234,5 => 1234  zo kunnen we cijfer per cijfer optellen.
*/