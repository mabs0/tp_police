#include "fonctions.h"

int rand() {
    srand(time(NULL));

    // Ouvrir le fichier en mode écriture
    FILE *random = fopen("random.txt", "w");
    if (random == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.");
        return 1;
    }

    for (int i = 0; i < 1000; i++) { // pour 1000 entiers
        int entier = rand() % 25; // génère un entier entre 0 et 24
        fprintf(random, "%d\n", entier); // écrit l'entier dans le fichier
    }

    fclose(random);

    return 0;
}
