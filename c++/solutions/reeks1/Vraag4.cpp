
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N=10;

string genereer_string(int);
void vul_array_met_strings(string * ,int , int );
void schrijf(const string *, int );
void bepaal_min_en_max(const string *, int, string &, string &);
void splits_woorden(string *, int &, const string &n);

int main(){
     int len=0;
     srand(time(NULL));
     cout << "Geef getal in [5,10]:";
     cin>>len;
     while(len<5 || len>10){
     	fflush(stdin);
     	cin.clear();
     	cout << "Opnieuw!! Geef getal in [5,10]:";
        cin>>len;
     }
     fflush(stdin); //laatste enter weghalen
     
     string tab[N];
     vul_array_met_strings(tab,N,len);
     schrijf(tab,N);
    
     string min, max;
     bepaal_min_en_max(tab,N,min,max);
     cout << endl << "min is " << min;
     cout << endl << "max is " << max << endl;   
     
     string woorden[N];
     string zin;
     
     cout << "geef een zin: ";
     getline(cin, zin);

     int n;
     splits_woorden(woorden,n,zin);
     schrijf(woorden,n);

     bepaal_min_en_max(woorden,n,min,max);
     cout << endl << "alfabetisch kleinste=" << min << " / grootste=" << max << endl;

     return 0;
}

/*** Hieronder staat de implementatie van alle methodes ****/
string genereer_string(int n){
     string s = "";
     for(int i=0; i<n; i++){
          s += ('a'+rand()%26);
     }
     return s;    
}

void vul_array_met_strings(string * tab, int n, int len){
     for(int i=0; i<n; i++){
          tab[i] = genereer_string(len);    
     }        
}

void schrijf(const string * tab, int n){
     if (n>0){
          cout << tab[0];
          for(int i=1; i<n; i++){
             cout << " - " << tab[i];
          }
     }        
}

void bepaal_min_en_max(const string * tab, int n, string & min, string & max){
     min = tab[0];
     max = tab[0];
     for(int i=1; i<n; i++){
          if (min > tab[i]){
               min = tab[i];    
          }
          else if (max < tab[i]){
               max = tab[i];    
          }
     }
}

void splits_woorden(string * tab, int &aantal, const string &zin){
     int i=0;
     int start=0;
     int p = zin.find(" ");
     while( i<N && p!=string::npos){
          tab[i] = zin.substr(start,p-start);
          start=p+1;
          p = zin.find(" ",p+1);
          i++;                  
     } 
     if(i<N){
          tab[i] = zin.substr(start);
          i++;    
     }
     aantal=i;
}
