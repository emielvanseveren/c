/*
 * Deze code levert, in tegenstelling tot vorige oefening, wél de gevraagde output.
 * Toch levert deze oplossing nog minder punten op dan de vorige oplossing. Waarom?
*/

#include <stdio.h>
int main(){
    int macht = 1;
    int i;
    for(i=0; i<20; i++){
        printf("%d ",macht);
        macht *= 2;
        if(macht > 10000){
            break;
        }
    }
    return 0;
}
/* UITLEG:
 * For loops worden gebruikt indien je het aantal herhalingen vooraf kent.
 * While loops voor een bepaalde condition, waar het aantal herhalingen niet gekend is.

 * Een break is een slechte manier om een for loop te onderbreken. Dit wijst opnieuw dat de kans groot is dat een while
 * loop nodig is ipv een for loop.
*/
