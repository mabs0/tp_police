#include "fonctions.h"

clock_t start_time;

void start_timer() {
    start_time = clock();
}

void stop_timer() {
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Temps ecoule : %.5f secondes\n", elapsed_time);
}


