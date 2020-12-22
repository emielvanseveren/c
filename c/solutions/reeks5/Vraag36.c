
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
     double x,y;
} punt;

double max(double d1, double d2){
     return d1>d2?d1:d2;
}

double euclidische_afstand(const punt *p1, const punt *p2){
     double dx,dy;
     dx = p1->x - p2->x;
     dy = p1->y - p2->y:
     return sqrt(dx*dx + dy*dy);
}

double manhattan_afstand(const punt *p1, const punt *p2){
     return fabs(p1->x - p2->x)+fabs(p1->y - p2->y);
}

double schaakbord_afstand(const punt *p1, const punt *p2){
     return max(fabs(p1->x - p2->x),fabs(p1->y - p2->y));
}

double bepaal_max_afstand(const punt * punten, int aantal, double(*f)(const punt*,const punt*)){
     if (aantal>1){
          int i,j;
          double max=f(&punten[0],&punten[1]);
          for (i=0;i<aantal;i++){
               for (j=i+1;j<aantal;j++){
                    double afstand=f(&punten[i],&punten[j]);
                    if (afstand > max) 
                         max=afstand;
               }
          }
          return max;
     } else {
          return 0;
     }
}

int main(){
     int aantal;
     int i;
     printf("Hoeveel punten zal je ingegeven? ");
     while (scanf("%d",&aantal)!=1){
          while(getchar()!='\n');
          printf("Fout! Hoeveel punten zal je ingegeven? ");
     }
     punt *punten=(punt*)malloc(sizeof(punt)*aantal);

     for(i=0;i<aantal;i++){
          printf("Geef een punt(in de vorm x,y): ");
          double x,y;
          char komma;
          while (scanf("%lf%c%lf",&x,&komma,&y)!=3 || komma!=','){
               while(getchar()!='\n');
               printf("Fout! Geef een punt(in de vorm x,y): ");    
          }    
          punten[i].x=x;
          punten[i].y=y;
     }
     double max_eucl=bepaal_max_afstand(punten,aantal,euclidische_afstand);
     double max_manh=bepaal_max_afstand(punten,aantal,manhattan_afstand);
     double max_schaak=bepaal_max_afstand(punten,aantal,schaakbord_afstand);
    
     printf("De maximimum Euclidische afstand tussen twee punten bedraagt %lf\n",max_eucl);
     printf("De maximimum Manhattan afstand tussen twee punten bedraagt %lf\n",max_manh);
     printf("De maximimum schaakbordafstand tussen twee punten bedraagt %lf\n",max_schaak);
     free(punten);
     return 0;
}
