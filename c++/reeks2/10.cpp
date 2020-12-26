#include <memory>
#include <iostream>
using namespace std;

void schrijf(const unique_ptr<string> * s, int aantal){
    cout << endl;
    for(int i=0; i < aantal-1; i++){
        cout << s[i] << " - ";
    }
    cout << s[aantal-1];
}

void verwijder(unique_ptr<string> *s, int aantal, int volgnr){
    for(int i = volgnr; i < aantal-1; i++){
        s[i] = move(s[i+1]);
    }
    (*s)[aantal-1] = "";  //laatste element leeg maken
}

int main(){

    // we moeten hier werken met unique pointers. Zodat gewoon de pointers gewijzigd worden en de strings niet overgekopieerd hoeven te worden.
    unique_ptr<string> namen[]={
            make_unique<string>("Rein"),
            make_unique<string>("Ada"),
            make_unique<string>("Eppo"),
            make_unique<string>("Pascal"),
            make_unique<string>("Ilse")
    };

    schrijf(namen,5);
    verwijder(namen,5,1);
    schrijf(namen,5); //alle namen tonen
    return 0;
}