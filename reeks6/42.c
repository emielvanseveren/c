/*
 Hieronder de procedure voeg_getal_toe die een knoop toevoegt aan een lijst die stijgend geordend is en moet blijven.

    void voeg_getal_toe(int g, knoop **pl) {
        knoop *h, *m;
        if (*pl == 0 || g <= (*pl)->getal) {
            h = (knoop*) malloc(sizeof(knoop));
            h->getal = g; h->opv = *pl; *pl = h;
        }
        else {
            h = *pl;
            while (h->opv != 0 && h->opv->getal < g)
                h = h->opv;
            m = h->opv;
            h->opv = (knoop*) malloc(sizeof(knoop));
            h = h->opv; h->getal = g; h->opv = m;
        }
    }

 Je ziet dat er een opsplitsing nodig is in deelgevallen: een stuk code dat van toepassing is indien het toevoegen
 vooraan in de lijst gebeurt, en een stuk code dat alle andere gevallen behandelt. Dit dubbele werk willen we vermijden.
 Het is immers werk gespaard als je code kan schrijven die in elke situatie bruikbaar is. De hulppointer h werd
 gedeclareerd als knoop * en duidt de knoop aan waar de nieuwe knoop aangehangen zal worden. Op tekening:

    - Als we het getal 4 willen toevoegen, zal h naar de eerste knoop wijzen.
    - Als we het getal 10 toevoegen, zal h naar de laatste knoop wijzen.
    - Als we het getal 2 willen toevoegen, zal h geen knoop hebben om naar te wijzen.

    En het behandelen van een speciaal geval is niet meer nodig!

 ZIE IMAGE

 Het valt echter op te merken dat je enkel h->opv nodig hebt in de code. De inhoud van de knoop waar h naar wijst (h->d)
 heb je niet nodig. Waarom dan naar de hele knoop (zowel h->d als h->opv) wijzen? Is toegang tot h->opv niet voldoende?

 Dat is de oplossing voor ons probleem: we laten een hulppointer k wijzen naar de horizontale pijlen (de links tussen de knopen).

   - Willen we 4 toevoegen, dan wijst k naar de tweede horizontale pijl.
   - Willen we 10 toevoegen, dan wijst k naar de laatste horizontale pijl.
   - Willen we 2 toevoegen, dan wijst k naar de eerste horizontale pijl.

  En het behandelen van een speciaal geval is niet meer nodig! Herschrijf de procedure voeg_getal_toe(getal,lijst)
  zonder if-else -structuur! De functionaliteit blijft dezelfde.

 */