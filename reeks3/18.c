/*
    Beantwoord deze vraag zonder computer. Welke regels zijn syntactisch niet correct - en zullen een compilerfout
    opleveren. Welke bewerkingen kloppen wel qua syntax, maar zijn zinloos en/of gevaarlijk voor het verloop van het
    programma.  Wat zit er uiteindelijk in de variabelen? Regels die een compilefout geven, of die zinloos/gevaarlijk
    zijn negeer je hierbij.

    int main(){
        int i=7, j;
        double d;
        int *ip, *jp, *tp;
        double *dp;
        void *v;
        const int * p1;
        int * const p2 = &i;
        int t[5] = {10,20,30,40,50};

         jp = &i;               // 1
         j = *jp;               // 2
         *ip = i;               // 3
         ip = jp;               // 4
         &i = ip;               // 5
         (*ip)++;               // 6

         tp = t+2;              // 7
         j = &t[4] - tp;        // 8
         t++;                   // 9
         (*t)++;                // 10
         j = (*tp)++;           // 11
         i = *tp++;             // 12

         v = tp++;              // 13
         printf("%d", *v);      // 14
         v++;                   // 15

         p1 = ip;               // 16
         jp = p1;               // 17
         (*p1)--;               // 18
         dp = &i;               // 19
         dp = v;                // 20

         jp = p2;               // 21
         p2 = p1;               // 22
         *p2 += i;              // 23
        return 0;               // 24
}

Nadat je de oefening gemaakt hebt kan je de video op Ufora bekijken.
*/