
/*methode schrijf vind je in oefening 21*/

const char* pointerNaarEersteKleineLetter(const char* l){
    while(*l && (*l<'a' || *l>'z')){
        l++;
    }
    return l;
}

void verzetNaarEersteHoofdletter(const char ** l){
    while(**l && (**l<'A' || **l>'Z')){
        (*l)++;
    }
}
