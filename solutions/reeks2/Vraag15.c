
#include <stdio.h>
#define MIN 100
#define MAX 120
#define BEREIK MAX-MIN+1
#define AANTAL MAX-MIN

int main(){
    int getal;
    int aanwezigheid[BEREIK] = {0}; /*alle elementen zullen hierdoor 0 zijn*/
    int i;
   
    srand(time(NULL)); /* anders krijg je altijd diezelfde getallen! */
    /* let op! als je - ter controle - hier in de lus ook wil uitschrijven welk getal er effectief gegenereerd werd,
       zorg er dan voor dat je slechts EEN MAAL rand() oproept!!! */

    for(i = 0; i < AANTAL; i++){    
        getal = MIN + rand()%BEREIK);        
        aanwezigheid[getal - MIN] = 1;
        printf("%d ",getal);
    }
    
    printf("\nKwamen niet voor:\n");
    for(i = 0; i < BEREIK; i++){
        if (aanwezigheid[i] == 0){
            printf("%d ",(i+MIN));    
        }
    }   
    return 0;        
}
