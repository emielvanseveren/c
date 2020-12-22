
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 4  /*1000 in de opgave*/
                      
char* lees(){
     char tekst[MAX+1];          /* +1 !! */
     int lengte;
     char * nieuw;
    
     printf("Geef een tekst: ");
     fgets(tekst,MAX+1,stdin);   
     lengte = strlen(tekst); 
    
     /* indien 4+1 karaktervelden voorzien, en 'aap\n' ingelezen */
     if(tekst[lengte-1] == '\n'){
          tekst[lengte-1] = 0;    /* of '\0' */
          lengte--;
     }
     /* indien 4+1 karaktervelden voorzien, en 'noot' ingelezen: 
        alles ok; niets doen of lege lus                                */
     /* indien 4+1 karaktervelden voorzien, en 'appelmoes' ingelezen: 
        'appe\0' bewaard; 'lmoes' moet nog weg                          */
     else{    /* enkel als er nog iets staat!! */
          fflush(stdin);
     }
    
     nieuw = malloc((lengte+1)*sizeof(char));
     strcpy(nieuw,tekst); 
     return nieuw;
}


int main(){
     int i;
     for(i=0; i<5; i++){    
          char * tekst = lees();
          printf("Ik las ***%s***.\n",tekst);
          free(tekst);                     /* BELANGRIJK! */
     }    
     return 0;
}
