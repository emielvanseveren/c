#include <stdio.h>
#include <ctype.h>

void wis(char*);

int main(){
    char s[] = "t3st";
    wis(s);
    printf("%s", s);
    return 0;
}

void wis(char *s){ // array pointer naar eerste element
    char *loper =s;

    while(*s != 0) { // zolang het karakter verschillend is van het null-karakter
        if(islower(*s) || isspace(*s)){
           *loper = *s;
           loper++;
        }
        s++;
    }
    *loper = 0;
}