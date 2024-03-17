#include "fonctions.h"

void tri_bulle(char **liste, int taille) {
    int i, j;
    char temp[100];
    for (i = 0; i < taille-1; i++) {
        for (j = 0; j < taille-i-1; j++) {
            if (strcmp(liste[j], liste[j+1]) > 0) {
                strcpy(temp, liste[j]);
                strcpy(liste[j], liste[j+1]);
                strcpy(liste[j+1], temp);
            }
        }
    }
}