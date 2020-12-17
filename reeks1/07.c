/*
 Bij het berekenen van de sinus van een gegeven hoek in radialen, gebruikt je computer of rekenmachine onderstaande reeksontwikkeling:

    Zie foto: 07-1.png

    1.  Schrijf een programma dat de sinus berekent van 0.23 radialen door de eerste 10 termen van de reeksontwikkeling
        te berekenen. Opgelet: we kijken naar efficiëntie van je berekeningen! Vergelijk je berekening met het resultaat
        van de ingebouwde sinusfunctie uit de bibliotheek math.h - tot hoeveel decimalen is jouw berekening correct?
        Herneem de berekeningen voor 8.2 radialen, dan is de reeksontwikkeling niet nauwkeurig genoeg.

    2.  In de vorige oplossing heb je geen enkele zekerheid over de nauwkeurigheid van de reekssom. Pas je programma aan
        zodat je zeker bent dat de reekssom even correct is als het resultaat van de ingebouwde sinusfunctie.

    3.  Nu is de waarde van x hard-gecodeerd in het programma. Pas dit aan zodat x door het programma willekeurig gekozen
        wordt in het interval [-3.200,3.200[. Het getal x bevat dus drie beduidende decimalen.

    Het efficiënt implementeren van een reeksontwikkeling is niet evident. Vergelijk bijvoorbeeld het aantal
    berekeningen dat jouw code uitvoert met het aantal berekeningen van de voorbeeldoplossing.

    Heb je graag nog wat extra oefeningen op reeksontwikkelingen, dan vind je er op https://nl.wikipedia.org/wiki/Taylorreeks
    extra oefeningen, die bovendien eenvoudig te controleren zijn. Zo kan je bijvoorbeeld de uitkomst die jouw zelfgeprogrammeerde
    reeksontwikkeling van ln(1+x) geeft.

    vergelijken met de uitkomst van ln(1+x). Kies in dit geval x dan wel tussen -1 en 1 zoals de voorwaarde eist, en
    zoek uit hoe ln in C-taal geschreven wordt.

 */

#include <stdio.h>
#include <math.h>

#define N 10

int main(){
    double x = 0.23;
    double term = x;
    double som;
    int n = 2 * 10;
    int i;
    som = x;
    for(i=2 ; i<n ; i += 2){
        term *= -x*x / (i*(i+1));
        som += term;
    }
    printf("sin(%.2f) =  %.16f \n",x,som);
    printf("controle     %.16f \n",sin(x));
    return 0;
}



