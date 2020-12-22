#include <stdio.h>

schrijf_aantal(char *p,int aantal){// van positie pointer 4 letters 4.
    int i;
    for(i=0;i<aantal;i++){
        printf("%c", *(p+i));
    }
}

schrijf(char *begin, char *eind){
    int i;
    while(begin < eind){
        printf("%c", *begin++);
    }
}


int main(){
    char letters [] = {'p','o','r','g','o','e','d','o','i','e','o','k','i',':','a','-','t','('};
    const char *p = letters;

    printf("Dit zijn het aantal elementen via de pointer: %d\n", sizeof(letters)/sizeof(char));
    printf("Dit zijn het aantal elementen in de array via de pointer: %d \n", sizeof(p)/sizeof(char)); // Dit klopt toch niet?

    printf("Dit is de size van een char pointer: %d\n", sizeof(char*));
    printf("Dit is de size van een int pointer: %d\n", sizeof(int*));
    printf("Dit is de size van een double pointer: %d\n", sizeof(double*));
    printf("Dit is de size van de void pointer: %d\n", sizeof(void*));

    schrijf_aantal(letters+3,4);
    printf("\n");
    schrijf(p+10,p+12);

    return 0;
}
