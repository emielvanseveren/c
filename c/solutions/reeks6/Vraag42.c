
void voeg_toe(int getal, knoop ** pl){
     knoop * naar_achter;
     while(*pl && (*pl)->d < getal){
          pl=&((*pl)->opv);
     }
        
     naar_achter = *pl;
        
     *pl = (knoop*) malloc(sizeof(knoop));
     (*pl)->d = getal;
     (*pl)->opv = naar_achter; 
}

/* toevoegen in het hoofdprogramma:   */
     free_lijst(&l);    
