
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 4 
#define MAXAANTAL 6  /* nadien nog een nullpointer opslaan */                         
              
/* functie lees() zie vorige oefening */

char** lees_meerdere(){
     int aantal=0;
     int i;
     char* teksten[MAXAANTAL]; 
     char** nieuwe_teksten;
   
     char* tekst = lees();
     while( aantal < MAXAANTAL-1 && strcmp(tekst,"STOP") != 0 ){  
          teksten[aantal] = tekst;
          aantal++;
          tekst = lees(); 
     } 
     if(aantal == MAXAANTAL-1 && strcmp(tekst,"STOP")!=0){
          teksten[aantal] = tekst;
          aantal++;      
     }
     else{ 
          printf("free %s\n",tekst); /* visualiseert het vrijmaken */      
          free(tekst);
     }
   
     /* nieuwe_teksten is 1 langer (voor nullpointer)  */
     nieuwe_teksten = malloc((aantal+1)*sizeof(char*));
     i=0;
     for(i=0; i<aantal; i++){
          nieuwe_teksten[i] = teksten[i];
     }
     nieuwe_teksten[aantal] = NULL;

     return nieuwe_teksten;
}           
   
void geef_vrij(char** teksten){
     printf("\nVrijmaken elementen: \n");
     while(*teksten){
          printf("free %s\n",*teksten); /* visualiseert het vrijmaken */      
          free(*teksten);
          teksten++;
     }
}

int main(){   
     char ** teksten = lees_meerdere();
     char ** w;
   
     printf("Ik las deze teksten in:\n"); 
     /* overloop met hulpptr; anders kan free niet meer! */
     w = teksten;
     while(*w){
          puts(*w);
          w++;
     }
   
     geef_vrij(teksten);  /*alle elementen in de array wissen*/
     printf("\nfree **teksten"); /* visualiseert het vrijmaken */            
     free(teksten);       /*zichzelf vrijgeven*/
     return 0;
}
