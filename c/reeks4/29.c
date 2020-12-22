#include <stdio.h>

void schrijf_cstring(const char* const *s);
void schrijf_int(const int const *n);
void schrijf_double(const double const *n);
void schrijf_array(const void *, int, int, char, void (*)(const void*));

int main(){
    char * namen[] = {"Evi","Jaro","Timen","Youri","Ashaf","Jennifer"};
    int leeftijden[] = {21,30,18,14,22,19};
    double scores[] = {0.5,1.6,8.2,-2.4};

    schrijf_array(leeftijden, sizeof(leeftijden)/sizeof(int), sizeof(int), ',', (void (*)(const void*))&schrijf_int);
    schrijf_array(namen, sizeof(namen)/sizeof(char*), sizeof(char*), ';', (void (*)(const void*)) &schrijf_cstring);
    schrijf_array(scores, sizeof(scores)/sizeof(double), sizeof(double), '~', (void (*)(const void*)) &schrijf_double); // & moet niet maar we geven eigenlijk het adres mee v.d. func!
    return 0;
}

void schrijf_array(const void *t, int aantal, int grootte, char tussenteken, void (*schrijf)(const void*)){
    int i;
    const char * h = (const char *)t;
    schrijf(h);
    for(i=1; i<aantal; i++){
        h += grootte;
        printf("%c", tussenteken);
        schrijf(h);
    }
    printf("\n\n");
}

// s is een pointer die verwijst naar een naam. Een naam is een array van letters. Een array passen = een pointer naar het eerste karakter van de char array.
void schrijf_cstring(const char* const *s){ printf("%s", *s); }
void schrijf_int(const int const *n){ printf("%d", *n); }
void schrijf_double(const double const *n){ printf("%.1f", *n);}
