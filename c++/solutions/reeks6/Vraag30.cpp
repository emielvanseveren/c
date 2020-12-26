
void lees(const string &bestandsnaam, map<char,set<string> > &m){
     string woord; //geen auto - geen initialisatie - ook niet gewenst
     ifstream inv(bestandsnaam);  //geen auto: inv wordt niet herkend als ifstream
     inv>>woord;
     while(!inv.fail()){
          cout << woord << endl;
          m[woord[0]].insert(woord);  
          inv >> woord; 
     }    
}

string langstewoord(char letter, const map<char,set<string> > &m){
     string langste; //geen auto - geen initialisatie - ook niet gewenst
     auto it_find = m.find(letter);  //hier wel oke
     if(it_find != m.end()){    
          auto it = it_find->second.begin();  //hier ook toegelaten
          while (it != it_find->second.end()){
               if (it->size() > langste.size()){
                    langste = *it;
               }
               it++;
          }
     }
     return langste;
}

int main(){
     map<char,set<string> > m; //geen auto - geen initialisatie
     string naam;   //geen auto - geen initialisatie - ook niet gewenst
     cout << "Bestandsnaam: ";
     cin >>  naam;
     lees(naam, m);
     char letter = 's';  // auto kan, maar is niet gewenst
     cout << "Het langste woord met de letter " << letter << " is: ";       
     cout << langstewoord(letter,m);
     return 0;
}

