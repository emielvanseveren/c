/*
    Gegeven de functies som, product en verschil en een hoofdprogramma:

    #include <stdio.h>
    #define AANTAL 5

    int som(int a, int b){ return a+b;}
    int product(int a, int b){ return a*b;}

int verschil(int a, int b){
    return a-b;
}

void schrijf(const int * t, int aantal){
    int i;
    for(i=0; i<aantal; i++){
        printf("%i ",t[i]);
    }
    printf("\n");
}



int main(){
    int a[AANTAL];
    int b[AANTAL];
    int c[AANTAL];
    int i;
    for(i=0; i<AANTAL; i++){
        a[i] = 10*i;
        b[i] = i;
    }

    vul_array(a,b,c,AANTAL,som);
    schrijf(c,AANTAL);

    vul_array(a,b,c,AANTAL,product);
    schrijf(c,AANTAL);

    vul_array(a,b,c,AANTAL,verschil);
    schrijf(c,AANTAL);
    return 0;
}

    Je ziet dat de derde array wordt ingevuld aan de hand van de twee eerste arrays. Afhankelijk van de laatste parameter
    van de procedure vul_array, bevat de derde array de som, respectievelijk product of verschil van de overeenkomstige
    elementen uit de eerste twee arrays.

    Als output zal er dus verschijnen:

        0 11 22 33 44
        0 10 40 90 160
        0 9 18 27 36

    Schrijf de procedure vul_array(...). De laatste parameter is een functie. Definieer de procedure vul_array ná je
    main-functie. Dan moet je vul_array vooraf declareren. Laat in die parameterlijst de benamingen van de parameters zelf
    weg, schrijf enkel de types neer.
