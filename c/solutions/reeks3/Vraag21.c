
void schrijf_aantal(const char a[], int n){  /* of (const char *a, int n)  */
     int i;
     for(i=0 ; i<n ; i++){
          printf("%c",a[i]);
     }
}

void schrijf(const char* begin, const char* eind){
     while(begin < eind){	
          printf("%c",*begin);
          begin++;
/* de twee statements kunnen ook in 1 opdracht: printf("%c",*begin++);    */
     }
}

/* voeg onderstaande code toe in het hoofdprogramma: */        
     printf("Aantal elementen in array   :      %d\n",sizeof(letters)/sizeof(char));
     printf("Aantal elementen via pointer:      %d\n",sizeof(p)/sizeof(char));

/* sizeof pointer is altijd 8 !*/
     printf("sizeof pointer to letter %d: \n", sizeof(p));
     printf("sizeof char*             %d: \n", sizeof(char*));
     printf("sizeof int*              %d: \n", sizeof(int*));
     printf("sizeof double*           %d: \n", sizeof(double*));
     printf("sizeof void*             %d: \n", sizeof(void*));
