
#include <stdio.h>
#include <math.h>
#include <stdio.h>

#define EPSILON  0.000001 /* een klein getal (doubles vergelijk je nooit exact !)*/     
                       
int index_van(const double[], int , double);

int main(){
     double rij[]= {8.8,4.4,2.2,6.6,0.0,10.0};
     double x;
     int lengte = sizeof(rij)/sizeof(double);
     int index;
	
     printf("Geef een reeel getal op  ");
     while(scanf("%lf",&x)==0){
          fflush(stdin);  //buffer leegmaken
          printf("Geef een reeel getal op  ");	 	
     }
     printf("\nJe gaf het getal %.1f op.",x);
		
     index = index_van(rij,lengte,x);
     if(index==-1){
          printf("\n%.1f werd niet gevonden in de array.",x);
     }
     else{	
          printf("\nIn de array staat %.1f op plaats %d.\n",x,index);
     }
		
     return 0;
} 
 
/*    Merk op: Je MOET stoppen zodra je vond wat gezocht werd.
               Je MAG NIET de hele array doorlopen als je al vond wat je zocht!! */

int index_van(const double array[], int aantal, double gezocht){
	int i = 0;
	while(i<aantal && fabs(gezocht-array[i]) > EPSILON){
		i++;
	}		
	return (i<aantal ? i : -1);  
}
