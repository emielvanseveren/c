
#include <stdio.h>
#define AANTAL 3  /* voor testdoeleinden zet je dit klein genoeg! */
int main(){	
    int getal;
    int som = 0;
    int aantal = 1;
    printf("Geef een positief geheel getal: ");
    scanf("%d",&getal);
    while(aantal < AANTAL && getal >= 0){
        som += getal;
        aantal++;
        printf("Geef een positief geheel getal: ");
        scanf("%d",&getal);        
    }
    if(getal < 0){
        printf("U gaf helaas geen %d positieve gehele getallen op.\n",AANTAL);
    }
    else{
        som += getal; /* verwerken van het laatste getal, dat ook positief was */
        printf("Dank, u gaf %d positieve gehele getallen op.\n",AANTAL);
    }
    printf("De som van de positieve getallen die u opgaf is %d.",som);
    return 0;
}
