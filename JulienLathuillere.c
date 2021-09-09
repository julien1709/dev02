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
    gettimeofday(&debutCalcul ,NULL);

    // Refaire le calcul 10000 fois pour augmenter la durée de calcul
    for( j = 0; j < 10000; j++) {
        moyenne = normaliseCapteur(valCapteur);
    }

    // Heure fin du calcul
    gettimeofday(&finCalcul,NULL);

    printf("La moyenne des valeurs : %d\n", moyenne);

    duree = ((finCalcul.tv_sec - debutCalcul.tv_sec) * 1000000) + (finCalcul.tv_usec - debutCalcul.tv_usec);
    printf( "Durée %ld ms\n", duree );  
}

int intcmp(const void *aa, const void *bb) {
    const int *a = aa, *b = bb;
    return (*a < *b) ? -1 : (*a > *b);
}

int getRealAverage(int total) {
    int moyenne = total / 4;
    return(moyenne);
}

int normaliseCapteur( int valCapteur[8]) {
    int total=0;
    int moyenne;

    qsort(valCapteur, 8, sizeof(int), intcmp);

    //total = 0;
    for( int i = 2; i < 6; i++) {
        total += valCapteur[i];
    }

    moyenne = getRealAverage(total);

    return(moyenne);
}