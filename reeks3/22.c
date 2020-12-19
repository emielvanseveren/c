#include <stdio.h>

void zoek_extremen(int *, int, int*, int*);

int main(){
    int t[] = {1,2,3,4,5,6,7,8,9,10};
    int min,max;
    zoek_extremen(t, sizeof(t)/sizeof(int), &min, &max);

    printf("min: %d\n", min);
    printf("max: %d\n", max);
    return 0;
}

void zoek_extremen(int *t,int n, int *min, int *max){
    int i;
    *min = t[0];
    *max = t[0];
    for(i=0;i<n;i++){
        if(t[i] < *min){ *min = t[i];}
        if(t[i] > *max){ *max = t[i];}
    }
}