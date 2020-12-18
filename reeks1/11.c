
#include <stdio.h>
#include <stdlib.h>

int ggd(int a, int b){
    if(b == 0){ return abs(a);} // OPGELET ggd kan nooit een negatief getal zijn.
    return ggd(b, a % b);
}

int main(){
    printf("ggd(%i, %i) is: %d\n", -6, -8, ggd(-6, -8));
    printf("ggd(%i, %i) is: %d\n", 24, 18, ggd(24, 18));
    printf("ggd(%i, %i) is: %d\n", 0, -5, ggd(0, -5));
    printf("ggd(%i, %i) is: %d\n", 6, -35, ggd(6, 35));
    return 0;
}

