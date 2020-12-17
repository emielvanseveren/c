/*
 Om een idee te hebben van wat er zoal gevraagd kan worden op de test van C, volgt hieronder een ongecensureerde
 testvraag. Oplossingen worden niet gepubliceerd. Uiteraard heeft het geen zin aan deze oefening te beginnen als je
 alle vorige niet onder de knie hebt. Veel puzzelplezier!

Gegeven een tekst zoals:

De Dit Er zon is was schijnt een eens door goede een het zin. prinses. raam. STOP

Als je deze zin woord voor woord inleest en elk woord beurtelings in één van drie gelinkte lijsten stopt, krijg je volgende drie gelinkte lijsten:

    De zon schijnt door het raam.
    Dit is een goede zin.
    Er was eens een prinses.

Schrijf een functie geef_array_van_lijsten(int aantal) die een opsomming van woorden (afgesloten met STOP) inleest en
beurtelings in één van 'aantal' gelinkte lijsten stopt. De array (met lengte 'aantal') die deze lijsten bevat, wordt
teruggegeven. De woorden worden ingelezen vanop het scherm en zullen niet meer dan 80 letters bevatten, maar neem niet
meer geheugenplaats in dan nodig.

Let op: om netjes bij te houden waar je in de gelinkte lijsten gebleven bent, houd je een array bij van precies 'aantal'
hulppointers, die ervoor zorgen dat je elke gelinkte lijst achteraan kan uitbreiden met een nieuwe knoop, zonder telkens
de reeds opgebouwde lijsten van voor af aan te moeten doorlopen.
*/
