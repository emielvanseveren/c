
#include <functional>

class Groep : public vector<Persoon>{
    public:
        Persoon geef_beste(
              function<bool(const Persoon&, const Persoon &)> func){
    // index aanpassen is zuiniger; Persoon kopieren mag zeker niet! 
            int  index_beste = 0;
            for(int i=1; i<size(); i++){
                if(func(operator[](i),operator[](index_beste))){
                    index_beste = i;
                }
            }
            return operator[](index_beste);
        }
};

/****** Aanvullen in main **************/
    
    cout << "Eerste qua naam:     " << gr.geef_beste(
      [](const Persoon& a, const Persoon& b){return a.naam < b.naam;})
         << endl;
    
    cout << "Eerste qua voornaam: " << gr.geef_beste(
      [](const Persoon& a, const Persoon& b){
            return a.voornaam < b.voornaam;}) << endl;
    
    cout << "Jongste:             " << gr.geef_beste(
      [](const Persoon& a, const Persoon& b){
            return a.leeftijd < b.leeftijd;}) << endl;

    cout << "Oudste:              " << gr.geef_beste(
      [](const Persoon& a, const Persoon& b){
            return a.leeftijd > b.leeftijd;}) << endl;
