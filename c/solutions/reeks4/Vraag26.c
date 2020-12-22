
#include <stdio.h>
void my_toupper(char * s);

/* In deze oefening gebruiken we een procedure.
   In latere oefeningen wordt dit omgevormd naar een functie (nl. returntype char*) 
*/

int main(){
     /* char * woord = "snEEuwwITJE<3!!";              DIT MAG NIET */
     char woord[50] = "snEEuwwITJE<3!!";     /*        DIT MAG WEL */ 
	                                        
     /* Laatste vraag: inlezen van toetsenbord: */	
     printf("Geef een woord op: ");
     scanf("%49s",woord);	
	
     my_toupper(woord);
     puts(woord);
     return 0;
}
	
void my_toupper(char * s){
     if(*s >= 'a' && *s <= 'z'){
          *s = *s - 'a' + 'A'; 
     }	                     
     s++;                     
     while(*s != 0){	
          if(*s >= 'A' && *s <= 'Z'){
               *s = *s - 'A' + 'a';
          }
          s++;
     }
}
