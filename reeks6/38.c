/*
    typedef struct knoop knoop;
    struct knoop{
        int d;
        knoop * opv;
    };

    int main(){
        knoop * l = 0;
        knoop * k = l;
        k = (knoop*) malloc(sizeof(knoop));
        return 0;
    }

    Teken de twee pointers l en k. Wat gebeurt er precies? Is l gewijzigd?
*/
