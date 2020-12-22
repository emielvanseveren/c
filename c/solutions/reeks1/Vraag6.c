
/* versie 1 is correct tot 12!  */
#include <stdio.h>
int main(){
     long int fac = 1;
     int n = 30;
     int i;
     for(i=2 ; i<=n ; i++){
          fac *= i;
          printf("%d! = %lld \n",i,fac);
     }
     return 0;
}

/* versie 2 - met unsigned long long */
#include <stdio.h>
int main(){
     unsigned long long int fac = 1;
     int n = 30;
     int i;
     for(i=2 ; i<=n ; i++){
          fac *= i;
          printf("%d! = %llu \n",i,fac);
     }
     return 0;
}

/* versie 2 - met double - vanaf 23 ! zijn er te weinig beduidende cijfers, en is het resultaat niet correct ! */
#include <stdio.h>
int main(){
     double fac = 1;
     int n = 30;
     int i;
     for(i=2 ; i<=n ; i++){
          fac *= i;
          printf("%d! = %.0f \n",i,fac);    
     }
     return 0;
}

/* versie 3 - computer kiest getal */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
     unsigned long long int fac = 1;
     int i, n;    
     srand(time(NULL)); /* Laat je dit weg, dan genereert het programma bij elke run 
                           telkens hetzelfde getal.    Probeer uit!                 */
     n = rand()%19 + 2;
     for(i=2 ; i<=n ; i++){
          fac *= i;
     }    
     printf("%d! = %lld \n",n,fac);
     return 0;
}

/* versie 4 - gebruiker geeft getal in */
#include <stdio.h> 
int main() { 
     unsigned long long int fac = 1; 
     int i, n; 
     printf("Geef een geheel getal uit het interval [2,20] in: ");
     while (scanf("%d",&n)==0 || n<2 || n>20) {
          /* inputbuffer leegmaken - fflush(stdin); werkt ook*/
          while (getchar() != '\n');            
          printf("Foute input!\n");
          printf("Geef een geheel getal uit het interval [2,20] in: ");
     }
     for(i=2 ; i<=n ; i++) { 
          fac *= i; 
     } 
     printf("%d! = %lld \n",n,fac); 
     return 0; 
}

