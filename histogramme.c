
#include "fonctions.h"

int trouver_ou_ajouter(compteurNoms* liste, int* numNoms, char* nom) {
    for (int i = 0; i < *numNoms; i++) {
        if (strcmp(liste[i].nom, nom) == 0) {
            liste[i].compteur++;
            return i;
        }
    }
    // si le nom n'a pas été trouvé, l'ajouter à la liste
    strcpy(liste[*numNoms].nom, nom);
    liste[*numNoms].compteur = 1;
    (*numNoms)++;
    return *numNoms - 1;
}


int histogramme() {
    char ligne[100]; // Taille maximale de chaque ligne
    char nom[MAX_NAME_LENGTH];
    compteurNoms compteurNoms[MAX_I]; // liste des noms et de leurs occurrences
    int numNoms = 0;

    FILE* releve_tel = fopen("releve_tel.txt", "r"); // ouvre le fichier
    if (releve_tel == NULL) { // si il y a un problème
        printf("Erreur lors de l'ouverture du fichier releve_tel.\n"); // printf l'erreur
        return 1;
    }


    while (fgets(ligne, sizeof(ligne), releve_tel)) {

        sscanf(ligne, "%s", nom);

        trouver_ou_ajouter(compteurNoms, &numNoms, nom);
    }

    fclose(releve_tel);

    printf("Histogramme des noms :\n");
    for (int i = 0; i < numNoms; i++) {
        printf("%s : ", compteurNoms[i].nom);
        for (int j = 0; j < compteurNoms[i].compteur; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
