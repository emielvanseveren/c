
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template <typename T>
class Doos {
    public:
        Doos();
        Doos(const Doos<T> &);
        Doos<T>& operator=(const Doos<T> &);
        ~Doos();
 
   private:
        vector<T> b;
        int n;
        Doos<T> *c;
        unique_ptr<string> *d;
        void copy(const Doos<T> &); //vermijd duplicated code
};

template <typename T>
class Schijf {
    public:
        Schijf();
        Schijf(const Schijf<T> &);
        Schijf<T>& operator=(const Schijf<T> &);
        ~Schijf();

    private:
        Doos<T> *a;
};

/******************************* SCHIJF *****************************/

template<typename T>
Schijf<T>::Schijf():a(nullptr){}  //initializer list

template<typename T>
Schijf<T>::Schijf(const Schijf<T> &schijf){
     if(schijf.a){ //geen nullptr
         a=new Doos<T>(*schijf.a);
     }
     else
         a=nullptr;     
}

template<typename T>
Schijf<T>::~Schijf(){
     delete a;
}

template <typename T>
Schijf<T>& Schijf<T>::operator=(const Schijf<T> &schijf){
     if (this!=&schijf) {
          delete a;
          a=nullptr;
          if (schijf.a!=nullptr){
               a=new Doos<T>(*schijf.a);
          }
     }
     return *this;            
}

/********************************* DOOS **************************/

template<typename T>
Doos<T>::Doos() : n(0), c(nullptr), d(nullptr){} //initializer list
    
template<typename T>
void Doos<T>::copy(const Doos<T> &doos){
    b = doos.b;  //vector kopieren                
    if(doos.c){
        c = new Doos<T>(*doos.c);
    }
    else 
        c = nullptr;
    n = doos.n;
    if (n > 0){
        d = new unique_ptr<string>[n]; //n elementen in de array
        // de elementen van de array d moeten ingevuld worden.
        for(int i=0; i<n; i++){
            if(doos.d[i]) {
               d[i] = make_unique<string>(*doos.d[i]);
            }
            else 
               d[i] = nullptr;
        }
    }
    else
        d = nullptr;
}     

template<typename T>
Doos<T>::Doos(const Doos<T> &doos) {
    copy(doos);
}

template<typename T>
Doos<T>& Doos<T>::operator=(const Doos<T> &doos){
     if (this != &doos) {
          delete c;                              
          delete[] d;          
          copy(doos);
     }
     return *this;
}

template<typename T>
Doos<T> :: ~Doos(){
     delete c;
     delete[] d;
}

