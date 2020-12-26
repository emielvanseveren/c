#include <iostream>
using namespace std;

class Breuk{

private:
    int teller, noemer;
    void normaliseer();
public:
    Breuk(int, int = 1);
    friend ostream& operator<< (ostream&, const Breuk&);    // Geen lidfunctie
    Breuk operator+(const Breuk &) const;                   // deze lidfunctie moet constant zijn want we returnen een nieuwe breuk, de originele breuken mogen niet aangepast worden.
    Breuk operator-() const;                                // Deze zal de tegengestelde breuk terugsturen. -a.
    Breuk operator-(const Breuk &) const;                   // 2 breuken van elkaar aftrekken. Nieuwe breuk terugsturen.

    Breuk& operator+=(const Breuk &);                       // We passen de originele breuk aan => we sturen een pointer van de breuk terug.
    Breuk& operator-=(const Breuk &);                       // De breuk die we ervan trekken passen we niet aan dus deze blijft constant!

    Breuk& operator++();                                    // prefix
    Breuk& operator++(int);                                 // postfix


    // Deel 2
    friend bool is_stambreuk(const Breuk&);                 // aangezien het in het gegeven deel2 geen lidfunctie is moeten we het implementeren als friend functie.
    Breuk operator+(int) const;                             // Be default prefix, waardoor we dus een getallen kunnen optellen zoals (i+f).
    Breuk operator+(int, const Breuk &);

};
