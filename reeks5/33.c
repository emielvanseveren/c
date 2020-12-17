/*
 Gegeven het onderstaande (half-afgewerkte) hoofdprogramma.

    int main(){
        int i;
        for(i=0; i<5; i++){
            char * tekst = lees();
            printf("Ik las ***%s*** \n",tekst);
        }
        return 0;
    }

    Schrijf de functie lees() die een lijn (bestaande uit 1 of meerdere woorden) inleest vanop het klavier, en een
    nieuwe C-string teruggeeft. Je weet niet hoe lang de tekst is, maar na oproep van de functie neemt de C-string niet
    meer geheugenplaats in dan strikt noodzakelijk. Indien de tekst langer is dan 1000 karaktertekens, breek je het af
    na het 1000e teken en kuis je de resterende tekst op. Test dit uit door de constante 1000 aan te passen - uiteraard.
    Zorg er ook voor dat op het einde van de resulterende C-string geen newline-karakter staat. Vervolledig het
    hoofdprogramma met 1 regel code.
*/