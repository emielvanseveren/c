
#include <stdio.h>
/* in functie/procedure kan sizeof niet achterhalen hoe groot de array is*/

void schrijf_even_posities(const char t[], int aantal){ 
     printf("IN PROCEDURE #elementen =%i\n", sizeof(t)/sizeof(int));
     int i;
     for(i=0; i<;aantal; i+=2){
          printf("%c",t[i]);                       
     }     
}

int main(){
     char letters [] = {'p','o','r','e','o','i','f','o','i','e','c','i','i',':','a','-','t','('}; 
     int lengte, i;
    
     lengte = sizeof(letters)/sizeof(char);
     printf("lengte van array met letters is %i\n",lengte);
     for(i=0; i<lengte; i+=2)     {      
          printf("%c",letters[i]);                       
     }         
     printf("\nLetters uitschrijven via procedure\n");
     schrijf_even_posities(letters,lengte);
     return 0;   
}
