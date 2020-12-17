/*
 Loop niet te snel in deze oefeningen, volg de opdracht nauwgezet. (Dus geen functies/procedures waar het niet staat.)
 - Definieer een struct Deeltal met drie velden: waarde, aantal_delers en delers. De waarde zal een geheel getal bevatten;
 aantal_delers geeft aan hoeveel delers (tussen 1 en waarde-1) dit getal heeft; delers is een pointer naar int(s), hier
 zullen de delers te vinden zijn.

 - Werk dit deel uit in het hoofdprogramma. Maak lokaal een variabele van het type
 Deeltal aan. Vul op de volgende regels de drie velden van deze variabele in: waarde wordt 6, aantal_delers wordt 3 en
 de drie delers zijn 1, 2 en 3. Gebruik hiervoor geen lus.

 - Schrijf een procedure schrijf_ints(...) die een array van ints meekrijgt, en deze gehele getallen naast elkaar
 uitschrijft met een liggend streepje tussen. Gebruik de bovenstaande procedure in de procedure schrijf_deeltal(d) die
 een deeltal (=getal en zijn delers) uitschrijft. Voor het getal 6 zou er komen:

    6  1-2-3

Heb je in de schrijf-procedure(s) een kopie gemaakt, of ben je zuiniger geweest?

- Schrijf de functie aantal_delers_van(x) die telt hoeveel delers het geheel getal x heeft.
  (Overloop hiervoor alle getallen van 1 tot en met x/2.)

- Schrijf een functie delers_van(x,aantal) die een pointer teruggeeft naar een array die alle delers bevat van het
  geheel getal x. De parameter aantal bevat het aantal delers van x. Test uit door in je hoofdprogramma de delers van 6
  niet handmatig in te geven.

- Schrijf een procedure lees_deeltal(g) die de velden van een deeltal invult: het veld waarde wordt hierbij ingelezen
  vanop het toetsenbord; de andere velden worden automatisch berekend (gebruik de voorgaande functies).

- Schrijf een procedure lees_deeltallen(t,aantal) die een aantal deeltallen inleest en bijhoudt in de array t.
 Gebruik bovenstaande procedure (uiteraard).

- Schrijf een procedure schrijf_deeltallen(t,aantal) die een array t van deeltallen uitschrijft. %Dit kan op Overloop de
  array met indexering, en gebruikt een hulpprocedure om elk deeltal apart uit te schrijven. Test voorgaande procedures
  uit in een hoofdprogramma: lees één deeltal in en schrijf het uit. Vraag de gebruiker nadien om een aantal op te geven,
  waarna je hem/haar exact zoveel deeltallen vraagt. Deze schrijf je ook uit.

- Schrijf een functie zoek(waarde, t, aantal) die een pointer teruggeeft naar het deeltal met waarde waarde (type int)
  in de array t van deeltallen. (Wat geef je terug indien het gezochte niet aanwezig is?) Denk na over de types in de
  parameterlijst.

- Schrijf een of meerdere procedures die memory-leaks voorkomen. Aantal en aard van de parameters bepaal je zelf. Tip:
  voor je de geheugenplaats van een deeltal weer vrijgeeft aan het geheugen, schrijf je de waarde van dat deeltal uit.
  Zo kan je zelf nakijken of alle deeltallen zijn vrijgegeven.
*/