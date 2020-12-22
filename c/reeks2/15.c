#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWER 100
#define UPPER 120
#define RANGE (UPPER-LOWER+1)   // HAAKJES ZIJN HIER BELANGRIJK
#define N UPPER-LOWER

int main(){
   srand(time(NULL));
   int getallen[N] = {0}; // Zorg dat by default overal een 0 zit.

   int i;
   for(i=0;i<N;i++){
       int g =  (rand()%RANGE)+LOWER;
       getallen[g-LOWER] +=1;
       printf("%i ", g);
   }
   printf("\n");

   for(i=0;i<N;i++){
       if(getallen[i] == 0){
           printf("%i ", i+LOWER);
       }
   }
    return 0;
}
