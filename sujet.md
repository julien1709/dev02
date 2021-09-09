# Normalisation de capteur 

Vous devez écrire un programme qui permet de normaliser les données d'un capteur.
Les données du capteur sont transmises sous la forme: int valCapteur[8];
Les valeurs de capteur valides sont comprises entre 0 et 1023.

Vous disposez d'un exemple exemple.c réalisant ce calcul en utilisant une moyenne, mais les résultats ne 
sont pas très satisfaisants.

Pour améliorer les résultats, vous utilisez l'algorithme suivant:
- supprimer les 2 valeurs de capteur les plus basses et les 2 plus hautes pour limiter les artefacts de lecture.
- Puis faire la moyenne des 4 valeurs restantes.

Variante: faire une rotation de 2 bits vers la droite pour remplacer la division par 4.
Est ce que la variante est plus rapide ? Pourquoi ?