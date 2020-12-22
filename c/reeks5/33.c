#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 2


char* lees(){
    char zin[N+1];
    int lengte;
    char * start;

    fgets(zin,N+1, stdin);
    lengte = strlen(zin);

    // 'aap\n'
    if(zin[lengte-1] == '\n'){
        zin[lengte-1] = '\0';
        lengte--;
    } else { // 'noot' of 'appelmoes' indien er nog iets resterend in stdin staat verwijder dit
        while(getchar() != '\n');
    }

    start = malloc((lengte+1)*sizeof(char));
    strcpy(start, zin);
    return start;
}

int main(){
    int i;
    for(i=0; i<5; i++){
        char * tekst = lees();
        printf("Ik las ***%s*** \n",tekst);
        free(tekst);
    }
    return 0;
}