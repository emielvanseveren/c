#include <fstream>
#include <iostream>
using namespace std;


void vul_array_met_regelnummers(int *, ifstream &);
void extract_tekst(const int *, ifstream &)

int main(){
    ifstream nbible("tekstbestanden/reeks1/nbible.txt");
    ifstream input_regelnummers ("tekstbestanden/reeks1/regelnummers.txt");

    int regelnummers[10];
    vul_array_met_regelnummers(regelnummers, input_regelnummers);
    extract_tekst(regelnummers, nbible);

    return 0;
}

void print_verhaal(int *t)

void vul_array_met_regelnummers(int *t, ifstream &regelnummers){

    if(!regelnummers.is_open()){
        cout << "Kon het bestand niet correct openen" << endl;
    } else {
        // uitlezen van het bestand
        string line;
        int i=0;

        while(!regelnummers.fail()){;
            getline(regelnummers, line);
            t[i] = int(line);
            i++;
        }

        if(regelnummers.eof()){
            cout << "There is something wrong in the file"
        }
    }
}

void extract_tekst(int *t, ifstream &nbible){

}

void print_verhaal(int *t){

}