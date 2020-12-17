/*
    Schrijf een programma dat tekstuele input van de gebruiker, afgesloten met een $-teken, verwerkt
    (zie voorwaarden na het voorbeeld!). Van elke letter wordt bijgehouden hoe dikwijls hij voorkomt. Hierbij worden
    hoofdletters meegerekend bij de overeenkomstige kleine letters. Daarna worden twee histogrammen getekend
    (zie voorbeeld).

    Voorbeeld: Invoer van de gebruiker: Als je tevreden bent met weinig, bezit je veel. $

    Eerste histogram:

    a:   *
    b:   **
    c:
    d:   *
    e:   ***********
    ...
    z:   *

    Tweede histogram:

        e
        e
        e
        e
        e
        e
        e
        e              t
        e   i    n     t
     b  e   ij l n     t v
    ab de g ij lmn   rst vw  z

Voorwaarden waaraan je oplossing moet voldoen:

    Je schrijft en gebruikt drie procedures: één die de tekst inleest/verwerkt, één die een horizontaal staafdiagram tekent en één die een vertikaal staafdiagram tekent.
    Je gebruikt, buiten scanf en printf, geen bibliotheekfuncties. Zelf extra hulpfuncties schrijven kan wel zinvol zijn.

Laat nu je programma vanaf de command line draaien, waarbij je input-redirection gebruikt om de input te halen uit het bestand gandhi.txt.
 *
 *
*/


#include <stdio.h>

int is_kleine_letter(char c){ return ('a' <= c && c <= 'z');}
int is_grote_letter(char c){ return ('A' <= c && c <= 'Z');}

void readInput(int* freq){
    char letter;

    scanf("%c", &letter);
    while(letter != '$'){
        if(is_kleine_letter(letter)){ freq[letter-'a']++; }             /* BELANGRIJK */
        if(is_grote_letter(letter)){ freq[letter-'A']++; }              /* BELANGRIJK */
        scanf("%c",&letter);
    }
}
void print_horizontal(int *frequenties, int len){
    int i;
    for(i=0; i<len;i++){
        printf("\n%c: %i", 'a'+i, frequenties[i]);
    }
}

int main(){
    int freq[26]={0}; // 26 letters
    readInput(freq);
    print_horizontal(freq, sizeof(freq) / sizeof(int));
    return 0;
}

/*
  * OPMERKINGEN
  * Elke char heeft een integer value (ASCI).
  * Bv. 97 is de integer value voor de kleine letter 'a'. Dit loopt alfabetisch tot z.
  * De hoofdletters lopen van 'A'.65 tot 'Z'.90.
  * Aangezien dit integer values zijn kan je hierbij een integer optellen/aftrekken en zo een andere letter uitkomen.
  *
  * TODO: vertical
*/