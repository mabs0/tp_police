#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_I 1000

typedef struct comptageHistorigramme {
    char nom;
    int apparitions;
} t_comptageHistorigramme;

#ifndef TP_ETUDE_DE_CAS_FONCTIONS_H
#define TP_ETUDE_DE_CAS_FONCTIONS_H
void start_timer();
void stop_timer();
void tri_bulle(char **liste, int taille);
void tri_insertion(char **liste, int taille);
void historigramme (char **liste);
#endif //TP_ETUDE_DE_CAS_FONCTIONS_H
