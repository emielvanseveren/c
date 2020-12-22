
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
