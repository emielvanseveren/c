
#include "containers.h"

template <typename T>
class Container {
    private:
        set<T> elementen;
        string naam;        
    public:
        Container(){ };
        Container(const T[], int, const string &);        
        Container<T>& operator+=(const T &);
        Container<T> operator* (const Container<T> & ) const; //  verz1*verz2                 
  
       /*
       Indien je voor de friend operator<< ook gebruik zou willen maken van de typename T, dan moet deze operator inline ge�mplementeerd worden.
       Aangezien we alle operatoren outline willen implementeren, moet er voor (externe) friend functies een andere typename gebruikt worden (hier U).
       Bij de implementatie van deze operator mag wel opnieuw T gebruikt worden (zie verder).*/

       template<typename U> 
       friend ostream& operator << (ostream&, const Container<U>&);
};

template <typename T>
Container<T>::Container(const T data[], int n, const string & _naam):naam(_naam){
    for(int i=0; i < n ;i++ ){
        elementen.insert(data[i]);
    }        
}

template <typename T>
Container<T> Container<T>:: operator* (const Container<T> &c )const {
    Container<T> vv; //default-constructor toevoegen 
    vv.naam = "doorsnede " + naam + " en " + c.naam;
    for (const T & el : elementen){
        if(c.elementen.count(el)>0){
              vv.elementen.insert(el);        
         }
    }
    return vv;
}

template <typename T>
Container<T>& Container<T>::operator += (const T &c){
    elementen.insert(c);
    return *this;
}

template <typename T>
ostream& operator <<  (ostream& out, const Container<T>& c){
    out << "*** set " << c.naam << " ***\n" << c.elementen << endl;        
    return out;    
}
