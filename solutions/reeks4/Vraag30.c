
#include <stdio.h>

bool array_bevat_dubbels_na_elkaar(const void * array, int aantal, int grootte, 
                            bool (*zijn_gelijk) (const void *, const void *)){	
    const char * rij = (const char*) array;
    int i=1; 
    while(i < aantal && !zijn_gelijk(rij + (i-1)*grootte, rij + i*grootte)) {
        i++;	
    }
    return (i < aantal);  
}

bool zijn_ints_gelijk(const void * a, const void * b){
    const int * aa = (const int*) a;
    const int * bb = (const int*) b;
    return *aa == *bb;
}

bool zijn_cstrings_gelijk(const void * a, const void * b){	
    const char * const * aa = (const char * const *) a;
    const char * const * bb = (const char * const *) b;
    return strcmp(*aa,*bb)==0; 
}


/* 4 keer functie array_bevat_dubbels_na_elkaar oproepen in hoofdprogramma */
array_bevat_dubbels_na_elkaar(getallen_ja,sizeof(getallen_ja)/sizeof(int),
                 sizeof(int),zijn_ints_gelijk)
array_bevat_dubbels_na_elkaar(getallen_neen,sizeof(getallen_neen)/sizeof(int),
                 sizeof(int),zijn_ints_gelijk)   
array_bevat_dubbels_na_elkaar(woorden_ja,sizeof(woorden_ja)/sizeof(char*),
                 sizeof(char*),zijn_cstrings_gelijk) 	
array_bevat_dubbels_na_elkaar(woorden_neen,sizeof(woorden_neen)/sizeof(char*),
                 sizeof(char*),zijn_cstrings_gelijk)
