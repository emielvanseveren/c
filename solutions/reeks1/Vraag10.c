
#include <stdio.h>
unsiged long long int faculteit (int x){
    int i;
    unsigned long long int fac = 1;
    for(i = 2; i<= x; i++){
          fac *= i;
    } 
    return fac;
}
unsiged long long int faculteit_rec(int x){
    if(x<2) return 1;
    return x*faculteit_rec(x-1);
} 
int main(){
    int i;
    for(i=2 ; i<=20 ; i++){
        printf("%d ! = %lld = %lld\n", i , faculteit(i),faculteit_rec(i));
    }
    return 0;   
}
/* MERK OP:
 * Voor wie zich de vraag stelt: de snelheid van de rechtstreekse berekening en de recursieve zijn niet merkbaar verschillend. 
 * Enkel als de stack (= geheugenruimte die bijhoudt waar het programma gebleven was met de recursie) vol begint te raken, zou je
 * vertraging kunnen zien. Maar tegen dan zijn we al lang de limiet voor de overflow gepasseerd...
 * 
 * Wil je tijdsverschillen echt afmeten tegen elkaar, dan zou je een grote herhaling moeten inbouwen, en timen. Dit is hier echter niet gevraagd.
 */
