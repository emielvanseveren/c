
#include <stdio.h>
void wis(char * s);

int main(){	
     /* mag je hier niet doen:
        char * woord = "...........";    
        ZAL CRASHEN; GEEN COMPILEERFOUT    */	
     char woord [] = "8�d'a7!<t-)>+. -)4h&!e9)b*( )�j�'(�e)�!�4\n8g|'9�2o!43e5d/.' 2 3g*(e('d22a'(a25n�'(";	   
     wis(woord);
     puts(woord);
     
     char woord2[81];
     printf("\n\n\nGeef nu zelf een tekst in (met spaties);\n");
     fgets(woord2,81,stdin); 
     wis(woord2);
     puts(woord2);
	
     return 0;
}

void wis(char * s){
     char * loper = s;
     while(*s){
          if(islower(*s) || isspace(*s)){
               *loper = *s;
               loper++;	
          }
          s++;		
     }
     *loper = 0;
}
