
#include <stdio.h>
/* In deel 2 van deze vraag wordt de returnwaarde van deze functie gebruikt 
   om het gevonden getal te bewerken! Dit kan niet indien het returntype const int* gebruikt wordt. 
   Nu moet ook 'const' bij de eerste parameter weggehaald worden: 
   als we een niet -const pointer willen teruggeven naar een array, dan moeten we toegang 
   hebben tot deze array aan de hand van een niet -const pointer! */ 

int* plaats_van(int array[], int aantal , int gezocht) { 
     int i = 0; 
     while(i<aantal && gezocht != array[i])
          i++; 
     return (i<aantal ? &array[i] : NULL); 
}
/* alternatieve oplossing:
   int* plaats_van(int array[], int aantal , int gezocht) { 
   int i; 
   for (i=0 ; i<aantal ; i++) 
       if (gezocht == array[i])
          return &array[i]; 
   return 0; 
   }
*/
void plaats_ptr_op_getal(int ** dptr, int aantal, int gezocht) { 
     int i = 0; 
     while(i<aantal && gezocht != **dptr) { 
          (*dptr)++; 
          i++; 
     } 
     if (i==aantal) 
          *dptr = NULL; 
}
/* Merk op: om snel te controleren zonder inmenging van de gebruiker, 
   kan je de waarde van x hardcoderen. Dat kan tijd sparen bij het testen. */
int main() { 
     int rij []= {8,4,2,0,6,10}; 
     int lengte = sizeof(rij)/sizeof(rij[0]); 
     int x, i; 
     int *plaats, *ptr;
     printf("Geef een geheel getal op "); 
     scanf("%d",&x);
     plaats = plaats_van(rij,lengte ,x); 
     if(plaats == NULL) { 
          printf("\nHet getal %d werd niet gevonden in de niet-geordende array.",x); 
     }
     else {
          printf("\nIk vond het getal en vervang het door zijn tweevoud.\n"); 
          *plaats *= 2; 
          for(i=0; i<lengte; i++)
               printf("%d ",rij[i]); 
     }
     printf("\n\nVIERDE DEEL VAN DE OEFENING\n\nGeef een geheel getal op "); 
     scanf("%d",&x); 
     printf("\nJe gaf het getal %d op.",x);
     ptr = rij; /*zet de pointer klaar vooraan in de array */
     plaats_ptr_op_getal(&ptr,lengte ,x); 
     if(ptr == NULL)
          printf("\nHet getal %d werd niet gevonden in de niet -geordende array.",x); 
     else {
          printf("\nIk vond het getal en print de array vanaf dat getal:\n"); 
          for(i=0; i<lengte - (ptr-rij); i++) 
               printf("%d ",ptr[i]);  
     }
     return 0;
}
