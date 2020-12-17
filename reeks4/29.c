/*
 Intialiseer in het hoofdprogramma volgende arrays:

    char * namen[] = {"Evi","Jaro","Timen","Youri","Ashaf","Jennifer"};
    int leeftijden[] = {21,30,18,14,22,19};
    double scores[] = {0.5,1.6,8.2,-2.4};

    We willen de elementen van deze arrays uitschrijven, gescheiden door een leesteken naar keuze. Omdat de arrays elk
    van een ander type zijn, zouden we drie keer bijna dezelfde code moeten schrijven: een lus om de elementen van een
    array te overlopen en die uit te schrijven.

    Dat dubbel werk kunnen we vermijden. Ga daarvoor als volgt te werk:

    Schrijf de procedure void schrijf_array(const void * t, int aantal, int grootte, char tussenteken, void (*schrijf)(const void*))
    die de eerste aantal elementen uit de array t uitschrijft. Elk koppel elementen wordt gescheiden door het opgegeven
    tussenteken. De parameter grootte bevat de grootte van het type dat uitgeschreven moet worden. De parameter schrijf
    is een pointer naar een passende uitschrijfprocedure.

    Schrijf drie procedures schrijf_cstring, schrijf_int en schrijf_double die alledrie één parameter van een
    pointertype meekrijgen en één element uitschrijven.

    Vul het hoofdprogramma aan zodat volgende output produceert:

        21,30,18,14,22,19

        Evi;Jaro;Timen;Youri;Ashaf;Jennifer

        0.5~1.6~8.2~-2.4

    Belangrijke voetnoot met het oog op de labotest. Zorg dat je deze oefening helemaal binnenste buiten draait en
    jezelf grondig bevraagt over het hoe en waarom van welke parametertypes, sterretjes, haakjes,... Een dergelijke
    vraag komt dikwijls op testen voor, waarbij je soms ook zelf de hoofding van de procedure moet schrijven.
 */