
void Langeslang::schrijf(ostream& out)const{
    for(int i=0; i<size(); i++)
    {
         out << *(operator[](i)) << " "; //of *((*this)[i])
    }    
}

void Langeslang::vul(const vector<int>& v){
    resize(v.size());
    for(int i=0; i<size(); i++)
    {
        (*this)[i] = make_unique<int>(v[i]);
    }
}

Langeslang& Langeslang::concatenate(Langeslang & c){
    int s_b = size();  //onthouden
    resize(s_b+c.size()); 
    if(this == &c)
    { 
        for(int i=0; i<s_b; i++){
            (*this)[i+s_b] = make_unique<int>(*c[i]);     
        }
    }
    else{
        for(int i=s_b; i<size(); i++)
        { 
            (*this)[i] = move(c[i-s_b]); 
        }
        c.resize(0); 
    }
    return *this; 
}

