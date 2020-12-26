
//aangepast hoofdprogramma:
   vector<unique_ptr<Rechthoek>> v; 

   v.push_back(make_unique<Rechthoek>(4,6)); 
   v.push_back(make_unique<GekleurdeRechthoek>()); //gewenste type gebruiken!!!
   v.push_back(make_unique<GekleurdeRechthoek>(6,9,"rood")); 
   v.push_back(make_unique<Vierkant>(10));  

   for(int i=0 ; i<v.size() ; i++) 
   { 
      cout << *v[i]; 
      cout << " oppervlakte: " << v[i]->oppervlakte() << endl 
           << " omtrek: " << v[i]->omtrek() << endl; 
   }

// Alternatieve oplossing: opvullen vector met gewone pointers:
/* Nadelen:
   1) Zonder new lukt het enkel als je het toevoegen in main doet 
     (en niet in procedure).
   2) Met new moet je er zelf aan denken om delete toe te voegen                       
*/
   
   Rechthoek r2(4,6);
   GekleurdeRechthoek gr1;
   GekleurdeRechthoek gr3(6,9,"rood");
   Vierkant v2(10);  
   vector<Rechthoek*> v;
   v.push_back(&r2);
   v.push_back(&gr1);
   v.push_back(&gr3);
   v.push_back(&v2);  
