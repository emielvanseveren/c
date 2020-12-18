

#include <stdio.h>

void fout(){
    int macht = 1;
    printf("FOUT: ");
    while(macht < 10000){
        macht *= 2;
        printf("%d ",macht);
    }
}

void correct(){
    int macht =1;
    printf("CORRECT: ");
    while(macht < 10000){
        printf("%d ",macht);
        macht *= 2;
    }
}

int main(){
    fout();
    printf("\n");
    correct();
    return 0;
}

