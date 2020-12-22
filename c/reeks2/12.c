#include <stdio.h>

void schrijf_even_posities(char* letters, int len){ // je kan hier ook char letters[] schrijven. Maar persoonlijk vind ik een pointer duidelijker. Aangezien het geen copy van de array is.
    int i;
    for(i=0;i<len;i+=2){
        printf("%c", letters[i]);
    }
}

int main(){
    int i;
    char letters [] = {'p','o','r','e','o','i','f','o','i','e','c','i','i',':','a','-','t','('};
    int len = sizeof(letters) / sizeof(char); // Kan in principe sizeof(letters) zijn. Want char size is 1.

    for(i=0;i<len;i+=2){
        printf("%c", letters[i]);
    }
    printf("\n");
    schrijf_even_posities(letters, len);
    return 0;
}
