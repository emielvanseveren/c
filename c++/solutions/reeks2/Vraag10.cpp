
//Schrijf de inhoud van 1 unieke pointer, indien niet de nullptr
void schrijf (const unique_ptr<string> &s){
    if(s==nullptr){
        cout << "NULL";
    }
    else{
        cout << *s;
    }
}

void schrijf(const unique_ptr<string> * s, int aantal){
    cout << endl;
    for(int i=0; i<aantal-1; i++){
        schrijf(s[i]);
        cout << " - ";
    }
    schrijf(s[aantal-1]);
}

// OPGELET!! WAT WE NIET WILLEN ZIEN STAAN IN DE PROCEDURE HIERONDER:
//    *s[i] = *s[i+1]   --> kopieert strings
// OF
//    *s[i] = move(*s[i+1]) --> swapt de strings; probeer eens uit: 
//               als je 'Rein' weghaalt uit 'Rein Ada Eppo'
//               eindig je met 'Ada Eppo Rein'    

void verwijder(unique_ptr<string> * s, int aantal, int volgnr){    
    if(volgnr < aantal-1){        
        for(int i = volgnr; i < aantal-1; i++){
            s[i] = move(s[i+1]);
        }        
    }
    else{
        //indien de laatste moet verwijderd worden 
       if(volgnr == aantal-1){
           s[volgnr].reset();
       }
    }
}

//Declaratie in het hoofdprogramma:
    
    unique_ptr<string> pnamen[]={
        make_unique<string>("Rein"),
        make_unique<string>("Ada"),
        make_unique<string>("Eppo"), 
        make_unique<string>("Pascal"), 
        make_unique<string>("Ilse")};


