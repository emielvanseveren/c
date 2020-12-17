/*
 * Schrijf voor het eerste deel van deze oefening ENKEL een hoofdprogramma, geen functies of procedures. (Houd je hier aan, of je mist de clou van de oefening.)

    Maak in het hoofdprogramma een array aan waarin elk element een karakter is. Vul deze array bij declaratie op als volgt:

    char letters [] = {'p','o','r','e','o','i','f','o','i','e','c','i','i',':','a','-','t','('};

    Bepaal de lengte van de array zonder te tellen (zie theorie)!
    Schrijf in het hoofdprogramma alle karakters uit die op een even positie in de array staan.

    Schrijf nu een procedure schrijf_even_posities(...) die alle karakters uitschrijft die op een even positie in de gegeven array staan (Bepaal zelf aantal en aard van de parameters).
    Roep deze procedure op in het hoofdprogramma en test grondig uit.
 */

#include <stdio.h>

void schrijf_even_posities(char* letters, int len){ // je kan hier ook char letters[] schrijven. Maar persoonlijk vind ik een pointer duidelijker. Aangezien het geen copy van de array is.
    int i;
    for(i=0;i<len;i+=2){
        printf("%c", letters[i]);
    }
}

int main(){
    int i;
    char letters [] = {'p','o','r','e','o','i','f','o','i','e','c','i','i',':','a','-','t','('};
    int len = sizeof(letters) / sizeof(char); // Kan in principe sizeof(letters) zijn. Want char size is 1.

    for(i=0;i<len;i+=2){
        printf("%c", letters[i]);
    }
    printf("\n");
    schrijf_even_posities(letters, len);
    return 0;
}

/* Opmerkingen
 * In de subfunctie wordt niet de array gepassed maar een pointer naar het 0de element van die array. De functie
 * schijf_even_posities heeft dus geen idee dat dit een array is. En kan dus ook niet de sizeof() hiervan bepalen.
 * Als je een array passed naar een functie moet je dus ook de lengte van die array meegeven als extra parameter.
 *
 *
 * Opgelet in de main functie is dit ook een pointer. Maar dit is een speciale pointer. Een array pointer genoemd.
 * Deze pointer kan je niet verplaatsen. Vanaf je in de subroutine zit. Is dit een nieuwe (gewone) pointer die verwijst
 * naar hetzelfde element als de array pointer.
*/
