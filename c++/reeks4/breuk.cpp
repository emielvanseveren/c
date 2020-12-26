#include "breuk.h"


// niet lid
ostream& operator << (ostream &out, const Breuk &b){
    out << b.teller << "/" << b.noemer;
    return out;
}

int mijn_ggd(int a, int b){
    if(a < 0 || b < 0){
        return mijn_ggd(abs(a),abs(b));
    }
    if(b == 0){
        return a;
    }
    return mijn_ggd(b,a%b);
}

void Breuk::normaliseer() {
    if(this->noemer < 0){
        this->teller = this->teller*-1;
        this->noemer = this->noemer*-1;
    }
    int deler = mijn_ggd(teller,noemer);
    this->teller /= deler;
    this->noemer /= deler;
}

bool is_stambreuk(const Breuk &b){
    if(b.teller == 1){
        return true;
    } else {
        return false;
    }
}

Breuk Breuk::operator+(int x) const{
    x *= this->noemer;
    x += this->teller;
    return Breuk(x, this->noemer);
}
Breuk operator+(int x, const Breuk& b){
    return b+x;
}


// constructor
Breuk::Breuk(int teller, int noemer){
    this->teller = teller;
    this->noemer = noemer;
    normaliseer();
}

/* via initializer list (Opgelet de namen van de parameters mogen != aan de attributen van de klasse*/
//Breuk::Breuk(int t, int n):teller(t),noemer(n){}

// lidfunctie
Breuk Breuk::operator+ (const Breuk &b) const {
    return Breuk(this->teller*b.noemer + b.teller * this->noemer, this->noemer*b.noemer);
}
Breuk Breuk::operator-()const{
    return Breuk(this->teller*-1, this->noemer);
}

Breuk Breuk::operator-(const Breuk &b) const {
    return Breuk(this->teller*b.noemer - b.teller * this->noemer, this->noemer*b.noemer);
};

Breuk& Breuk::operator+=(const Breuk &b){
    this->teller = this->teller*b.noemer + b.teller * this->noemer;
    this->noemer = this->noemer*b.noemer;
    normaliseer();
    return *this;
}

Breuk& Breuk::operator-=(const Breuk &b){
    this->teller = (this->teller*b.noemer) - (b.teller * this->noemer);
    this->noemer = this->noemer*b.noemer;
    normaliseer();
    return *this;
}

Breuk& Breuk::operator++(){ // ++-prefix
    this->teller = this->teller+this->noemer;
    return *this;
}
Breuk& Breuk::operator++(int){
    this->teller = this->teller++;
    return *this;
}


