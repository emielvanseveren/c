
void verwijder(int x, knoop **pl){
     knoop *te_verwijderen;
     while (*pl && (*pl)->d < x){
          pl = &((*pl)->opv);    
     }
     if(*pl && (*pl)->d ==x ){
          te_verwijderen = *pl;
          (*pl)= (*pl)->opv;
          free(te_verwijderen);
     }
     else{

          printf("\n%i niet in lijst ",x); /* ENKEL IN TESTFASE LATEN STAAN 
                                            * - of exceptie werpen 
                                            * - of returntype van maken */
     }
}

/* toevoegen in het hoofdprogramma:   */
    verwijder(2,&l);  /* kies zelf wat je hier verwijdert - test grondig uit! */
     
    free_lijst(&l); 

/*recursieve versie */
void verwijder(int x, knoop **lijst){
     if (*lijst){
          if ((*lijst)->d==x){
               knoop *hulp=*lijst;
               *lijst=(*lijst)->opv;
               free(hulp);
          } 
          else 
               verwijder(x,&((*lijst)->opv));
     }
}
