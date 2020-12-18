#include <stdio.h>

void * schuif_links(char *t, size_t len){
    char first = t[0];
    int i;
    for(i=1; i<len;i++){
        t[i-1] = t[i];
    }
    t[len-1] = first;
}

print(char *t, size_t len){
    int i;
    for(i=0; i<len;i++){
        printf("%c", t[i]);
    }
    printf("\n");
}

int main(){
    char rij[] = {'s','a','p','a','p','p','e','l'};
    int i;
    size_t len = sizeof(rij) / sizeof(char);

    for (i=0;i<3;i++){
        schuif_links(rij, len);
        print(rij, len);
    }
    return 0;
}
