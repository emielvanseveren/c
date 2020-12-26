using namespace std;
#include <iostream>
#include <fstream>

int main(){

    ifstream station("tekstbestanden/reeks1/stationnetje.txt"), paddestoel("tekstbestanden/reeks1/paddestoel.txt"); // enkel uitschrijven
    ofstream mix("tekstbestanden/reeks1/mix.txt"); // enkel inlezen

    if(mix.is_open() && station.is_open() && paddestoel.is_open()){
       cout << "Het openen van de bestanden is gelukt." << endl;
       int teller = 0;
       string line1, line2;
        getline(station, line1);
        getline(paddestoel, line2);
        while(!station.fail() && !paddestoel.fail()){
            if(teller%2){
                mix << line1 << endl;
            } else {
                mix << line2 << endl;
            }
            teller++;
            getline(station, line1);
            getline(paddestoel, line2);
        }

       if(!station.eof() && !paddestoel.eof()){
           cout << "De file bevatte fouten waardoor de failtbit op true werd gezet.";
       }

    }  else {
        cout << "Het openen is mislukt" << endl;
    }

    station.close();
    paddestoel.close();
    mix.close();
    return 0;
}
