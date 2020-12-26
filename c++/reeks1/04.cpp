using namespace std;
#include <iostream>
#define N 10

string genereer_string(int);
void vul_array_met_strings(string*, int, int);
void schrijf(string*, int);
void bepaal_min_en_max(string *, int, string&, string&);
void splits_woorden(string *, int&, string);

int main(){
    int lengte = 8;

    srand(time(NULL)); // set seed.
    cout << genereer_string(lengte) << endl;

    // Het is een procedure, dus een void --> meegeven als pointer!
    string strings[N];
    vul_array_met_strings(strings, N, lengte);
    schrijf(strings, N);


    string min, max;
    bepaal_min_en_max(strings, N, min, max);
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;


    // laat user een getal ingeven.


    int getal = 0;
    cout << "Geef een getal tussen 5 en 10 in: ";
    while (getal < 5 || getal > 10){
        cin >> getal;
    }
    vul_array_met_strings(strings, getal, lengte);
    schrijf(strings, getal);
    bepaal_min_en_max(strings, getal, min, max);
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;


    // splits woorden van zin
    string zin = "";
    int aantal=0;
    cout << "Geef een zin op: ";
    cin >> zin;
    splits_woorden(strings, aantal, zin);
    bepaal_min_en_max(strings, aantal, min, max);
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
}



string genereer_string(int len){
    string res = "";
    for(int i=0;i<len;i++){
        // kleine letter => ascii tussen 97 en 122.
        res += rand() % ('z' - 'a' + 1) + 'a'; // rand() % (bovengrens - ondergrens + 1) + ondergrens
    }
    return res;
}

void vul_array_met_strings(string *tab, int n, int len){
    for(int i=0;i<n;i++){
        tab[i] = genereer_string(len);
    }
}

void schrijf(string *t, int n){

    for (int i=0;i<n;i++){
        cout << t[i] << " ";
    }
    cout << endl;
}

void bepaal_min_en_max(string *tab, int n, string &min, string &max){

    min = max = tab[0];

    for (int i=1;i<n;i++){
        if(tab[i] < min){
            min = tab[i];
        } else if (tab[i] > max){
            max = tab[i];
        }
    }
}

void splits_woorden(string *tab, int &aantal, string zin){
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
};