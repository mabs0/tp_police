//
// Created by barea on 14/03/2024.
//
#include "fonctions.h"

void tri_insertion(char **liste, int taille) {
    int i, j;
    char *cle;
    for (i = 1; i < taille; i++) {
        cle = liste[i];
        j = i - 1;
        while (j >= 0 && strcmp(cle, liste[j]) < 0) {
            liste[j + 1] = liste[j];
            j = j - 1;
        }
        liste[j + 1] = cle;
    }
}