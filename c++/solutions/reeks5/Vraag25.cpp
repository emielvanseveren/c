
#include <iostream>
#include <vector>
using namespace std;

//je kan ook containers.h includeren
template <typename T>
ostream& operator << (ostream& out, const vector<T> & v){
    out << endl << "[ ";
    for(int i=0; i<v.size()-1; i++){
        out << v[i] << " - ";
    }
    out << v[v.size()-1] << " ]" << endl;
    return out;
}

template <typename T>
class mijn_vector: public vector<T>{
    using vector<T>::vector;  //constructoren gebruiken

    public:
       void verdubbel(bool herhaal_elk_element=false);
};

template<typename T>
void mijn_vector<T>::verdubbel(bool herhaal_elk_element){
     if(herhaal_elk_element){   //a b c wordt a a b b c c
          int lengte = this->size();
          //  zonder 'this->' krijg je een foutmelding, aangezien mijn_vector een template-klasse is
          // indien er geen template gebruikt zou worden, kan je wel onmiddelijk size (en resize) oproepen.
          this->resize(2*lengte);          
          for(int i=this->size()-1; i>0; i-=2){
               (*this)[i] = (*this)[i/2];
               (*this)[i-1] = (*this)[i/2];
          }
     }
     else{ //a b c wordt 2a 2b 2c
          for(int i=0; i<this->size(); i++){
               (*this)[i] = 2 * (*this)[i];
          }
     }
}
