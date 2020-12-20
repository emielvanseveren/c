#include <stdio.h>

void verzetNaarEersteHoofdletter(char**);
char* pointerNaarEersteKleineLetter(char*);
void schrijf(char*, char*);

int main(){
    char zus1[50] = "sneeuwWITje";
    char zus2[50] = "rozeROOD";
    const char* begin;
    const char* eind;

    begin = zus1;
    verzetNaarEersteHoofdletter(&begin);
    eind = pointerNaarEersteKleineLetter(begin);
    schrijf(begin,eind);   /* schrijft 'WIT' uit */
    printf("\n");
    begin = zus2;
    verzetNaarEersteHoofdletter(&begin);
    eind = pointerNaarEersteKleineLetter(begin);
    schrijf(begin,eind);   /* schrijft 'ROOD' uit */
    return 0;
}

void schrijf(char *begin, char *eind){

    // eind is hier een void pointer

    while(begin<eind){
        printf("%c", *begin++);
    }
}


void verzetNaarEersteHoofdletter(char** l){
    while(*l && (**l<'A' || **l>'Z')) {
        (*l)++;
    }
}

/* zoek uit warom dit wel werkt nu*/
char* pointerNaarEersteKleineLetter(char* l){
    while(*l && (*l<'a' || *l>'z')){
        l++;
    }
    return l;
}
