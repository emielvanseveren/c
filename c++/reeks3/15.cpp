#include <map>
#include <iostream>
#include <unordered_set>

using namespace std;

int main(){

    // map met chars en woorden
    map<char,unordered_set<string>> m;
    cout << "Geef een aantal woorden in, indien je wilt stoppen type STOP: ";
    string woord;
    while(woord !="STOP"){
        cin >> woord;
        while(getchar() != '\n'); // buffer leegmaken voor zekerheid.
        m[woord[0]].insert(woord);
    }

    cout << endl << "Geef een letter in waarvan je het aantal woorden die beginnen met die letter wilt weten";
    char letter;
    cin >> letter;
    cout << "Aantal wooren met letter " << letter << ": " << m[letter].size();

    return 0;
}
