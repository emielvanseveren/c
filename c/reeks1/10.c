

#include <stdio.h>

unsigned long long int faculteit(int getal){
    int i;
    unsigned long long int fac = 1;
    for(i=2; i<=getal;i++){
        fac *= i;
    }
    return fac;
}

unsigned long long int faculteit_rec(unsigned long long int getal){
    if(getal == 1) { return getal; }
    return getal * faculteit(getal-1);
}

int main(){
    printf("%i!: %llu\n", 5, faculteit(5));
    printf("Recursief %i!: %llu\n", 5, faculteit_rec(5));
    return 0;
}
