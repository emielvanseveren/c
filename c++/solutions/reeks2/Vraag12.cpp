
#include "containers.h"
const int AANTAL = 5;
int main(){
    //oefening 1: array van vectoren
    vector<string> tabel[AANTAL];  
    tabel[1].push_back("aap"); //nog geen elementen in de vector
    tabel[1].push_back("noot");
    tabel[1].push_back("mies");
    for(int i=0; i<AANTAL; i++){
        cout << tabel[i];
    }
    cout << endl;
    //Tweede oefening - eerste oplossing: lengte gekend bij declaratie
    vector<vector<int> > v(AANTAL);
    for(int i=0; i<AANTAL; i++){
        v[i].resize(i);        
        for(int k=0; k<v[i].size(); k++) { 
            v[i][k] = 10+10*k; 
        } 
    }
    
    //Tweede oplossing: enkel plaats reserveren - gebruik push_back     
    /*	
    vector<vector<int> > v;
    v.reserve(AANTAL); 
    for(int i=0; i<AANTAL; i++){
        vector<int> w;
	w.reserve(i);  
        for(int k=0; k<i; k++){
            w.push_back(10+10*k);
        }
        v.push_back(move(w));
    }*/
    //cout << endl << v << endl; //niet omgekeerd
    for(int i=v.size()-1; i>=0; i--){
        for(int k=v[i].size()-1; k>=0; k--){
            cout << v[i][k] << " ";
        }
        cout << endl;
        //cout << v[i] << endl;  //niet omgekeerd
    }
    return 0;
}
