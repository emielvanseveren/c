
class GekleurdeRechthoek : public Rechthoek { 
     //...
  
     //Wijzig in protected
   protected: 
      string kleur; 
};

class GekleurdVierkant : public Vierkant, public GekleurdeRechthoek { 
   public: 
      GekleurdVierkant(int = 1, const string & = "onbekend"); 
      void print(ostream &out) const; 
};

GekleurdVierkant::GekleurdVierkant(int zijde , const string &kl) : 
   GekleurdeRechthoek(zijde ,zijde ,kl), Vierkant(zijde) {}  

void GekleurdVierkant::print(ostream &out) const { 
   Vierkant::print(out); 
   out << " kleur: " << kleur << endl;  //kleur in de klasse GekleurdeRechthoek is protected
}

//aangezien Rechthoek een "ambiguous base" is van GekleurdVierkant
//moet de operator <<  specifiek herschreven worden:
ostream& operator << (ostream &out, const GekleurdVierkant &v) {
   v.print(out);
   return out;
}

/************* aanvullingen in main voor het uitschrijven **********/

   GekleurdVierkant gv1; 
   cout << gv1; 
   cout << " oppervlakte: " << gv1.Vierkant::oppervlakte() << endl 
        << " omtrek: " << gv1.Vierkant::omtrek() << endl;
        
   GekleurdVierkant gv2(12); 
   gv2.print(cout); 
   cout << " oppervlakte: " << gv2.Vierkant::oppervlakte() << endl 
        << " omtrek: " << gv2.GekleurdeRechthoek::omtrek() << endl;
        
   GekleurdVierkant gv3(15,"geel"); 
   cout << gv3;
   cout << " oppervlakte: " << gv3.GekleurdeRechthoek::oppervlakte() << endl 
        << " omtrek: " << gv3.GekleurdeRechthoek::omtrek() << endl; 
