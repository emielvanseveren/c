/*
    Dit is een vervolg op oefening 12. Gegeven onderstaand hoofdprogramma:

    #include <stdio.h>
    int main(){
        char letters [] = {'p','o','r','g','o','e','d','o','i','e','o','k','i',':','a','-','t','('};
        const char *p = letters;

        schrijf_aantal(letters+3,4);
        printf("\n");
        schrijf(p+10,p+12);

        return 0;
    }

    - Kan je de lengte van de array berekenen via de pointer p? Ga na dat de geheugenruimte, ingenomen door een pointer
      altijd gelijk is (onafhankelijk van het type waarnaar de pointer verwijst).

    - Schrijf de procedure schrijf_aantal die het aantal gevraagde letters uitschrijft vanaf de pointer opgegeven in de eerste parameter.

    - Schrijf de procedure schrijf(begin,eind) die de letters uitschrijft die te vinden zijn tussen de plaats waar de
      pointers begin en eind naar wijzen. (Laatste grens niet inbegrepen; je mag er vanuit gaan dat beide pointers wijzen naar
      elementen in dezelfde array van karakters, en dat begin < eind .) Maak hierbij verplicht gebruik van schuivende
      pointers (gebruik dus geen indexering).

*/