#include "fonctions.h"

int find_or_add(NameCount* liste, int* numNames, char* name) {
    for (int i = 0; i < *numNames; i++) {
            if (strcmp(liste[i].name, name) == 0) {
                liste[i].count++;
                return i;
        }
    }
    // si le nom n'a pas été trouvé, l'ajouter à la liste
    strcpy(liste[*numNames].name, name);
    liste[*numNames].count = 1;
    (*numNames)++;
    return *numNames - 1;
}


int histogramme() {
    char line[100]; // Taille maximale de chaque ligne
    char name[MAX_NAME_LENGTH];
    NameCount nameCounts[MAX_I]; // liste des noms et de leurs occurrences
    int numNames = 0;

    FILE* releve_tel = fopen("releve_tel.txt", "r"); // ouvre le fichier
    if (releve_tel == NULL) { // si il y a un problème
        printf("Erreur lors de l'ouverture du fichier releve_tel.\n"); // printf l'erreur
        return 1;
    }


    while (fgets(line, sizeof(line), releve_tel)) {

        sscanf(line, "%s", name);

        find_or_add(nameCounts, &numNames, name);
    }

    fclose(releve_tel);

    printf("Histogramme des noms :\n");
    for (int i = 0; i < numNames; i++) {
        printf("%s : ", nameCounts[i].name);
        for (int j = 0; j < nameCounts[i].count; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
