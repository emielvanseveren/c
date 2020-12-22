
/* LET OP! om zo min mogelijk zaken te herberekenen, bewaar je telkens de laatst gebruikte term (bvb -x^3/3!) 
 *    en leid je daaruit de  volgende term af.
 *    Anders zou je veel berekeningen opnieuw doen.  Vergelijk: 
 *        om x^5/5! rechtstreeks uit te rekenen, heb je volgende bewerkingen nodig: 
 *                   x*x*x*x*x / (1*2*3*4*5)
 *
 *        om x^5/5! af te leiden uit -x^3/3! (het 'vorige resultaat'),  heb je volgende bewerkingen nodig:   
 *		    ('vorige resultaat') * (-x*x)/(4*5)
 * 
 * Dit verschil vergroot als je verder in de reeksontwikkeling bent. */

#include <stdio.h>
#include <math.h>
/*********************************** versie 1 *********************/
int main(){
    double x = 0.23; 
    double term = x;
    double som;
    int n = 2 * 10;
    int i;
    som = x;
    for(i=2 ; i<n ; i += 2){
        term *= -x*x / (i*(i+1));
        som += term;
    }
    printf("sin(%.2f) =  %.16f \n",x,som);
    printf("controle     %.16f \n",sin(x));
    return 0;    
}

/*********************************** versie 2 *********************/
/* double heeft 16 beduidende cijfers en je zoekt een waarde tussen -1 en 1 termen die kleiner zijn dan 1e-16 zullen geen invloed meer hebben op de som*/
#define EPS 1e-16
int main(){    
    double x = 0.23; 
    double term = x;
    double som = term;
    int i=2;
    while (fabs(term)>EPS){        
        term *= -x*x / (i*(i+1));
        som += term;
        i +=2;
    }
    printf("sin(%.2f) =  %.16f \n",x,som);
    printf("controle     %.16f \n",sin(x));
    return 0;        
}

/*********************************** versie 3 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define EPS 1e-16
int main(){    
    double x, term, som;    
    int i;
    srand(time(NULL)); 
    x = (rand()%6400-3200)/1000.0; 
   /* let op! vraag je 4 cijfers na de komma, dan krijg je geen gelijkmatige randomverdeling, omdat de bovengrens van rand() kleiner is dan 64000 !! */
    term = x;
    som = x;
    i = 2;
    while (fabs(term)>1e-16){        
        term *= -x*x/(i*(i+1));
        som += term;
        i +=2;
    }
    printf("sin(%.2f) = %.15f \n",x,som);
    printf("controle    %.15f \n",sin(x));    
    return 0;
}
/* De rand-functie van C is niet geschikt voor doorgedreven statistische toepassingen!! 
   Het bereik is te klein, en er valt wel wat aan te merken op de kwaliteit. 
   In C++ heb je nieuwe bibliotheken die meer garanties bieden.        
*/
