#include <stdio.h>
void my_toupper(char *);

int main(){
    char s[] = "snEEuwwITJE<3!!";
    my_toupper(s);
    printf("%s", s);
    return 0;
}

void my_toupper(char *s){
    if(*s >= 'a' && *s <= 'z'){
        *s = *s-'a'+'A';
    }
    s++;

    while(*s != '\0'){
        if (*s >='A' && *s <= 'Z'){ *s = (*s)-'A'+ 'a';}
        s++;
    }
};