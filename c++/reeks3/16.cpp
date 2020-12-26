#include <map>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;


// dus het enige dat we hier eigenlijk moeten doen is een set van strings uitprinten

template <typename T>
ostream& operator<<(ostream&, unordered_set<T> &);
void zoek(string woord, vector<map<char, unordered_set<string>>> &);

int main(){

    vector<map<char, unordered_set<string>>> v(10);


    // vraag woorden op.
    cout << "Geef een reeks woorden op: ";
    string woord;
    cin >> woord;
    while(woord != "STOP"){
        if(woord.size() > v.capacity()){
            v.resize(woord.size());
        }
        v[(woord.size()-1)][woord[0]].insert(woord);
        cin >> woord;
    }

    // vraag een woord op
    string woord2;
    cout << endl << "Geef een woord op en geef alle woorden terug die evenlang zijn en beginnen met dezelfde letter: ";
    cin >> woord2;
    return 0;
}

template <typename T>
ostream& operator<<(ostream &out, unordered_set<T> &s){
    typename unordered_set<T>::iterator it = s.begin();

    while(it != s.end()){
        out << *it++ << " ";
    }

}

void zoek(const string woord, const vector<map<char, unordered_set<string>>> &v){

    // we controleren eerst of het woord wel een lengte heeft die binnen de lengte van de array past.

    if(woord.size() <= v.capacity()+1) {
        // we gaan kijken of de set een element bevat.

        if(v[(woord.size()-1)].count(woord[0]) == 1){ // Kijk of er een set bestaat voor het woord van die bepaalde lengte die begint met die bepaalde letter

            // Is dat het geval. Dan kunnen we dit itereren, we gaan niet de [] gebruiken anders gaan we dit initialiseren.
            map<char,unordered_set<string> >::const_iterator it = v[woord.size()].find(woord[0]);


        } else {
           cout << "Er bevinden zich geen woorden met die lengten in de ";
        }


    } else {
        cout << "Er bevinden zich geen woorden van deze lengte in de vector.";
    }


    cout << v[woord.size()-1][woord[0]];
}