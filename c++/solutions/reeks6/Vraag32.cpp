
#include "figuren.h"
#include <memory>

class Blokkendoos : vector<unique_ptr<Figuur>>{
  private:
     unique_ptr<Figuur> max_opp;
     void schrijf(ostream&)const;
  public:
     Blokkendoos(const string & bestandsnaam);
     unique_ptr<Figuur> geef_figuur_met_grootste_oppervlakte();     
     void push_back(unique_ptr<Figuur> & figuur);          
     friend ostream& operator << (ostream& out, const Blokkendoos& l){
          l.schrijf(out);
          return out;     
     }     
};

void Blokkendoos::push_back(unique_ptr<Figuur> & figuur){
     if(max_opp==nullptr){
          max_opp = move(figuur);     
     }
     else{
          vector<unique_ptr<Figuur>>::push_back(move(figuur));
          if(max_opp->oppervlakte() < operator[](size()-1)->oppervlakte()){
               max_opp.swap(operator[](size()-1));
          }
     }
}

Blokkendoos::Blokkendoos(const string & bestandsnaam){
     unique_ptr<Figuur> up;
     ifstream input(bestandsnaam);
     string soort;
     while (input >> soort){
          if (soort == "rechthoek"){
               double lengte, breedte;
               input >> lengte >> breedte;
               up = make_unique<Rechthoek>(lengte,breedte);     
          }
          else if(soort == "vierkant"){
               double zijde;
               input >> zijde;
               up = make_unique<Vierkant>(zijde);       
          }   
          else { //soort == "cirkel"
               double straal;
               input >> straal;
               up = make_unique<Cirkel>(straal);      
          }
          push_back(up);      
     }    
}
          
void Blokkendoos::schrijf(ostream& out)const{
    for(const unique_ptr<Figuur> & ptr : *this){
       out << *ptr << endl;     
    }    //kan ook met gewone for-lus
    out << "grootste figuur: " << *max_opp;
}

unique_ptr<Figuur> Blokkendoos::geef_figuur_met_grootste_oppervlakte(){
     int index_tweedegrootste = 0;
     for(int i=1; i<size(); i++){
          if(operator[](i)->oppervlakte() > operator[](index_tweedegrootste)->oppervlakte()){
               index_tweedegrootste = i;
          }
     }
     
     operator[](index_tweedegrootste).swap(operator[](size()-1));
     // nu staat tweede grootste achteraan; die moet naar max_opp verhuizen
     unique_ptr<Figuur> hulpptr = move(max_opp);
     //max_opp.swap(operator[](size()-1)); of gebruik (*this)[i]-notatie:
     max_opp.swap((*this)[size()-1]);
     resize(size()-1);
     return move(hulpptr);
}

int main() {
     Blokkendoos blokkendoos("figuren.txt");
     cout << endl << "ALLE FIGUREN: " << blokkendoos << endl;
     
     cout << endl << "DE 3 GROOTSTE, van groot naar klein: " << endl;
     for(int i=0; i<3; i++){
          cout << "figuur met grootste opp:    " << *blokkendoos.geef_figuur_met_grootste_oppervlakte() << endl;
     }

     cout << endl << "DE NIEUWE BLOKKENDOOS BEVAT ALLEEN NOG DE KLEINERE FIGUREN: ";
     cout << blokkendoos << endl;
     return 0;     
}

