#include <fstream>
#include <iostream>
#include <iostream>

using namespace std;

int main(){
    ifstream inv("tekstbestanden/reeks1/paddestoel.txt", ios::ate);
    char c;
    // controleren of de file open is?
    if(!inv.is_open()){
        cout << "Het bestand kon niet geopend worden." << endl;
    } else {
        // kijken naar de size van de file
        streampos size = inv.tellg();
        for(int i=1; i<size;i++){
            inv.seekg(-i, ios::end);
            inv.get(c);
            cout << c;
        }
    }

    return 0;
}

// we zullen het bestand paddestoel achterstevoren uitschrijven.


