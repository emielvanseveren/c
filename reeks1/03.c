/*
    Gegeven volgend programmafragment, als oplossing voor oefening 1. Dit levert de gevraagde output. Het levert echter
    op een examen strafpunten op. Waarom?
*/

int main(){
    int i;
    for(i=10; i>0; i--){
        if(i==10){
            printf("Hello world!\n");
        }
        printf("%d ",i);
        if(i==1){
            printf("\nSTART");
        }
    }
}

 /*
 Uitleg:
 *  If statement n een for statement duidt meestal op fout gebruik. De if statements moeten elke loop gecontroleerd worden.
    In dit voorbeeld is dit minder relevant aangezien we de loop maar 10x uitvoeren. Maar dit heeft een veel grotere invloed
    indien we dit 10000000000x uitvoeren.
 *  De prints moeten dus eigenlijk gewoon buiten de loop gebeuren.
*/
