
#include <stdio.h>
typedef unsigned int uint;
const int LENGTE = sizeof(uint)*8;

int bit_i(uint x, int i){
     return (x >> i) & 1;
     /* alternatief:   return (x & (1<<i)) >> i;     */
}

void schrijf(uint x, int lengte){    
     int i, viervoud = lengte/4*4;
     for(i=lengte-1; i>=viervoud; i--){
          printf("%u",bit_i(x,i));
     }
     for(i=viervoud-1; i>=0; i-=4){  
          printf(" ");
          int k;
          for(k=0; k<4; k++){        
               printf("%u",bit_i(x,i-k));
          }
     }
     printf("    %u\n",x);
}

uint eenbit(int i){
     return 1<<i;
}

int aantal_eenbits(uint getal){
     int teller=0;
     while (getal) {
          teller+=(getal&1);
          getal>>=1;
     }
     return teller;
}

uint bit_i_aangezet(uint x, int i){
     return x | eenbit(i);
}

/* niet expliciet gevraagd; wel nuttig  */
uint alle_bits_omgedraaid(uint x){
     return ~x;
}

uint bit_i_uitgezet(uint x, int i){
     return x & ~(eenbit(i));
}

uint bit_i_gewisseld(uint x, int i){
     return x ^ eenbit(i);    
}

int zijn_gelijk(uint a, uint b){
     return a^b;
}

int is_even(uint g){
     return 1 & ~(g&1);
}


int main(){
     uint k = 49;
     int tel;    
     schrijf(k,16);
     tel = aantal_eenbits(k);
     k = bit_i_uitgezet(k,5);
     schrijf(k,16);
     k = bit_i_aangezet(k,6);
     schrijf(k,16);
     schrijf(eenbit(6),16);
     schrijf(k^k,16);
     return 0;
}

