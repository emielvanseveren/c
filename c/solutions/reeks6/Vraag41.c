
/* werk verder op voorgaande oefening */
/* bouw nog veiligheid in: geen twee dezelfde lijsten mergen! */
knoop * merge(knoop ** pa, knoop ** pb){
     knoop * l;
     knoop * i = *pa;
     knoop * j = *pb;
     knoop * k;
     if(*pa == 0){
          l = *pb;
          *pb = 0;
          return l;    
     }
     else if(*pb == 0){
          l = *pa;
          *pa = 0;
          return l;    
     }
    
     if((*pa)->d < (*pb)->d){
          l = *pa;
          i = (*pa)->opv;
          k = l;    
     }
     else{
          l = *pb;
          j = (*pb)->opv;
          k = l;    
     }

     while(i != 0 && j != 0){
          if(i->d < j->d){
               k -> opv = i;
               i = i -> opv;    
          }    
          else{
               k -> opv = j;
               j = j -> opv;
          }
          k = k -> opv;            
     }
     if(i != 0){
          k -> opv = i;    
     }
     if(j != 0){
          k -> opv = j;    
     }
    
     *pa = 0;
     *pb = 0;
     return l;    
}        

/* vul het hoofdprogramma aan */
     knoop * mn = merge_bis(&m,&n);    
    
/* op het einde */    
     vernietig_lijst(&mn);
    
