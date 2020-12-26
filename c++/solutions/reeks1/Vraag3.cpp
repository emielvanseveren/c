
/* Het eerste stukje werkt niet. De reden: de code
              "" + c 
start met een constante c-string. Daar tel je met de +-operator iets bij. 
Maar c-strings tel je niet op met '+', wel met strcat.

Je zou kunnen argumenteren dat dit ook de notatie is voor een constante 
standard-string, maar hoe moet de compiler het verschil weten? 
De c-strings waren er eerst, dus de compiler interpreteert "" als een c-string.

Het tweede stukje werkt wel. De reden: de code   
            string w = "";
zorgt ervoor dat de constante "" c-string gecast wordt naar een (standard-)string.
Strings kan je wel aan elkaar plakken met de +-operator. */
