
#include <stdio.h>
#include <string.h>
void schrijf_int(const void * v){
     const int * a = (const int *) v;
     printf("%d",*a);	
}

void schrijf_cstring(const void * v){  
     const char * const * s = (const char * const *) v;
     printf("%s",*s);	
}

void schrijf_double(const void * v){
     const double * x = (const double *) v;
     printf("%f",*x);	
}

/************ Eerste poging  ***********/
void schrijf_array___(const void * t, int aantal, int grootte, char tussenteken, void (*schrijf)(const void*)){
     int i;
     schrijf(t);
     for(i=1; i < aantal; i++){
          printf("%c",tussenteken);
          t += grootte;  /* verplaats de pointer*/
          schrijf(t);
     }
     printf("\n\n");
}

/* De meeste compilers geven hier echter - terecht - warnings op:
   'pointer of type 'void*' used in arithmetic'
   Andere compilers weigeren het helemaal.
   De reden: het is niet standaard gedefinieerd wat "+i" betekent bij een void-pointer.
      
   De oplossing: de void-pointer wordt gecast naar een char-pointer, die wel
   weet hoe er gerekend moet worden. Bovendien beslaat een 'char' de kleinste eenheid
   van geheugenplaats, en zijn alle andere hier veelvoud van.
   Dus kunnen we hetzelfde principe toepassen: de stapgrootte nog aanpassen
   aan de grootte van het type waarnaar verwezen wordt.

   Met deze ingreep zijn de warnings weg, en zijn we uit de illegaliteit...
*/

/***************** VERSIE 1 - correct *******************************************/
void schrijf_array(const void * t, int aantal, int grootte, char tussenteken, 
                     void (*schrijf)(const void*))
{
   const char* hulpptr = (const char*)t; 
   int i;
   schrijf(hulpptr);
   for(i=1; i < aantal; i++){
      printf("%c",tussenteken);
      hulpptr += grootte;
      schrijf(hulpptr);
   }
   printf("\n\n");
}

int main(){
   char *namen[]= {"Evi","Jaro","Timen","Youri","Ashaf","Jennifer"};
   int leeftijden[] = {21,30,18,14,22,19};
   double scores[] = {0.5,1.6,8.2,-2.4};	
   
   schrijf_array(leeftijden, sizeof(leeftijden)/sizeof(int) ,sizeof(int), ',', 
                    schrijf_int);
   schrijf_array(namen,      sizeof(namen)/sizeof(char*)    ,sizeof(char*), ';', 
                    schrijf_cstring);	
   schrijf_array(scores,     sizeof(scores)/sizeof(double)  ,sizeof(double), '~',
                    schrijf_double);
   return 0;
}

	
/* merk op: 
   (1) voor schrijf_int, schrijf_cstring en schrijf_double in bovenstaande 3 regels 
   mag ook een & staan, maar het moet niet (compiler kan beide interpreteren)         
   (2) voor leeftijden, namen, scores in bovenstaande 3 regels mag nog (void*) staan 
   (casten naar void-pointer), maar het moet niet (compiler kan hiermee weg).    */

/***************** VERSIE 2 - even correct**************************************
  hier blijft alle code gelijk, behalve wat hieronder staat:                   */

void schrijf_double(const double *x){
     printf("%f",*x);	
}

void schrijf_int(const int * a){
     printf("%d",*a);	
}

void schrijf_cstring(const char *const * s){  // !! DUBBEL STER !! 
     printf("%s",*s);	
}

/*aanroep in het hoofdprogramma:	*/

     schrijf_array(leeftijden, sizeof(leeftijden)/sizeof(int) ,sizeof(int),    ',',
           (void (*)(const void*))schrijf_int);
     schrijf_array(namen,      sizeof(namen)/sizeof(char*)    ,sizeof(char*),  ';', 
           (void (*)(const void*))schrijf_cstring);		
     schrijf_array(scores,     sizeof(scores)/sizeof(double)  ,sizeof(double), '~', 
	   (void (*)(const void*))schrijf_double);

/* merk op:
   Bij de aanroep van de procedure schrijf_array moet de laatste parameter gecast worden, 
   aangezien de functies schrijf_int, schrijf_double en schrijf_cstring nu niet meer voldoen 
   aan het parametervoorschrift van de procedure schrijf_array */
