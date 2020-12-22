
#include <stdio.h>

void pivoteer( char * begin, char * einde , char * pivot){
     char *p,*q;	
     p = pivot-1;
     q = pivot+1;     
     while (p>=begin && q<einde){
          char h = *p;
          *p = *q;
          *q = h;
          p--;
          q++;
     }
}
