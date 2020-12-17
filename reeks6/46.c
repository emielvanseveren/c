/*
    Schrijf onderstaande functies en procedures, waarbij je enkel gebruik maakt van bitoperatoren.
    Gebruik een typedef zodat je unsigned int korter kan noteren als uint.

    - De functie bit_i(uint x, int i) geeft het gehele getal 0 of 1 weer (type int), naargelang de inhoud van bit i van
      het getal x. Merk op: we zullen de laatste, minst significante bit, met het volgnummer 0 aanduiden.
      Test uit met enkele getallen.

    - Schrijf een procedure schrijf(uint x, int lengte) die gebruik maakt van bitoperatoren om het getal x uit te
      schrijven. Bij dit uitschrijven zullen er slechts lengte bits uitgeschreven worden (de minst significante). Je mag
      hierbij gebruik maken van de voorgaande functie bit_i. Let op: maak groepjes van 4 door tussen 4 bits steeds een
      spatie toe te voegen. Test uit.

    - Schrijf de functie eenbit(int i) die de unsigned int teruggeeft die slechts één bit heeft aanstaan, nl. die met
      volgnummer i.

    - Schrijf de functie aantal_eenbits(uint x) die het aantal bits teruggeeft dat aanstaat in de binaire voorstelling
      van x. Werk niet via de functie bit_i(x,i), dat is inefficiënt.

    - Schrijf de functie bit_i_aangezet(uint x, int i) die de unsigned int teruggeeft die gelijk is aan het gegeven
      getal x op hoogstens één bit na: de bit met volgnummer i staat aan.

    - Schrijf de functie bit_i_uitgezet(uint x, int i) die analoog werkt aan bovenstaande functie. Nu staat de i-de bit
      van het resultaat zeker uit.

    - Schrijf de functie bit_i_gewisseld(uint x, int i) die analoog werkt aan bovenstaande functie. Nu wordt de i-de bit
      veranderd van aan naar uit (of omgekeerd).

    - Schrijf de logische functie zijn_gelijk(uint x, uint y) die nul teruggeeft indien de parameters gelijk zijn.
      De ==-operator mag niet gebruikt worden.

    - Schrijf de logische functie is_even(uint x) die 1 teruggeeft als het getal even is, anders 0. Gebruik enkel
      bitoperatoren, zelfs geen minteken.

 */
