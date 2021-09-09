#include <stdio.h>
#include <sys/time.h>

int normaliseCapteur( int valCapteur[8] );

int main(void)
{
    int valCapteur[8] = { 2, 56, 180, 60, 10, 1020, 65, 55 };
    int moyenne;

    int j;
    unsigned long duree;
    struct timeval debutCalcul, finCalcul;

    // Heure debut du calcul
    gettimeofday(&debutCalcul,NULL);

    // Refaire le calcul 10000 fois pour augmenter la durée de calcul
    for( j = 0; j < 10000; j++) {
        moyenne = normaliseCapteur(valCapteur);
    }

    // Heure fin du calcul
    gettimeofday(&finCalcul,NULL);

    printf("moyenne %d\n", moyenne);

    duree = ((finCalcul.tv_sec - debutCalcul.tv_sec) * 1000000) + (finCalcul.tv_usec - debutCalcul.tv_usec);
    printf( "Durée %ld ms\n", duree );  
}

int normaliseCapteur( int valCapteur[8] )
{
    int i;
    int total=0;
    int moyenne;

    total = 0;
    for( i = 0; i < 8; i++) {
        total += valCapteur[i];
    }
    moyenne = total / 8;

    return(moyenne);
}