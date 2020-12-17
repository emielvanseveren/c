/*
    Bij het berekenen van de afstand tussen twee punten wordt doorgaans gebruikgemaakt van de Euclidische afstand.
    Aangezien de Euclidische afstand eigenlijk de afstand in vogelvlucht is, is deze afstand bij enkele praktische
    problemen niet de meest bruikbare. Denk bijvoorbeeld aan het wegennet waarbij de afstand in vogelvlucht niet
    noodzakelijk de kortste afstand hoeft te zijn. Bij deze vraag gaan we - naast de euclidische afstand - twee andere
    manieren beschouwen om de afstand tussen twee punten te berekenen.

    - De Manhattan-afstand dankt zijn naam aan het typische stratenpatroon van Manhattan waar alle straten ofwel
      loodrecht op elkaar ofwel evenwijdig aan elkaar lopen. In dit geval wordt de afstand gegeven als de som van het
      verschil van de x-coördinaten en het verschil van de y-coördinaten. Dit komt overeen met de weg die je zou afleggen
      om van het ene punt naar het andere punt te gaan als je enkel evenwijdig met de x-as en de y-as zou mogen wandelen.

    - De Chebyshev-afstand of de schaakbordafstand dankt zijn naam aan het feit dat op een discreet rooster deze afstand
      overeenkomt met het aantal zetten dat de koning uit het schaakspel nodig heeft om van het ene punt naar het andere
      punt te gaan. De afstand wordt in dit geval gegeven door het maximum van het verschil van de x-coördinaten en het
      verschil van de y-coördinaten.

    Voorzie het volgende:

    - Definieer een struct met als naam punt en twee attributen van het type double voor het bijhouden van de x- en de
      y-coördinaat.

    - Schrijf drie functies die respectievelijk de Euclidische, de Manhattan en schaakbordafstand berekenen. Elk van
      deze functies geeft de afstand als reëel getal terug.

    - Schrijf een functie bepaal_max_afstand(punten, aantal, functie) die van een gegeven array met punten de maximum
      afstand bepaalt. De functie waarmee de afstand moet worden berekend, wordt als derde parameter meegeven. De
      maximumafstand wordt als reëel getal teruggegeven.
    - Schrijf een hoofdprogramma dat aan de gebruiker vraagt hoeveel punten er zullen worden ingegeven. Het programma
      leest exact het aantal opgegeven punten en stopt die in een array die net voldoende plaats heeft om alle punten
      bij te houden. Het inlezen gebeurt punt per punt en dat volgens het patroon x , y. De gebruiker geeft dus de
      x-coördinaat gevolgd door een spatie gevolgd door een komma gevolgd door een spatie en gevolgd door de
      y-coördinaat. Het programma schrijft vervolgens de maximum Euclidische, maximum Manhattan en maximum
      schaakbordafstand naar het scherm.
*/