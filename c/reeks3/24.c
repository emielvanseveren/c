#include <stdio.h>

void pivoteer(char*, char*, char*);
void schrijf(char*,char*);


int main(){
    char tekst[] = {'b','d','?','z','g','o','e','z','e','b',' ','d','i','g','!','h','o','s','v'};
    pivoteer(tekst+7,tekst+12,tekst+9);
    schrijf(tekst+4,tekst+15);
    return 0;
}


void schrijf(char *begin, char *eind){
    while(begin < eind){
        printf("%c", *begin++);
    }
}

void pivoteer(char *begin, char *eind, char *pivot){ // pivot = center die blijft gelijk.
    char *p, *q;

    // Neem eerste letter links van en rechts van het midden waar rond moet gedraaid worden.
    p = pivot-1;
    q = pivot+1;

    while (p>=begin && q<=eind){
        char h = *p; // sla waarde tijdelijk op
        *p = *q;
        *q = h;

        // shuif ze 1 op.
        p--;
        q++;
    }
}