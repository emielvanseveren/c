
#include <stdio.h>
#define AANTAL 15    /* te kiezen */
int main(){
     int i;
     printf("Hello world!\n");
     for(i=AANTAL; i>0; i--){
          printf("%d ",i);                    
     }
     printf("\nSTART");
     return 0;   
}
/*  MERK OP
 *  
 *  DECLARATIE VAN i
 *  C eist dat de teller buiten de lus gedeclareerd wordt. Te betreuren, 
 *  maar in latere versies van C ook rechtgezet. Van zodra we in C++
 *  werken, wordt dit als NOT DONE beschouwd.
 *  Ook de plaats van declaratie is op de C-manier: vooraan in het
 *  programma. Eveneens NOT DONE beschouwd zodra we met C++ bezig zijn.
 */
