/* In deze opgave wordt de faculteit van positieve gehele getallen berekend.

 Bereken de faculteit van de gehele getallen 2 tot en met 30 en schrijf de resultaten uit. Wat merk je op?
 Bereken de faculteit met andere gegevenstypes (geheel én reëel). Hoe exact is de berekende waarde voor de faculteit van grotere getallen?

 Pas het programma aan zodat de computer een willekeurig geheel getal kiest tussen 2 en 20 (grenzen inbegrepen). Bereken de faculteit van dit getal.
 Gebruik de functie rand(); - meer informatie zoek je online.

 Pas het programma aan zodat de gebruiker een positief geheel getal kan ingeven tussen 2 en 20 (grenzen inbegrepen).
 Controleer deze input! Vraag (desnoods herhaaldelijk) een nieuw getal indien de gebruiker geen geheel getal ingaf of indien het ingegeven geheel getal niet tot het interval [2,20] behoort. Vergeet niet om na elke foutieve input de resterende tekst uit de inputbuffer te verwijderen. Bereken de faculteit van dit getal.
*/

#include <stdio.h>
#include <stdlib.h> // srand() rand()
#include <time.h>   // time()

void v1(){
    int i;
    int fac = 1;

    for (i=2;i<=30; i++){
        fac *= i;
        printf("%i! %i\n", i, fac);
    }
}
void v2(){
    int i;
    unsigned long long int fac = 1;

    for (i=2;i<=30; i++){
        fac *= i;
        printf("%i! %llu\n", i, fac);
    }
}

void v3(){
    int i;
    int lower = 2;          // Inclusief de boundaries (2 en 20)
    int upper = 20;
    unsigned long long int fac = 1;

    // seed random
    srand(time(NULL));
    int random = rand() % (upper - (lower+1)) + lower;

    for (i=2; i<random;i++){ fac *= i; }
    printf("%i!: %llu\n", fac);
}
void v4(){
    int getal = 0;
    int i;
    unsigned long long int fac = 1;

    printf("Geef een getal in tussen 2 en 20: ");
    while(getal<2 || getal > 20){
        scanf("%i", &getal);

        while (getchar() != '\n'); // clear input buffer.
    }

    for (i=2; i<=getal;i++){
        fac *=i;
    }
    printf("%i!: %llu", getal, fac);
}

int main(){
    v1(); v2(); v3(); v4();
    return 0;
}

/* Opmerkingen
 * v1()  deelvraag 1           =>  Vanaf +- 20! zullen de waarden niet meer kloppen omdat de grote van het getal groter is dan wat maximaal in een int past.
 * v2()  deelvraag 1           =>  We gebruiken het grootste int type, "unsigned long long int". Dit heeft plaats voor 64 bits. Nu kloppen de resultaten wel.
 * v3()  deelvraag 2           =>  Zonder srand(time(NULL)) zullen we steeds dezelfde random getallen verkrijgen. Wat vaak niet het gene is wat je wil. Gebruik van rand() is ook uitgelegd.
 * v4()  deelvraag 3           =>  Opgelet zie while (getchar() != '\n') Dit is ALTIJD nodig na het opnieuw opvragen van input. Dit omdat anders \n als nieuw.
*/