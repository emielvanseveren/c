using namespace std;
#include <iostream>


typedef struct Persoon Persoon;
struct Persoon {
    string naam;
    int leeftijd, lengte;
};

template <typename T1>
T1 grootste(T1 *, int);
void initialiseer(Persoon&, string, int, int);
void print(Persoon &);

// parameter overloading.
double grootte(double x){ return x; }
int grootte(const string & woord){ return woord.size(); }
int grootte(const Persoon & p){ return p.leeftijd; }


int main(){
    double getallen[5] = {5.5,7.7,2.2,9.9,9.8};
    string woorden[3] = {"geloof","hoop","de liefde"};
    cout << "Grootste getal is: " <<  grootste(getallen,5) << endl;
    cout << "Het grootste woord is: " << grootste(woorden,3) << "." << endl;


    // array van 3 personen
    Persoon personen[3];
    initialiseer(personen[0], "niek", 15, 130);
    initialiseer(personen[1], "michiel", 83, 132);
    initialiseer(personen[2], "emiel", 25, 190);

    for(int i=0;i<3;i++){ print(personen[i]);}

    // Persoon grootste = grootste(personen, 3);
    // print(grootste);
    return 0;
}


template <typename T1>
T1 grootste(T1 *t, int lengte){
    T1 max = t[0]; // ZET DIT ALTIJD GELIJK AAN MINIMUM VALUE
    for(int i=0;i<lengte;i++){
        if(grootte(t[i]) > grootte(max)){
            max = t[i];
        }
    }
    return max;
}

void initialiseer(Persoon &p, string naam, int leeftijd, int lengte){
    p.naam = naam;
    p.leeftijd = leeftijd;
    p.lengte = lengte;
}

void print(Persoon &p){
    cout << "Naam: " << p.naam << endl << "Leeftijd: " << p.leeftijd << endl << "Lengte: " << p.lengte<< endl << endl;
}

