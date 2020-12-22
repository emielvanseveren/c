
#include <stdio.h>
int ggd(int a, int b){
    if(a<0 || b<0){
        return ggd(abs(a),abs(b));
    }
    if(b==0){
         return a<0 ? -a : a ;    /* of abs(a) gebruiken */
    }
    return ggd(b,a%b); /* indien a<b, zal dit gelijk zijn aan ggd(b,a)
                          en kan de recursie vanaf die stap de getallen
                          echt verkleinen */
}
/*Procedure om de ggd te testen, en dit te rapporteren*/
void controleer_ggd(int a, int b, int result){    
     printf("ggd(%d,%d) is %sok\n",a,b,(ggd(a,b)!=result? "NIET ":""));
}
int main(){
    controleer_ggd(24,-36,12);
    controleer_ggd(24,1,1);
    controleer_ggd(-9,-24,9);
    controleer_ggd(-6,-8,2);
    controleer_ggd(24000,5000,1000);
    controleer_ggd(0,-5,5);
    return 0;
}
/* Merk op:
   de waarden voor het uittesten (zowel a,b als uitkomst) kunnen beter in een array bewaard worden, zodat het controleren in een lus geschreven kan
   worden. Dat kan je doen na volgende theorieles.   */
