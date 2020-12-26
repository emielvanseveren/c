#include <iostream>
#include <set>

using namespace std;

template <typename T>
class Container {
private:
    set<T> elementen;
    string naam;

public:
    Container();
    Container(const T *, const int &, const string&);


    // Aangezien dit outline is moeten we hier gebruik maken van een andere typename. Ik begrijp dit nog niet volledig.
    template <typename U>
    friend ostream& operator<<(ostream &, const Container<U>&);

    Container<T>& operator+=(const T&);
    Container<T> operator*(const Container<T>&) const;

};

template <typename T>
ostream& operator<< (ostream &out, const set<T> &s){ // we passen de set niet aan.

    typename set<T>::const_iterator it = s.begin();
    out << "{ ";
    out << *it++;
    while(it != (s.end()--)){
        out << ", " << *it++;
    }
    out << " }" << endl;
    return out;          // zodat we kunnen chainen
}



template <typename T>
Container<T>::Container(const T *v, const int &n, const string &naam){
    this->naam = naam;
    for(int i=0;i<n;i++){
        this->elementen.insert(v[i]);
    }
}
template <typename T>
Container<T>::Container(){}

template <typename T>
ostream& operator<< (ostream &out, const Container<T> &c){
    out << "*** " << c.naam << " ***" << endl;
    out << c.elementen;
}

template <typename T>
Container<T> Container<T>::operator*(const Container<T>&c)const{
    Container<T> temp;
    temp.naam = "doorsnede " + naam + " en " + c.naam;

    // neem intersect (doorsnede) van 2
    for (const T & el : elementen){
        if(c.elementen.count(el)>0){
            temp.elementen.insert(el);
        }
    }
    return temp;
}

template <typename T>
Container<T>& Container<T>::operator+=(const T &x){
    this->elementen.insert(x);
    return *this;
}

// intersect

int main(){
    char v[]={'a','b','c','d', 'e', 'e'};
    Container<char> verz1(v,6,"groot");
    Container<char> verz2(v,2,"klein");
    verz2 += 'e';
    verz2 += 'z';
    Container<char> doorsnede = verz1*verz2;//Maak de doorsnede
    cout << verz1;
    cout << verz2;
    cout << doorsnede;
    return 0;
}
