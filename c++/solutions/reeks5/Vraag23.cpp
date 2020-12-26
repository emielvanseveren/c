
class Rechthoek { 
   public: 
      Rechthoek(); 
      Rechthoek(int, int); 
      int omtrek() const; 
      int oppervlakte() const; 
      virtual void print(ostream &out) const;
   protected: 
      int hoogte; 
   private: 
      int breedte; 
};
class GekleurdeRechthoek : public Rechthoek { 
   public: 
      GekleurdeRechthoek(); 
      GekleurdeRechthoek(int, int, const string & = "onbekend"); 
      virtual void print(ostream &out) const; 
   private: 
      string kleur; 
};
class Vierkant : public Rechthoek { 
   public: 
      Vierkant(int = 1); 
      virtual void print(ostream &out) const; 
};

/******************* Rechthoek **********************/
Rechthoek::Rechthoek(int h, int b) : hoogte(h), breedte(b) {} 
Rechthoek::Rechthoek() : Rechthoek(1,1) {}
 
int Rechthoek::omtrek() const { 
   return (hoogte+breedte)*2; 
} 

int Rechthoek::oppervlakte() const { return (hoogte*breedte);} 

void Rechthoek::print(ostream &out) const { 
   out << "Rechthoek: " << breedte << " op " << hoogte << endl;
}

/******************* GekleurdeRechthoek **********************/
GekleurdeRechthoek::GekleurdeRechthoek(int h, int b, const string &kl) 
       : Rechthoek(h,b), kleur(kl) {} 
GekleurdeRechthoek::GekleurdeRechthoek() : kleur("onbekend") {} 

void GekleurdeRechthoek::print(ostream &out) const { 
   Rechthoek::print(out); 
   out << " kleur: " << kleur << endl; 
}

/******************* Vierkant **********************/
Vierkant::Vierkant(int zijde) : Rechthoek(zijde ,zijde) {} 

void Vierkant::print(ostream &out) const { 
   out << "Vierkant: zijde " << hoogte << endl; 
}

/************Extern ****** **********************/
//moet geen friend zijn omdat print publieke methode is 
ostream& operator << (ostream &out, const Rechthoek &rh) {
   rh.print(out);
   return out;
}
