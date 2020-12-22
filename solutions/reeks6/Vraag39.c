
/* definitie knoop toevoegen */
void voeg_vooraan_toe(int x,knoop ** pl){
     knoop * even_bijhouden = *pl;
     *pl = (knoop*) malloc(sizeof(knoop));
     (*pl)->d = x;
     (*pl)->opv = even_bijhouden;     
}

void print_lijst(const knoop * l){
     while( l != 0){
          printf("%d ",l->d);
          l = l->opv;        
     }
     printf("X\n");
}
/*recursieve versie*/
void print_lijst(const knoop * l){
     if( l!=0 ){
          printf("%d ",l->d);   
          print_lijst_recursief(l->opv);
     }
     else{        
          printf("X\n");  /* 'X' om einde van de lijst aan te geven, 
                             zodat ook een lege lijst zichtbaar is */
     }
}

/* Niet correct:  void vernietig_lijst(knoop *l) 
   Reden: l moet ook wijzigen in het hoofdprogramma (wordt O) 
   (en niet wijzen naar een vernietigde knoop)                                */

void vernietig_lijst(knoop **pl) {
     knoop *h;
     while (*pl != 0) {
          h = *pl;
          *pl = h->opv;
          printf("Ik geef knoop %d vrij\n",h->d); /*ter info*/          
          free(h);
     }    
}

/* aanvullingen in het hoofdprogramma:                                      */
     voeg_vooraan_toe(7,&l);  /* geef &l mee; aan een kopie van de pointer l
                               * wijzigingen aanbrengen helpt immers niet
                               * (zie vorige oefening!!)                    */
     voeg_vooraan_toe(3,&l);
     print_lijst(l);          /* geef l mee; er moet toch niets veranderen 
                               * aan dit adres                              */                               
     print_lijst_recursief(l);                              
/* toevoegen                                                                */
     vernietig_lijst(&l); 
