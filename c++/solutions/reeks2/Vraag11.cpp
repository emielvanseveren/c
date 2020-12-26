
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/* stap 1-2 */
template <typename T>
void print(const vector<T> &v){
    for(int i=0; i< v.size();i++ ){
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
ostream& operator<< (ostream& out, const vector<T> & v){
    for(int i=0; i<v.size(); i++){
        out << v[i] << " ";
    }
    cout << endl;
    return out;
}

int main(){
    vector<vector<int> > v;
    vector<int> w;
    w.push_back(11);    
    v.push_back(w);
    cout<<v;
    return 0;
}
  

