int main(){
    char zus1[50] = "sneeuwWITje";
    char zus2[50] = "rozeROOD";
    const char* begin;
    const char* eind;
    begin = zus1;
    verzetNaarEersteHoofdletter(&begin);
    eind = pointerNaarEersteKleineLetter(begin);
    schrijf(begin,eind);   /* schrijft 'WIT' uit */
    printf("\n");
    begin = zus2;
    verzetNaarEersteHoofdletter(&begin);
    eind = pointerNaarEersteKleineLetter(begin);
    schrijf(begin,eind);   /* schrijft 'ROOD' uit */
    return 0;
}

// dit heb ik al gemaakt.