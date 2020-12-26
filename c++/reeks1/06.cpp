using namespace std;
#include <iostream>

void schrijf(int *, int, bool = false, char = ' ');

int main(){
    int t[] = {1,3,5,7,9,11,13};
    schrijf(t,7);
    schrijf(t,7,true);
    schrijf(t,7,false,'-');
    schrijf(t,7,true,'-');
    return 0;
}

void schrijf(int *t, int aantal, bool achterstevoren, char tussenteken){
    if(achterstevoren){
        cout << t[aantal-1];
        for(int i=aantal-2; i>=0; i--){
            cout << tussenteken << t[i];
        }
    }
    else{
        cout << t[0];
        for(int i=1; i<aantal; i++){
            cout << tussenteken << t[i];
        }
    }
    cout << endl;
}



