#include <stdio.h>

int* plaats_van(int *, int, int);
void print(int *, int);

int main(){
    int t[] = {0,1,2,3,4,5};
    int n = sizeof(t) / sizeof(int);

    // getal midden
    int *p = plaats_van(t,n, 4);
    printf("Getal %d\n", *p);
    print(t, n);

    // eerste getal
    *p = plaats_van(t,n,0);
    printf("Getal %d\n", *p);
    print(t, n);

    // laatste getal
    *p = plaats_van(t,n,5);
    printf("Getal %d\n", *p);
    print(t, n);

    // getal dat niet in de array zit.
    *p = plaats_van(t,n,8);
    printf("Getal %d\n", *p);
    print(t, n);

    return 0;
}


int* plaats_van(int *t, int n,int g){
    int i=0;

    while(i<n && t[i] != g){
        i++;
    }
    if(*t == g){
        *t = (*t)*(*t);
        return t;
    }
    return NULL; // this returns a void poitner?
}

void print(int *t, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ", t[i]);
    }
    printf("\n");
}
