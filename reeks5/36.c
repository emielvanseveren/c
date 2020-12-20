#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   double x,y;
} punt;

double max(double, double);
double euclidische_afstand(const punt*, const punt*);
double manhattan_afstand(const punt*, const punt*);
double schaakbord_afstand(const punt*, const punt*);  // Chebyshev-afstand

double bepaal_max_afstand(const punt*, int, double (*)(const punt*, const punt*));

int main(){

    int i,aantal;

    punt p1 = {1,2};
    punt p2 = {2,4};

    printf("Euclidische afstand: %.2lf\n", euclidische_afstand(&p1,&p2));
    printf("Manhattan afstand: %.2lf\n", manhattan_afstand(&p1,&p2));
    printf("Schaakbord afstand: %.2lf\n", schaakbord_afstand(&p1,&p2));

    // Vraag aan de gebruiker hoeveel punten er zullen worden ingegeven.
    printf("Hoeveel punten zullen er worden ingegeven?");
    scanf("%d", &aantal);

    // dit kan niet. Dus de enige manier dat we dit kunnen doen is aan de hand van malloc.
    punt *punten = malloc(aantal*sizeof(punt));

    for(i=0;i<aantal;i++){
        printf("Geef coordinaten in volgens x,y: ");
        while (scanf("%lf,%lf", &punten[i].x,&punten[i].y) != 2){
            while(getchar() != '\n'); // clear input buffer
        };
    }

    printf("Maximum euclidische afstand: %.2lf\n",bepaal_max_afstand(punten, aantal, euclidische_afstand));
    free(punten); // Vrijgeven van geheugen.
    return 0; // indien 0 alles geslaagd.
}


double euclidische_afstand(const punt *p1, const punt *p2 ){
    return sqrt(pow(p1->x-p2->x,2) + pow(p1->y-p2->y,2));
}
double manhattan_afstand(const punt *p1, const punt *p2 ){
    return (abs(p1->x) + abs(p1->y) + abs(p2->x) + abs(p2->y));
}

double max(double d1, double d2){
    return d1>d2?d1:d2;
}

double schaakbord_afstand(const punt *p1, const punt *p2 ){
    return max(abs(p2->x-p1->x),abs(p2->y-p2->y));
}

double bepaal_max_afstand(const punt *t, int size, double (*afstand)(const punt*, const punt*)){
    int i,j;
    double m; // max

    // elk punt moet vergeleken worden met elk ander punt.
   for(i=0; i<size;i++){
       for(j=0;j<size;j++){
           m = max(afstand(&t[i], &t[j]),m);
       }
   }
   return m;
}
