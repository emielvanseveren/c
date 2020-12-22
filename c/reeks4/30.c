#include <stdio.h>
#include <stdbool.h>

bool array_bevat_dubbels_na_elkaar(const void *, int, int);

int main() {
    int getallen_ja[]   = {1,2,3,4,5,6,7,8,9,10,10,11};
    int getallen_neen[] = {1,2,1,2,1,2,1,2,1,2,3,4,5};
    char* woorden_ja[]  = {"leentje","leerde","lotje","lopen","lopen","langs","de",
                           "lindelaan"};
    char* woorden_neen[] = {"wie","goed","doet","goed","ontmoet"};


    // voor elk van deze vier arrays wordt er opgeroepen:


    if(array_bevat_dubbels_na_elkaar(woorden_neen, sizeof(woorden_neen) / sizeof(char*), sizeof(char*))){
        printf("Deze array bevat dubbels na elkaar");
    }
    else{
        printf("Deze array bevat geen dubbels na elkaar");
    }
    return 0;
}

bool array_bevat_dubbels_na_elkaar(const void *t, int size, int grootte){
    int i;
    const char *h = t; // hulp pointer.

    for(i=1;i<size;i++){
       if(*h == *(h+grootte)){ return true; }
       h += grootte;
    }

    return false;
}