
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_I 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char nom[MAX_NAME_LENGTH];
    int compteur;
} compteurNoms;

#ifndef TP_ETUDE_DE_CAS_FONCTIONS_H
#define TP_ETUDE_DE_CAS_FONCTIONS_H
void start_timer();
void stop_timer();
void tri_bulle(char **liste, int taille);
void tri_insertion(char **liste, int taille);
int rand();
int histogramme();
#endif //TP_ETUDE_DE_CAS_FONCTIONS_H
