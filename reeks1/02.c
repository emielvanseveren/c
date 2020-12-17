/*
    Schrijf een programma dat alle (gehele) getallen van 0 tot en met 64 uitschrijft. Per regel komt zowel octale,
    decimale, als hexadecimale voorstelling van één getal. Zorg ervoor dat de getallen rechts gealligneerd zijn, dus zo:

   0    0    0
   1    1    1
 */
#include <stdio.h>

int main(){
    int i;
    for(i=0; i<65;i++){
        printf("%3d %3o %3x\n",i,i,i);
    }
    return 0;
}

/* Opmerkingen
 * d=decimal o=octal x=hex (f=float fl=double)
 * De 4 die vooraf gaat is de space die elk getal minimaal moet innemen.
 * Standaard is het rechts uitgelijnd. Indien we dit links willen uitlijnen kan dat door een '-' voor de 4 te zetten.
*/