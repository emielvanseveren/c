/*
 In onderstaand hoofdprogramma wordt er automatisch een stijgend gesorteerde lijst aangemaakt, waar dubbele elementen in kunnen zitten.

    int main(){
        srand(time(NULL));
        knoop * l = maak_gesorteerde_lijst_automatisch(10,100);
        print_lijst(l);
        printf("\nnu worden dubbels verwijderd: \n");
        verwijder_dubbels(...); (aanvullen)
        printf("\nna verwijderen van dubbels: \n\n");
        print_lijst(l);
        return 0;
}

    Implementeer:
    de functie maak_gesorteerde_lijst_automatisch(aantal,bovengrens). De eerste parameter geeft aan hoeveel elementen de
    lijst moet bevatten. De tweede parameter geeft aan wat het grootste getal kan zijn. Een tip: bouw de lijst op door
    vooraan telkens een iets kleiner getal dan het vorige toe te voegen. Daarvoor genereer je een random getal uit de
    verzameling {0,1,2} en trek je dit getal af van het vorige toegevoegde getal (of van het getal bovengrens bij het
    toevoegen van de eerste knoop).

    de procedure verwijder_dubbels(...) die alle dubbels uit de gelinkte lijst verwijdert. Als enige parameter geef je
    de gelinkte lijst mee.

    Vul het hoofdprogramma verder aan zoals het hoort.
*/