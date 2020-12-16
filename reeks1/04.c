/*
 * Gegeven de opgave schrijf alle machten van 2 (beginnend bij 2^0=1), kleiner dan 10.000 uit.
 * De onderstaande code geeft niet de gevraagde uitvoer - hoe kan je dit heel snel detecteren?
 * Pas de code ook aan zodat je de gevraagde uitvoer bekomt.
*/

#include <stdio.h>

void fout(){
    int macht = 1;
    printf("FOUT: ");
    while(macht < 10000){
        macht *= 2;
        printf("%d ",macht);
    }
}

void correct(){
    int macht =1;
    printf("CORRECT: ");
    while(macht < 10000){
        printf("%d ",macht);
        macht *= 2;
    }
}

int main(){
    fout();
    printf("\n");
    correct();
    return 0;
}

/* Uitleg
De print vindt in het foute voorbeeld plaats NA de print statement. Het is een goeie gewoonte gaat alsvolgt.

* Deel 1:    klaarzetten van het 'item' waarop getest wordt (buiten de while loop)
* Deel 2:    WHILE (voorwaarde waar item aan moet voldoen om door te gaan in de lus){
* Deel 3:        hier komen alle zaken die wel herhaald moeten worden, maar niet tot DEEL 4 behoren
* Deel 4:        opnieuw klaarzetten van het 'item' waarop getest wordt (dit kan eventueel meerdere regels beslaan)
            }
*/