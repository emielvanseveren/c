
#include <stdio.h>
#include <string.h>

/*methode my_toupper(char *s) vind je in de oplossing van oefening 26*/
const char* alfab_kleinste(const char* const *woorden ,int aantal);

int main(int argc ,char**argv){ 
     int i; 
     const char * kleinste;
     for(i=1; i<argc; i++){
          my_toupper(argv[i]);
     }
     if(argc > 1) { 
          kleinste = alfab_kleinste((const char * const *)argv+1,argc -1); 
          /* Merk op: sla het eerste element van argv over! 
             En doe dat HIER, het is niet de taak van de functie 
             alfab_kleinste om het eerste element over te slaan. */
          printf("Dag %s!",kleinste); 
     } 
     else printf("Dag allemaal!");
     return 0;
}

const char* alfab_kleinste(const char* const *woorden ,int aantal){ 
     const char* kl = woorden[0]; 
     int i; 
     for(i=1; i<aantal; i++) 
          if(strcmp(kl,woorden[i]) > 0)
               kl = woorden[i]; 
     return kl;
}


