
#include <stdio.h>

void zoek_extremen(const int  rij[], int lengte, int * min, int * max){
     int i;

     *min = rij[0];
     *max = rij[0];

     for(i=1; i<lengte; i++){
          if(*min > rij[i]){
               *min = rij[i];
          }
          else if(*max < rij[i]){
               *max = rij[i];	
          }
     }	
}

void zoek_extremen_rec(const int rij[], int lengte, int * min, int * max){
     if(lengte == 1){
          *min = rij[0];
          *max = rij[0];
     }
     else{
          zoek_extremen_rec(rij,lengte-1,min,max);
          if(rij[lengte-1] < *min){
               *min = rij[lengte-1];
          }
          if(rij[lengte-1] > *max){
               *max = rij[lengte-1];
          }
     }
}

int main(){
     int rij [] = {5,7,9,6,4,2,3,8,5,-11,999,-11,5,4,2};       
     /* int rij [] = {-5,-2,-888,-1,-3,-9,-4,-8,-7};      */   
	
     int min,max;
     /* zoek_extremen(rij,sizeof(rij)/sizeof(int),&min,&max); */	
     zoek_extremen_rec(rij,sizeof(rij)/sizeof(int),&min,&max);	
	
     printf("min is %d,  max is %d",min,max);
     return(0);        
}
/*
 *  Belangrijk: test ook met enkel negatieve getallen!
 *  Heb je opgemerkt dat de initialisatie van zowel min als max gebeurt met het 
 *  EERSTE ELEMENT uit de array, in plaats van met de willekeurig gekozen waarde 0?
 */
	

