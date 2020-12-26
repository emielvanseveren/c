
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::oct;
using std::hex;
using std::dec;
// of kortweg
// using namespace std;

int main(){
    for(int i=0; i<=64; i++){
    	cout << setw(6) << oct << i << setw(6) << dec << i << setw(6) 
             << hex << i << endl;
    }
   
    return 0;  
}
