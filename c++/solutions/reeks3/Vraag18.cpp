
/* Waaraan kunnen wij zien of je een verkapte javaprogrammeur dan wel een echte c++-programmeur bent?
   Als je ergens "="-tekens hebt staan, gebruik je de toekennings-operator. En die TOEKENNINGSOPERATOR MAAKT KOPIES in C++.
   En kopies maken is DUUUUUUUR. Dus dat doe je niet zonder geldige reden. */

#include "containers.h"

void vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(
         vector <map<string,stack<set<string>>>> & vect, int i, 
         const string &sleutel, const string & str1, const string &str2, 
         const string &str3){
    
    // OPDRACHT 1
    // een nieuwe set op stack die bij "noot" hoort steken:
    set<string> s;
    s.insert(str1);
    s.insert(str2);
    s.insert(str3);
    if (i>= vect.size()){
         vect.resize(i);
    }
    vect[i-1][sleutel].push(move(s)); // liet je de 'move' weg? 
                          // dan maak je nog een kopie van de set s
                          // (het gebruik van move (=std::move) 
                          // komt ook nog later in theorie aan bod)
    
    /* IN C++11 OOK MOGELIJK OP 2 REGELS:
    //set<string> st = {str1,str2,str3};
    //vect[i-1][sleutel].push(move(st)); 
    // ... EN ZELFS OP 1 REGEL, 
    // waarbij je automatisch (zonder move) vermijdt om de set te kopieren:
    //vect[i-1][sleutel].push({str1,str2,str3});        */  
}

// wat je zeker NIET mag doen in vorige opdracht is kopieen maken
// FOUT!   map<string,stack<set<string>>> hulpmap = vect[i-1];
// FOUT!   stack<set<string>>  hulpstack = hulpmap[sleutel];
// etcetera

bool i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(
       const vector<map<string,stack<set<string>>>> & vect, int i, 
       const string & woord, const string & element){

    if (i < 1)
        return false;
    bool aanwezig = false;
    map<string,stack<set<string> > >::const_iterator it = vect[i-1].find(woord);
    if(it != vect[i-1].end()){ // woord is aanwezig
        if(!it->second.empty()){   // bijhorende stack is niet leeg
            //+/ hier opgelost zonder iterator
            aanwezig = (it->second.top().count(element)!=0);            
        }       
    }
    return aanwezig;
}

//hulpmethode
void controleer( const vector<map<string,stack<set<string>>>> & vect, int i, 
       const string & woord, const string & element){
    
    if(i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(vect,i,woord, element))
    {
        cout << "\nmap op index " << i << " bevat sleutel '" << woord << "', en element '" <<  element << "'"
             << " zit in zijn bovenste set van de bijhorende stack";    
    }
    else{
        cout << "\nFOUT voor " << i <<  " " << woord <<  " " <<  element;
    }
}

int main(){    
   vector<map<string,stack<set<string> > > > v(5);
     
   vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(v,1,"noot","do","re","mi");
  // cout << v;
    
   controleer(v,1,"noot","re");
   controleer(v,1,"noot","sol");
   controleer(v,1,"appelmoes","re");
   controleer(v,0,"noot","re");
   return 0;
}

