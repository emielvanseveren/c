
Hier vind je een mogelijke oplossing. Er zijn zeker ook andere oplossingen mogelijk, waarbij er gebruik gemaakt worden van andere containers.

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;

/****************** Versie zonder procedures ***********************/
int main(){
     map<int,string> tekst_op_regelnr;
     vector<int>volgorde_regelnummers;
     ifstream input("regelnummers.txt");
     if(!input.is_open()){
          cout << "bestand niet gevonden.... " << endl;
     }
     else{
          int nr;
          while(input>>nr){
               tekst_op_regelnr[nr]=""; //nr toevoegen aan sleutelverzameling
               volgorde_regelnummers.push_back(nr);               
          }  
          ifstream input2("nbible.txt");         
          if(!input2.is_open()){
               cout << "bestand niet gevonden.... " << endl;
          }
          else{
               int tel=1;
               string lijn;
               while(getline(input2,lijn)){
                    if ( tekst_op_regelnr.count(tel)>0){
                         tekst_op_regelnr[tel]=lijn;
                    }
                    tel++;
               }

               for(int i=0;i<volgorde_regelnummers.size();i++){     
                    cout <<  tekst_op_regelnr[volgorde_regelnummers[i]] << endl;
               }
          }
          return 0;
     }
}
//alternatief: nr in aparte set stoppen (niet in de sleutelverzameling van de map)
/****************** Versie met procedures ***************************/
void regelnummers_opslaan(map<int,string> & m, vector<int> & v, 
           const string & bestand){
     ifstream input;
     input.open(bestand);
     if(!input.is_open()){
          cout << "bestand niet gevonden.... " << endl;
     }
     else{
          int nr;        
          while(input>>nr){
               m[nr]=""; 
               v.push_back(nr);
          }
     }
}

void tekstregels_opzoeken(map<int,string> & m, const string & bestand){
     ifstream input;
     input.open(bestand);
     if(!input.is_open()){
          cout << "bestand niet gevonden.... " << endl;
     }
     else{  //(1) zie laatste opmerking
          string lijn;
          int nr=1;        
          while(getline(input,lijn)){
               if(m.count(nr)==1){
                    m[nr]=lijn;
               }
               nr++;
          }
     }
}

//naar bestand weggeschreven
void regelnummers_vervangen(const map<int,string> & m, const vector<int> & v, 
         const string & bestandsnaam){
     ofstream output(bestandsnaam.c_str());
     for(int i=0;i<v.size();i++){
          map<int,string>::const_iterator it=m.find(v[i]);
          output << endl << it->second;
     }
}

int main(){
     vector<int> volgorde_regelnummers;
     map<int,string> tekst_op_regelnr;
     regelnummers_opslaan(tekst_op_regelnr,volgorde_regelnummers,"regelnummers.txt");
     tekstregels_opzoeken(tekst_op_regelnr,"nbible.txt");
     regelnummers_vervangen(tekst_op_regelnr,volgorde_regelnummers,"verhaal.txt");
     cout << "Het resultaat is te zien in het bestand 'verhaal.txt'." << endl;    
     return 0;
}

/* OPGELET! hieronder staat een minder goed alternatief voor de methode regelnummers_vervangen.
  In die procedure kan je echter niet de gewenste 'veiligheid' inbouwen zodat de
  map niet kan veranderd worden:  
  hier kan geen const bij map staan, want de aanroep 'm[...]' zou eventueel iets 
  kunnen wijzigen aan de map !! (zie compilermeldingen als je toch const toevoegt)

  void regelnummers_vervangen(map<int,string> & m, const vector<int> & v, const string & bestandsnaam){
      ofstream output(bestandsnaam.c_str());
      for(int i=0;i<v.size();i++){
          output << endl << m[v[i]];
      }
  }  */

/********************  Inlezen stoppen bij laatste lijn ************/
//Vervang de code in (1) door:
    int tel=1;  
    string lijn;
    map<int,string>::const_iterator it = m.begin();
    while (it != m.end()){
         while(tel<=it->first){                  
              getline(input,lijn);
              tel++;
         }
         it->second=lijnS;
         it++;                                      
    }



