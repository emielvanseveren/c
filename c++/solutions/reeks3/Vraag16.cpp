
#include "containers.h"

void zoek(const string & woord, const vector<map<char,unordered_set<string> > > & v){
     if(woord.size() < v.size()){
          if(v[woord.size()].count(woord[0])==1){
               map<char,unordered_set<string> >::const_iterator it = v[woord.size()].find(woord[0]);
               cout << it->second;
          }
          else{ cout << "geen woorden van die lengte" << woord[0] << endl; }
     }
     else{ cout << "Het ingegeven woord is langer dan het langste woord in de lijst." << endl; }
}

int main(){
     vector<map<char,unordered_set<string> > > v(10); //vertrek van 10 elementen
     string woord;
     cout << "geef woorden, eindig met STOP" << endl;
     cin>>woord;
     while(woord!="STOP"){
          if(woord.size() > v.size()-1){
               v.resize(woord.size()+1); 
          }
          v[woord.size()][woord[0]].insert(woord);
          cin>>woord;
     }
     //cout << v;
    
     //cout << endl << "geef een woord, ik zoek even lange woorden die met dezelfde letter starten ";
     //cin>>woord;
     zoek("sinterklaas",v);
     return 0;
}


