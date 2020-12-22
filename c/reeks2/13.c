#include <stdio.h>

int index_van(double* t, double n, double g){ // n is len(arr).
    double i=0;
    while(*t != g && i <n){
        t++; // T is geen array pointer meer maar een gewone pointer. Die kan verplaatst worden.
        i++;
    }
    if(i==n){ return -1; }
    return i;;
}

int main(){
    double getallen[] = {1.1,2,3,4,4,5};
    double zoek = 2.0;
    printf("Kleinste index van het getal %f in array is: %i\n", zoek,index_van(getallen, sizeof(getallen)/sizeof(double), zoek));
    return 0;
}