
void free_lijst(knoop ** pl){
     if(*pl != 0){
          free_lijst(&((*pl)->opv));
          printf("ik geef knoop met inhoud %d vrij\n",(*pl)->d);
          free(*pl);
          *pl = 0;
     }    
}

/* toevoegen in het hoofdprogramma:   */
free_lijst(&l);

