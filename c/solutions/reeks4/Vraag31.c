
#include <stdio.h>

/*methode my_toupper(char *s) vind je in de oplossing van oefening 26*/

int main(int argc,char**argv){
     int i;
	
     if(argc > 1) {
          for(i=1; i<argc; i++){
               my_toupper(argv[i]);
               printf("Dag %s!\n",argv[i]);
          }
	
     }	
     else printf("Dag allemaal!");
}
