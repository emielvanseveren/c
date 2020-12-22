
#include <stdio.h>
void print_lijn(char, int );

void teken_horizontaal(const int[] );
void teken_vertikaal(const int[] );

int is_kleine_letter(char );
int is_grote_letter(char );

void lees_input(int[] );

int main(){
     int frequenties[26];     
     lees_input(frequenties);	
     teken_horizontaal(frequenties);
     teken_vertikaal(frequenties);
     return 0;		
}

void print_lijn(char c, int lengte){
     int i;
     for(i = 0; i < lengte; i++){
          printf("%c",c);		
     }
}

void teken_horizontaal(const int frequenties[]){
     int i;
     for(i = 0; i < 26; i++){
          printf("\n%c:   ",('a'+i));
          print_lijn('*',frequenties[i]);
     }
}

void teken_vertikaal(const int frequenties[]){
     int grootste_frequentie = 0;
     int i;
     for(i = 0; i < 26; i++){
          if(grootste_frequentie < frequenties[i]){
               grootste_frequentie = frequenties[i];
          }
     }	
     for(i = grootste_frequentie; i > 0; i--){
          printf("\n");
          int k;
          for(k = 0; k < 26; k++){
               if(frequenties[k] >= i){
                    printf("%c",'a'+k);
               }
               else{
                    printf(" ");
               }
          }		
     }
}

int is_kleine_letter(char c){
     return ('a' <= c && c <= 'z');
}

int is_grote_letter(char c){
     return ('A' <= c && c <= 'Z');
}

void lees_input(int frequenties[]){
     for(i=0 ; i<26 ;i++){
          freqenties[i]=0;
     }
     char letter;
     scanf("%c",&letter);
     while(letter != '$'){
          if(is_kleine_letter(letter)){
               frequenties[letter-'a']++;	
          }
          else if(is_grote_letter(letter)){
               frequenties[letter-'A']++;
          }
          scanf("%c",&letter);
     }
}

