#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    int i = 5;
    int j = 8;
    unordered_set<string> s;
    s.insert("Jan");    // 1
    s.insert("Jari");   // 2
    s.insert("Jonas");  // 3
    s.insert("Roers");  // 4
    s.insert("Emiel");  // 5
    s.insert("Ries");   // 6
    s.insert("Alissa"); // 7
    s.insert("Astrid"); // 8
    s.insert("Niek");   // 9
    s.insert("Jeroen"); // 10

    int teller = 1;
    for(string naam : s){
        if(teller >=i && teller <= j){
           cout << naam << " ";
        }
        teller++;
    }
    return 0;
}

// Waarom unordered set. We veronderstellen hier dat de woorden niet dubbel mogen voorkomen? Anders zou het ook een vector mogen zijn.
