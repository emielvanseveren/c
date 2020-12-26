
// De gegeven methode mijn_ggd is ook nuttig buiten de Breuk-klasse.
// In Java zou je ervoor kiezen deze 'static' te maken 
// (je kan immers niets buiten een klasse schrijven in Java);
// in C++ kan je een functie gerust extern schrijven.

int mijn_ggd(int a, int b){ // ... }

class Breuk{
  private:
     int teller, noemer;      
     void normaliseer();

  public:        
     // voor deel 1
     Breuk(int, int );
     // merk op: operator= en copyconstructor moet je niet schrijven 
     //    want die bestaan al (en hun standaardwerking volstaat:
     //    er zijn immers geen pointers als dataleden)

     // is geen lidfunctie; 
     friend ostream& operator << (ostream &, const Breuk &);

     Breuk& operator+=(const Breuk&);  
     Breuk& operator-=(const Breuk&); 
      
     Breuk operator+(const Breuk&) const; 
     Breuk operator-(const Breuk&) const; 
      
     Breuk operator-() const;
       
     Breuk& operator++();
     Breuk operator++(int);
        
     // voor deel 2
     Breuk operator+(int) const;
     bool operator<(const Breuk&) const; 
     friend bool is_stambreuk(const Breuk&);
     
     // voor deel 3  
     bool operator==(const Breuk&) const;  
     bool operator!=(const Breuk&) const;      
     friend istream& operator>>(istream&, Breuk&);
};

//constructor
Breuk:: Breuk(int t=0, int n=1):teller(t),noemer(n) {  //initializer list  
      normaliseer(); 
} 

//lidfunctie
void Breuk::normaliseer(){
     if(noemer < 0) { 
          noemer *= -1; teller *= -1; 
     }
     int deler = mijn_ggd(teller,noemer);
     teller /= deler;
     noemer /= deler;
}

//Extern (friend van Breuk)
ostream& operator << (ostream & uit, const Breuk & b) {
     uit << b.teller ;
     if(b.noemer != 1) uit << "/" << b.noemer;
     return uit;
}

//Lidfuncties
Breuk& Breuk::operator+=(const Breuk & b) {     
     teller = b.noemer * teller + noemer * b.teller;
     noemer = noemer * b.noemer; 
     normaliseer(); 
     return *this;
}

Breuk& Breuk::operator-=(const Breuk & b) {
     operator+=(-b);
     return *this;
}

Breuk Breuk::operator+(const Breuk & b) const {
     return Breuk( b.noemer * teller + noemer * b.teller,noemer * b.noemer);
}
//Alternatief die gebruik maakt van de operator += 
/*
Breuk Breuk::operator+(const Breuk & b) const {
     Breuk c(*this);  // Gebruikt de copyconstructor (default-versie voldoet)
         // Dat is efficienter dan Breuk c = *this (maakt eerst een Breuk aan met 
         // de defaultconstructor, om daarna weer de dataleden te overschrijven).
     c += b;  //gebruikt +=      
     return c;
}  */

Breuk Breuk::operator-(const Breuk & b) const {
     return Breuk( b.noemer * teller - noemer * b.teller,noemer * b.noemer);
}
//Alternatief die gebruik maakt van de operator -=
/*
Breuk Breuk::operator-(const Breuk& b) const {
     Breuk c(*this); 
     c -= b;
     return c;
}  */

Breuk Breuk::operator-() const {
     return Breuk(-teller,noemer);     
}

Breuk& Breuk::operator++(){
     teller += noemer;
     normaliseer();
     return *this;
}
        
Breuk Breuk::operator++(int a){
     Breuk temp(*this);
     teller += noemer;
     normaliseer();
     return temp;
}


/***************** DEEL 2 ********************/

Breuk Breuk::operator+(int x) const{
     Breuk c(*this);
     x *= c.noemer;
     c.teller += x;     
     return c;     
}

bool Breuk::operator<(const Breuk& b) const {
     return teller * b.noemer < noemer * b.teller;
}

Breuk operator+(int x, const Breuk& b){
     return b+x;
}

bool is_stambreuk(const Breuk & a){
     return a.teller == 1;
}  

/***************** DEEL 3 ********************/

bool Breuk::operator==(const Breuk& b) const {
     return teller == b.teller && noemer == b.noemer;
}

bool Breuk::operator!=(const Breuk & b) const {
     return !operator==(b);
}

//Twee oplossingen voor het inlezen met "/" tussen teller en noemer
//Voor het examen moet je enkel de getallen kunnen inlezen met spatie ertussen

//Extern (friend van Breuk)
//gebruikt de functie  int atoi(char *)

istream& operator>>(istream &in,  Breuk & b) {
    string lijn;
    in>>lijn;
    int teller,noemer;
    int p = lijn.find("/");
    if(p!=string::npos){
        teller = atoi(lijn.substr(0,p).c_str());
        noemer = atoi(lijn.substr(p+1).c_str());
        b = Breuk(teller,noemer);
    }
    else{
        int getal = atoi(lijn.c_str());
        b = Breuk(getal);
    }
    return in;    
}

//Alternatief 
//gebruikt stringstream (te vergelijken met Scanner)

istream& operator>>(istream& in, Breuk & b) {   
     string getalbeeld;  
     in >> getalbeeld;
     stringstream ss; 
     ss << getalbeeld;
     int positie = getalbeeld.find("/");
     if(positie != string::npos) {
          int t; char c; int n;
          ss >> t; 
          ss >> c; 
          ss >> n;  
          b = Breuk(t,n); 
     }
     else {  // misschien is er geen breukstreep, omdat je
             // enkel een geheel getal (dus met noemer = 1) opgaf
          int t; 
          ss >> t;
          b = Breuk();
     }
     return in;
}
