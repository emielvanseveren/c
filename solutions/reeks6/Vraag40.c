
/* werk verder op vorige oefening */

/* lijst met elementen in stijgende volgorde, dubbels mogelijk */
knoop* maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens){
     knoop * l = 0;
     int getal = bovengrens;
     int i;
     for(i=0; i<aantal; i++){
          getal -= rand()%3;
          voeg_vooraan_toe(getal,&l);    
     }
     return l;
}

/* Omdat je de eerste knoop nooit zal verwijderen, hoef je niet per se via knoop** door te geven      */
void verwijder_dubbels(knoop * l){
    while(l != 0){
          while (l->opv != 0 && l->opv->d == l->d){
               knoop * magweg = l->opv;
               l->opv = magweg->opv;
               free(magweg);    
          }
          l = l->opv;
     }
}

/* HIERONDER EEN ALTERNATIEF, zie je wat er hier gebeurt?     */
void verwijder_dubbels_alternatieve_versie(knoop * l){
     /* h staat aan het begin van de gelijke waarden */
     /* m staat aan het einde van de gelijke waarden */
     knoop * h = l;
     knoop * m = l;
     while(m != 0){    
          while(m != 0 && h -> d == m -> d){
               m = m -> opv;        
          }
          if(h -> opv != m){
               knoop * magweg = h -> opv;    
               knoop * einde_magweg = magweg;
               while(einde_magweg != 0 && einde_magweg->opv != m){
                    einde_magweg = einde_magweg -> opv;
               }
               einde_magweg -> opv = 0;
               vernietig_lijst(&magweg);                
          }
          h -> opv = m;
          h = m;
     }    
}

/* aanvulling in het hoofdprogramma:                        */
      verwijder_dubbels(l);
/* toevoegen:                                               */
      vernietig_lijst(&l);
