#include <iostream>
#include <set>
#include <stack>
#include <map>

using namespace std;


template <typename T>
ostream& operator<<(ostream&, set<T>&);

template <typename T>
ostream& operator<< (ostream&, stack<T>);

template <typename T1, typename T2>
ostream& operator<<(ostream&, map<T1,T2>&);


int main(){

    // sample set
    set<string> s;
    s.insert("test1");
    s.insert("test2");
    s.insert("test3");
    cout << s;
    cout << endl;

    // sample stack
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st;
    cout << endl;

    // sample map
    map<char, string> m;
    m['a'] = "astrid";
    m['e'] = "emiel";
    cout << m;

    return 0;
}

template <typename T>
ostream& operator<<(ostream &out, set<T> &s){

    typename set<T>::iterator it;
    it = s.begin();

    while(it != s.end()){ // Zolang de waarde die in de iterator zit verschillend is van de laatste waarde die in de set zit. We kunnen dit vergelijken met het laatste element want een set bevat enkel unieke waarden.
        out << *it++ << " ";
    }
}

template <typename T>
ostream& operator<<(ostream& out, stack<T> st){ // hier dus GEEN kopie.

    while(st.size()){
        out << st.top() << " "; // referentie naar bovenste.
        st.pop(); // Bovenste element eraf halen.
    }
}

template <typename T1, typename T2>
ostream& operator<<(ostream &out, map<T1, T2> &m){
    typename map<T1,T2>::iterator it = m.begin();// hier moeten we werken met een pair. van key en value.

    while(it != m.end()){
        out << "key: " << it->first << "\t" << "value: " << it->second << endl;
        it++;
    }
}