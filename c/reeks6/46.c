#include <stdio.h>
#include <stdlib.h>


typedef unsigned int uint;
void print_binary(int);
int bit_i(uint x, int);
uint eenbit(int);
int aantal_eenbits(uint x);
uint bit_i_aangezet(uint, int);

int main(){
    // bit_i
    printf("Print bit met index 1 van getal 5: %d\n", bit_i(5,1));
    // eenbit
    printf("Print getal waarvan index i = 2 alle andere = 0: %i\n", eenbit(2));
    // aantal_eenbits
    print_binary(6);
    printf("aantal_eenbits: %d\n", aantal_eenbits(100));
    // bit_i_aangezet
    print_binary(100);
    printf("bit_i_aangezet: %d\n", bit_i_aangezet(100,3)); // zou moeten 5 zijn.
    print_binary(bit_i_aangezet(100,3));

    return 0;
}

// laat alle bits op 0, behalve die op index 1;
uint eenbit(int i){
    return 1<<i;
}

int aantal_eenbits(uint x){
    int i=0;
    while(x){
        if(x&1){ i++; }
        x>>=1;
    }
    return i;
}

// get bit on index
int bit_i(uint x, int index){
    return (x>>index) & 1;
}

void print_binary(int n){
    while(n){
        if (n & 1 ){                // controleren of n even of oneven is. (en dus eigenlijk 1 is of niet)
            printf("1");
        } else printf("0");
        n >>=1; // shift RIGHT once
    }
    printf("\n");
}

uint bit_i_aangezet(uint x, int i){
    return x | eenbit(i);
}

