
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10  
#define MAXAANTAL 6

/* implementatie: zie vorige oefeningen: */  
char * lees();
char ** lees_meerdere();
void geef_vrij(char **);

void plaats_pointer_op_string(const char * const * * p, char c) {
     while (**p && ***p != c) {
          (*p)++;
     }
     if (**p == 0) *p = 0;
}          
    
int main() {    
     char ** teksten = lees_meerdere();
     const char * const * p = (const char * const *)teksten;
     char c = 'a';
    
     plaats_pointer_op_string(&p, c);
     if (p)
          printf("tekst gevonden: %s",*p);
     else
          printf("geen tekst gevonden die begint met het karakter %c",c);
           
     geef_vrij(teksten);  /* alle elementen in de array wissen */            
     free(teksten);         /* zichzelf vrijgeven */
     return 0;
}
