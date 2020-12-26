#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    for(int i=0;i<65;i++){
        cout << setw(6) << dec << i << setw(6) << oct << i << setw(6) << hex << i << "\n";
    }
    return 0;
}

