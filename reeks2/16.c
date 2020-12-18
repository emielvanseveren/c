#include <stdio.h>

int is_kleine_letter(char c){ return ('a' <= c && c <= 'z');}
int is_grote_letter(char c){ return ('A' <= c && c <= 'Z');}

void readInput(int* freq){
    char letter;

    scanf("%c", &letter);
    while(letter != '$'){
        if(is_kleine_letter(letter)){ freq[letter-'a']++; }             /* BELANGRIJK */
        if(is_grote_letter(letter)){ freq[letter-'A']++; }              /* BELANGRIJK */
        scanf("%c",&letter);
    }
}
void print_horizontal(int *frequenties, int len){
    int i;
    for(i=0; i<len;i++){
        printf("\n%c: %i", 'a'+i, frequenties[i]);
    }
}

int main(){
    int freq[26]={0}; // 26 letters
    readInput(freq);
    print_horizontal(freq, sizeof(freq) / sizeof(int));
    return 0;
}

/*
  * OPMERKINGEN
  * Elke char heeft een integer value (ASCI).
  * Bv. 97 is de integer value voor de kleine letter 'a'. Dit loopt alfabetisch tot z.
  * De hoofdletters lopen van 'A'.65 tot 'Z'.90.
  * Aangezien dit integer values zijn kan je hierbij een integer optellen/aftrekken en zo een andere letter uitkomen.
  *
  * TODO: vertical
*/