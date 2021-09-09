#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
 
int normaliseCapteur( int valCapteur[8] );
 
int main(void) {
    int valCapteur[8] = { 2, 56, 180, 60, 10, 1020, 65, 55 };
    int moyenne;
 
    int j;
    unsigned long duree;
    struct timeval debutCalcul, finCalcul;
 
    // Heure debut du calcul
    gettimeofday(&debutCalcul , NULL);
 
    // Refaire le calcul 10000 fois pour augmenter la durée de calcul
    /*
    for( j = 0; j < 10000; j++) {
        moyenne = normaliseCapteur(valCapteur);
    }*/
    
    moyenne = normaliseCapteur(valCapteur);

 
    // Heure fin du calcul
    gettimeofday(&finCalcul, NULL);
 
    printf("La moyenne des valeurs est --> %d\n", moyenne);
 
    duree = ((finCalcul.tv_sec - debutCalcul.tv_sec) * 1000000) + (finCalcul.tv_usec - debutCalcul.tv_usec);
    printf( "La durée du programme est --> %ld ms\n", duree );  
}
 
int intCmp(const void *aa, const void *bb) {
    const int *a = aa, *b = bb;
    return (*a < *b) ? -1 : (*a > *b);
}
 
int getRealAverage(int total) {
    // On divise par 4 car il ne nous reste plus que 4 valeurs. 
    int moyenne = total / 4;
    return(moyenne);
}
 
int normaliseCapteur( int valCapteur[8]) {
    int total=0;
    int moyenne;
 
    // Cette fonction va nous permettre de sort nos valeurs selon un ordre croissant
    qsort(valCapteur, 8, sizeof(int), intCmp);
 
    // On enlève les deux extrêmes de chaque côté donc on va de valCapteur[2] à valCapteur[6]
    for( int i = 2; i < 6; i++) {
        total += valCapteur[i];
    }
 
    moyenne = total >>= 2;
 
    return(moyenne);
}