
#include <stdexcept>

class bestand_niet_lang_genoeg : public invalid_argument{
  public:
     bestand_niet_lang_genoeg(const string & message):
          invalid_argument(message) {}
};

string regel_uit_bestand(const string & bestandsnaam, int nr){
     ifstream invoer;
     invoer.open(bestandsnaam);
     if(!invoer.is_open()){
          throw bestandsnaam+" kon niet geopend worden";
     }
     string woord,magweg;
     invoer >> woord;
     getline(invoer,magweg); // rest van de regel na 'VERHAAL'     
     if(woord != "VERHAAL"){
          throw woord.c_str();
     }
     string zin;
     int teller = 0;
     while(teller<nr && getline(invoer,zin)){
          teller++;
     }
     if(invoer.fail()){
          throw bestand_niet_lang_genoeg( 
              bestandsnaam + " heeft geen " + to_string(nr) + " regels.");
     }
     return zin;     
}

/********** for-lus in Main aanpassen ********************/

 for(int i=0; i<bestandsnamen.size(); i++){
      try{               
           cout << regel_uit_bestand(bestandsnamen[i]+".txt",nrs[i]) 
                << endl;
      }
      catch(const char* x){
           eerste_woorden += x;
           eerste_woorden += "  ";
      }
      catch(const string &s){
           bestanden_niet_gevonden += s + "\n";
      }
      catch(bestand_niet_lang_genoeg bnlg){
           bestanden_niet_lang_genoeg += bnlg.what();
      }
 }
  
