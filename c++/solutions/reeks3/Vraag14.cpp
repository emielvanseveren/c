
// Set uitschrijven? als je per se komma's tussen de elementen wil
// (en geen komma meer na het laatste element), kan je niet met een
// gewone while-lus werken. je kan niet 'rekenen' met iteratoren,
// dus " s.end() - 1 " heeft geen betekenis (al had je gehoopt dat dat
// de iterator zou zijn die op het laatste element staat te wijzen...)

// Wat wel zou kunnen: een iterator 'hulp' gelijkstellen aan s.end(),
// die iterator 'hulp' dan eentje naar voor schuiven, en in de 
// while-lus voortdoen zolang de iterator die vooraan startte, 
// niet gelijk is aan die iterator 'hulp'.

template<typename T>
ostream& operator << (ostream& out, const set<T> & s){
     out << "{ ";
     typename set<T>::const_iterator it = s.begin();
     for(int i=0; i<s.size()-1; i++){
          out << *it << " , ";
          it++;
     }
     out << *it << " }";
     return out;
}

template<typename T>
ostream& operator << (ostream& out, stack<T> st){   // st MOET kopie zijn 
     while(!st.empty()){
          out << "  " << st.top() << endl;
          st.pop();
     }
     return out;
}

template<typename S, typename D>
ostream& operator << (ostream& out, const map<S,D> & m){
     typename map<S,D>::const_iterator it = m.begin();
     while(it!=m.end()){
          out << "  " << it->first << " --> " << it->second << endl;
          it++;
     }
     return out;
}


#include "containers.h"
const int AANTAL = 5;
int main(){
    stack<string> st;
    st.push("een");
    st.push("twee");
    st.push("drie");
    cout << st; // als je geen kopie had gemaakt bij uitschrijven van de stack, zal dit
    cout << st; // hier niet werken!!! (dan heb je de 2e maal een lege stack)
}

