/*
 * Om de grootste gemende deler (ggd) van twee getallen te berekenen, werd je allicht aangeleerd om de twee getallen
 * eerst te ontbinden in priemfactoren, om dan de gemeenschappelijke factoren te ontdekken. Het kan ook anders, met het
 * algoritme van Euclides dat gebruik maakt van volgende gelijkheid:

    ggd(a , b) = ggd(b , a mod b);
    De uitdrukking a mod b lees je als 'a modulo b' en stelt de rest van a bij deling door b voor. In de meeste
    programeertalen, ook in C (en Cpp), gebruik je de notatie % in plaats van mod.

    Het algoritme van Euclides vervangt de getallen a en b (herhaaldelijk) door de getallen b en a mod b. Indien a>b,
    zullen b en a mod b kleiner zijn dan a en b - en dus werd het probleem vereenvoudigd. Dit vervangen stopt van zodra
    een van de getallen 0 is: ggd(a,0) = a.

    Schrijf een recursieve functie ggd(a,b) die de grootste gemene deler van twee gehele getallen berekent.

    Test uit met

    ggd(-6,-8)==2
    ggd(24,18)==6
    ggd( 0,-5)==5
    ggd(6,-35)==1

    Opmerking: Het is wel belangrijk dat je bij het uittesten duidelijk laat merken aan de gebruiker of de test geslaagd
    is (zodat hij zelf niet moet zitten narekenen of de gegeven uitkomst juist is).
    In deze oefening kan je bijvoorbeeld een procedure controleer_ggd(a,b,res) toevoegen die nagaat of het restultaat
    dat je bekomt met ggd(a,b) overeenkomt met het meegegeven verwachte resultaat en de uitslag van de test rapporteert.
*/

#include <stdio.h>

int main(){
    return 0;
}

/* Opmerkingen */