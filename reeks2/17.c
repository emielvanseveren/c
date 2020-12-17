/*
    Tot nog toe werd er uitsluitend gebruikgemaakt van ééndimensionale arrays. Het gebruik en dus ook het declareren van
    meerdimensionale arrays is in C eveneens toegelaten. Iets complexer is het doorgeven van meerdimensionale arrays aan
    functies en procedures. Een ééndimensionale arrays kan op twee manieren worden doorgegeven:

    int bepaal_grootste(int array[ ], int aantal) //met rechte haken
    int bepaal_grootste(int *array, int aantal)   //pointernotatie

    Dit kan NIET veralgemeend worden voor meerdimensionale arrays. Er is immers een groot verschil tussen onderstaande
    declaraties:

    int bepaal_grootste(int matrix[ ][ ], int aant_rij, int aant_kol) //met rechte haken
    int bepaal_grootste(int **matrix, int aant_rij, int aant_kol)     //pointernotatie

    Bovendien geven ze allebei compilatiefouten. De functie met rechte haken wordt niet gecompileerd. De versie met
    pointernotatie geeft een compilatiefout bij onderstaand hoofdprogramma.

    int main(){
        int matrix[4][5]; 	//declaratie van een dubbele array met 4 rijen en 5 kolommen
        int grootste=bepaal_grootste(matrix,4,5);
    }

    Waarom de versie met pointernotatie niet aanvaard wordt in het hoofdprogramma, zal uitgelegd worden tijdens de
    theorieles over pointers. We bespreken verder enkel de versie met rechte haken.

    Een dubbele array wordt in het geheugen voorgesteld als een array van eendimensionale arrays. Hierbij worden de
    rijen van een dubbele array mooi na elkaar opgeslagen. Dus de voorstelling van de elementen van een matrix met twee
    rijen en twee kolommen is:

    element[0][0]   element[0][1]   element[1][0]   element[1][1]

    Opeenvolgende adressen bevatten dus opeenvolgende elementen.

    Om in de functie/procedure met dubbele vierkante haken te kunnen werken moet de compiler kunnen achterhalen waar het
    element te vinden is. In de vorige paragraaf werd gesteld dat het adres van het element[1][1] terug te vinden is op
    het startadres vermeerderd met drie. Je moet dus de elementen van de eerste rij voorbij om dan één positie verder
    het gevraagde element te bereiken. Algemeen kan het adres van het element element[i][j] berekend worden door het
    startadres te vermeerderen met de i * aantal_kol + j.

    Dit wordt opgelost door ook het aantal kolommen op te geven in de parameter die de dubbele array voorstelt
    (als letterlijke waarde of als constante):

    int bepaal_grootste(int matrix[ ][5], int aant_rij, int aant_kol)

    Opdracht:
    Gebruik matrices met maximaal N rijen en N kolommen - gebruik een constante voor N. Je mag veronderstellen dat het aantal rijen en kolommen steeds kleiner is dan deze constante (moet je dus niet controleren).
    Schrijf onderstaande proceduren en test ze uit in een hoofdprogramma.

    De procedure lees_matrix(matrix, aant_rij, aant_kol) leest een matrix van aant_rij * aant_kol gehele getallen in.
    De procedure print_matrix(matrix, aant_rij, aant_kol) schrijft een matrix van gehele getallen mooi uit (rij per rij naar het scherm schrijven: 1 lijn is 1 rij).
    De procedure transponeer(matrix, dimensie) transponeert een vierkante matrix. Bij het transponeren worden de rijen en de kolommen gewisseld. De rijen worden dus de kolommen en vice versa.
    De procedure vermenigvuldig_matrix(product, matrix1, matrix2, dimensie) vermenigvuldigt twee vierkante matrices van gehele getallen met elkaar. Je mag veronderstellen dat beide matrices even groot zijn.
 *
 */

print_matrix()
lees_matrix()
transponeer()
vermenigvuldig_matrix()


int main(){
   return 0;
}
