
#include <stdio.h>

void my_toupper(char *s){
    if(*s >= 'a' && *s <= 'z'){
        *s = *s-'a'+'A';
    }
    s++;

    while(*s){
        if (*s >='A' && *s <= 'Z'){ *s = (*s)-'A'+ 'a';}
        s++;
    }
};


int main(int argc, char** argv){
    int i;

    if(argc == 1) {
       printf("Dag allemaal!");
       return 0;
    }

    for(i=1;i<argc;i++){
        my_toupper(argv[i]);
        printf("Dag %s!\n", argv[i]);
    }

   return 0;
}