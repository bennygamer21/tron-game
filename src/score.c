#include <stdio.h>
#include "score.h"

void saveScore(int p1, int p2) {
    FILE *f = fopen("score.txt", "w");
    if (f != NULL) {
        fprintf(f, "%d %d", p1, p2);
        fclose(f);
    }
}


void loadScore(int *p1, int *p2) {
    FILE *f = fopen("score.txt", "r");


    if (f != NULL) {
        fscanf(f, "%d %d", p1, p2);
        fclose(f);
    } else {
        // Si no existe el archivo
        *p1 = 0;
        *p2 = 0;
    }
}