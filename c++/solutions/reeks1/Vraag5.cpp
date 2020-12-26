
#include <iostream>
#include <string>
using namespace std;

/**************** STRUCT EN INITIALISATIE / PRINT VAN STRUCT **************/

struct persoon{
     string naam;
     int leeftijd;
     int lengte;
};

void initialiseer(persoon & p, const string & naam, int leeftijd, int lengte){
     p.naam = naam;
     p.leeftijd = leeftijd;
     p.lengte = lengte;
}

void print(const persoon& p){ //geen kopie nemen
    
     cout << p.naam << " (" << p.leeftijd << " jaar, " << p.lengte  << "cm" ")"; 
}

/****************** FUNCTIE 'grootte' VOOR VERSCHILLENDE TYPES********/

double grootte(double x){
     return x;
}

int grootte(const string & woord){
     return woord.size();
}

int grootte(const persoon & p){
     return p.leeftijd;
}

/* // alternatief: grootte van persoon wordt bepaald door zijn/haar lengte
int grootte(const persoon & p){
     return p.lengte;
}*/

/* // alternatief: grootte van persoon wordt bepaald door lengte van zijn/haar naam
int grootte(const persoon & p){
     return grootte(p.naam);
}*/

/******************* FUNCTIE 'grootste' VOOR VERSCHILLENDE TYPES VAN ARRAYS ***/

template <typename T>
T grootste(const T * array, int lengte){
     T gr = array[0];
     for(int i=1; i<lengte; i++){
          if(grootte(gr) < grootte(array[i])){
               gr = array[i];
          }
     }
     return gr;
}

/************* Aanvullingen in main*********************************************/
     persoon personen[3];
     initialiseer(personen[0],"samuel",12,152);
     initialiseer(personen[1],"jente",22,181);
     initialiseer(personen[2],"idris",42,173);
     persoon gr = grootste(personen,3);
     print(gr);
     

