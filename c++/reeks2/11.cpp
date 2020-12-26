#include <iostream>
#include <vector>
using namespace std;

struct Persoon {
    string naam;
    int leeftijd, lengte;
};

ostream& operator<<(ostream& out, const Persoon & p){ out << p.naam << " (" << p.leeftijd << " jaar, " << p.lengte << "cm" ")"; return out; }

template<typename T>
void print(vector<T>&);

template<typename T>
ostream& operator<<(ostream&, const vector<T>&);




int main(){
    Persoon p = {"jan", 15, 180};
    cout << p << endl;

    // dit is een vector van gehele getallen.
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(8);
    // print(v);
    // cout << v;

    // vector van vectoren van ints
    vector<vector<int>> vint;
    vint.push_back(v);
    cout << vint;
}

template<typename T>
void print(vector<T> &v){
    for (int i=0;i<v.size();i++ ){
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T> &v){
    for (T val : v){
        out << val << " ";
    }
    cout << endl;
}