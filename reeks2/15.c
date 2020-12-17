/*
    Schrijf een programma dat 20 gehele getallen genereert tussen 100 en 120 (grenzen inbegrepen) en deze ook op het
    scherm toont. Daarna worden alle getallen die niet gekozen werden, in stijgende volgorde uitgeschreven.
    Kijk kritisch na!
    Heb je de grenzen en het aantal te genereren getallen in constanten bewaard? */


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

/* Opmerkingen
 * Aangezien de constanten vervangen worden wordt range vervangen door (upper-lower+1). Maar hierbij ontbreken haakjes!!!
 * waardoor zonder haakjes dit mis geïnterpreteerd wordt (door volgorde van bewerkingen).
*/