/*
    Schrijf een procedure schuif_links(t,n) die alle elementen van een gegeven array t met n lettertekens, één plaats
    naar links schuift. Het eerste karakter komt achteraan. Roep deze procedure drie keer aan op de array

    char rij[] = {'s','a','p','a','p','p','e','l'};

    Aangezien je de array verschillende keren moet uitschrijven, voorzie je hiervoor uiteraard een procedure.
*/

#include <stdio.h>

void * schuif_links(char *t, size_t len){
    char first = t[0];
    int i;
    for(i=1; i<len;i++){
        t[i-1] = t[i];
    }
    t[len-1] = first;
}

print(char *t, size_t len){
    int i;
    for(i=0; i<len;i++){
        printf("%c", t[i]);
    }
    printf("\n");
}

int main(){
    char rij[] = {'s','a','p','a','p','p','e','l'};
    int i;
    size_t len = sizeof(rij) / sizeof(char);

    for (i=0;i<3;i++){
        schuif_links(rij, len);
        print(rij, len);
    }
    return 0;
}


/* Opmerkingen
 *
 * Aangezien het de pointer is hebben we rechtstreeks toegang tot de geheugenplaatsen van de velden en kunnen we deze aanpassen.
 * We gaan steeds het eerste element opzij zetten. En vervolgens alle elementen opschuiven. En vervolgens het eerste element achteraan plaatsen.
 * Aangezien we gewoon schuiven blijft de grootte gelijk.
*/