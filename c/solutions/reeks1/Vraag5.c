
/*
Als je een for-lus gebruikt, geef je de lezer het sein dat je op voorhand weet hoe dikwijls je de code gaat uitvoeren.
Als je dan toch al van plan was om tussendoor van gedachten te veranderen (zie de 'break' in de 'if'), had je dat beter op voorhand duidelijk 
gemaakt door een (correcte) while-lus te gebruiken.
Dat is ook de bestaansreden van BEIDE lussen: 
   de for-lus gebruik je als het aantal herhalingen op voorhand vastligt,
   de while-lus gebruik je in de andere gevallen.
Bovendien: de bovengrens 20 in de for-lus kan ondergedimensioneerd zijn als je de grens 10000 aanpast. 
Dat duidt er nogmaals op dat deze oplossing niet foolproof is. 
(Ja, ze zou correcter met constanten kunnen werken, maar dan nog blijft de opmerking over de 'break' die niet netjes is!)
*/
