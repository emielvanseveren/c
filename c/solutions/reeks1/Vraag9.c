
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int cijfersom(int x){
     int som = 0;
     while(x>0){
          som += x%10;
          x /= 10;	
     }	
     return som;
}

/* 'rec' staat voor 'recursief' */
int cijfersom_rec(int x){
     if(x<10) return x;
     return x%10 + cijfersom_rec(x/10);
}

int main(){
     int getal;
     srand(time(NULL));
     /* rand() geeft willekeurig positief getal kleiner dan RAND_MAX (=32767)
        We willen elke getal met 5 cijfers genereren*/        
     getal = 10000 + (rand()+rand()+ rand())%90000;       
     printf("De cijfersom van %d     is %d  \n",getal, cijfersom_herhaald(getal));
     printf("De cijfersom_rec van %d is %d \n",getal,cijfersom_rec(getal));			
     return 0;	
}
