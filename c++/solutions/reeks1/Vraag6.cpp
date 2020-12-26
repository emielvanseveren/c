
#include <iostream>
using namespace std;

void schrijf(const int *, int, bool achterstevoren = false, char tussenteken = ' ');

int main(){}
//default-waarden niet herhalen
void schrijf(const int * array, int aantal, bool achterstevoren, char tussenteken){    
    if(achterstevoren){
        cout << array[aantal-1];
        for(int i=aantal-2; i>=0; i--){
            cout << tussenteken << array[i];
        }
    }
    else{
        cout << array[0];
        for(int i=1; i<aantal; i++){
            cout << tussenteken << array[i];
        }
    }
    cout << endl;
}
