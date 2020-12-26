using namespace std;
#include <iostream>
#include <fstream>
int main(){

    ifstream inv;
    inv.open("tekstbestanden/reeks1/lord.txt");

    // controleren of de file open is
    if(inv.is_open()){
        cout << "De file is succesvol geopend." << endl;
        int frequenties[26] = {0};
        while(!inv.fail()){
            char letter;
            inv >> letter;
            // we zijn enkel geïnteresseerd in kleine letters.
            if(letter >= 'a' && letter <= 'z'){ frequenties[letter-'a']++;}
        }

        for(int i=0; i<26;i++){
            char letter = 'a'+i;
            cout << letter << ": " << frequenties[i] << endl;
        }

    } else {
        cout << "Kon het bestand niet vinden." << endl;
    }
    inv.close();
}