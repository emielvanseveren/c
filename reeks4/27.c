/*
 Gegeven onderstaand hoofdprogramma. Schrijf de nodige code om dit te laten werken; gebruik overal verplicht schuivende
 pointers. De procedure schrijf(begin,eind) werd al gevraagd in oefening 21.

 de functie pointerNaarEersteKleineLetter(p) geeft een pointer terug naar de eerste kleine letter die te vinden is vanaf
 de huidige positie van de pointer p. Indien er geen kleine letters meer volgen, geef je een pointer terug die op het
 einde van de c-string staat (=voorbij het laatste karakter, dus op het nullkarakter). De procedure
 verzetNaarEersteHoofdletter(p) verzet de gegeven pointer p zodat hij wijst naar de eerste hoofdletter die vanaf zijn
 huidige positie te vinden is. Indien er geen hoofdletters meer volgen, staat p op het einde van de c-string (=voorbij
 het laatste karakter).

    int main(){
        char zus1[50] = "sneeuwWITje";
        char zus2[50] = "rozeROOD";
        const char* begin;
        const char* eind;
        begin = zus1;
        verzetNaarEersteHoofdletter(&begin);
        eind = pointerNaarEersteKleineLetter(begin);
        schrijf(begin,eind);   // schrijft 'WIT' uit
        printf("\n");
        begin = zus2;
        verzetNaarEersteHoofdletter(&begin);
        eind = pointerNaarEersteKleineLetter(begin);
        schrijf(begin,eind);   // schrijft 'ROOD' uit
        return 0;
    }

*/