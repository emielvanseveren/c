
/* definities bovenaan is duidelijker */
void vul_array(const int *, const int *, int *, int, int (*)(int,int) );
int som(int , int );
int product(int , int );
int verschil(int , int );
void schrijf(const int * t, int aantal);

/* int main() was gegeven */

void vul_array(const int * t_1, const int * t_2, int * resultaat, int lengte, int (*bewerking)(int,int) ){
     int i;
     for(i=0; i<lengte; i++){
          resultaat[i] = bewerking(t_1[i],t_2[i]);
     }
}
