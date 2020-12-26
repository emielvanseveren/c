
#include <iostream>
#include <functional>
#include <iomanip> // voor setw
using namespace std;

void schrijf(const string & tekst, const int * v, int aantal){
    cout << tekst;
    for(int i=0; i<aantal; i++){
        cout << setw(4) << v[i] << " ";
    }
    cout << endl;
}

void vul_array(const int * a, const int * b, int * c, int grootte,
            function<int(int,int)> func ){
    int i;
    for(i=0; i<grootte; i++){
        c[i] = func(a[i],b[i]);
    }
}

//aanroep in het hoofdprogramma:
    vul_array(a,b,c,GROOTTE,[](int x,int y){return x+y;});
    vul_array(a,b,c,GROOTTE,[](int x,int y){return x*y;});    
    vul_array(a,b,c,GROOTTE,[](int x,int y){return x-y;});

