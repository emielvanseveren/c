using namespace std;
#include <iostream>
#include <functional>

void vul_array(int *, int*, int*, int, function<int(int, int)>);
void schrijf(string, int *, int);

int main(){
    const int GROOTTE = 10;
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int b[] = {0,10,20,30,40,50,60,70,80,90};
    int c[GROOTTE];

    vul_array(a,b,c,GROOTTE,[](int a, int b) {
       return a+b;
    });
    schrijf("SOM:      ",c,GROOTTE);

    vul_array(a,b,c,GROOTTE,[](int a , int b) -> int {
       return a*b;
    });
    schrijf("PRODUCT:  ",c,GROOTTE);

    vul_array(a,b,c,GROOTTE,[](int a, int b){
        return a-b;
    });
    schrijf("VERSCHIL: ",c,GROOTTE);

    return 0;
}

void vul_array(int *a, int *b, int *c, int grootte, function<int (int, int)> func){
    for(int i=0;i<grootte; i++){
        c[i] = func(a[i], b[i]);
    }
}

void schrijf(string prefix, int *t, int grootte){
    cout << prefix << ": ";
    for(int i=0;i<grootte;i++){
        cout << t[i] << " ";
    }
    cout << endl;
}