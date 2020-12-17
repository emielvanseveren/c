/*
 Gegeven een gedeelte van een hoofdprogramma:

    int main() {
        int getallen_ja[]   = {1,2,3,4,5,6,7,8,9,10,10,11};
        int getallen_neen[] = {1,2,1,2,1,2,1,2,1,2,3,4,5};
        char* woorden_ja[]  = {"leentje","leerde","lotje","lopen","lopen","langs","de","lindelaan"};
        char* woorden_neen[] = {"wie","goed","doet","goed","ontmoet"};

        // voor elk van deze vier arrays wordt er opgeroepen:
        if(array_bevat_dubbels_na_elkaar(........)){
            printf("Deze array bevat dubbels na elkaar");
        }
        else{ printf("Deze array bevat geen dubbels na elkaar");}
        return 0;
}

Schrijf één logische functie array_bevat_dubbels_na_elkaar. Deze functie bepaalt voor een array met elementen van een
 niet nader bepaald type, of er ergens in die array twee elementen vlak na elkaar staan die gelijk zijn. In ons
 voorbeeld zal dat wel zo zijn voor de arrays getallen_ja en woorden_ja, maar niet voor de arrays getallen_neen en
 woorden_neen. Schrijf ook de nodige hulpfuncties om ervoor te zorgen dat je het hoofdprogramma volledig werkend krijgt.
 Tenslotte vul je het hoofdprogramma aan: roep de functie array_bevat_dubbels_na_elkaar vier keer op (voor elke
 gedeclareerde array 1 keer) en ga na of het programma de juiste output oplevert.
