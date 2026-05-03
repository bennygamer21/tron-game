#include <stdio.h>
#include "score.h"

int score1 = 0, score2 = 0;



int main () {

    loadScore(&score1, &score2);

    printf("Score: %d - %d\n", score1, score2);

    return 0;
}