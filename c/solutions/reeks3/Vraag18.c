
/* 1*/ jp = &i; /* ok: jp wijst naar geheugenplaats met naam i; types kloppen         */
/* 2*/ j = *jp; /* ok: j krijgt nu de waarde 7                                        */
/* 3*/ *ip = i; /* FOUT: ip is zwevende pointer; 
                         *ip is geen gereserveerde geheugenplaats                     */	
/* 4*/ ip = jp; /* ok: ip wijst nu ook naar geheugenplaats met naam i                 */
/* 5*/ &i = ip; /* FOUT: een adres kan je niet wijzigen                               */
/* 6*/ (*ip)++; /* ok: 7 wordt nu 8                                                   */
	
/* 7*/ tp = t+2;         /* ok: tp wijst nu naar derde element in de array t          */
/* 8*/ j = &t[4] - tp;   /* ok: j wordt nu 4-2=2                                      */
/* 9*/ t++;              /* FOUT: array kan je niet opschuiven                        */
/*10*/ (*t)++;           /* ok: eerste element van de tabel verhoogt met 1            */
/*11*/ j = (*tp)++;  /* ok: j krijgt nu de waarde van t[2]- waarna dat element met 1 verhoogt  
            (concreet: j is nu 30, terwijl de array 10 20 31 40 50 bevat)             */
/*12*/ i = *tp++;    /* ok: i krijgt de waarde van t[2] (concreet: 31), 
            tp schuift een plaats naar rechts in de tabel (concreet: tp wijst naar t[3])*/

/*13*/ v = tp++;     /* ok, v wijst naar tp, tp schuift 1 plaats op                    */
/*14*/ printf("%d", *v);  /* FOUT: dereferentie void-pointer lukt niet                 */
/*15*/ v++;          /* FOUT: geen rekenkundige bewerkingen op void-pointer            */

/*16*/ p1 = ip;      /* ok: p1 is pointer naar const en belooft dus meer dan ip deed   */ 
/*17*/ jp = p1;      /* geeft FOUT of warning en is ZEKER NOT DONE: 
         p1 is pointer naar const, terwijl jp niet belooft om de geheugenplaats waarnaar-ie wijst  ongewijzigd te laten.                                           */
/* warning: "assignment discards 'const' qualifier from  pointer target type [enabled by default]"*/
/*18*/ (*p1)--;      /* FOUT: p1 is een pointer naar const, dus  mag je via p1 geen wijzigingen aanbrengen aan *p1 */
/*19*/ dp = &i;      /* geeft FOUT of warning: pointer naar double kan niet geinitialiseerd worden met adres van int */
/*20*/ dp = v;       /* CORRECT, maar gevaarlijk, dp wijst nu naar een int             */
					
/*21*/ jp = p2;      /* ok: jp wijst nu naar element waar p2 naar wijst 
        (p2 is een constante pointer dus verhuist zelf nooit, maar heeft niet beloofd 
        om de geheugenplaats  waar-ie naar wijst ongewijzigd te laten, dus moet  jp dat ook niet doen)  */
/*22*/ p2 = p1;      /* FOUT: p2 is een constante  pointer,  en kan dus geen nieuwe waarde aannemen */
/*23*/ *p2 += i;     /* in orde; gezien p2 bij initialisatie naar i verwees, 
                       wordt de inhoud van i bij deze verdubbeld                       */
