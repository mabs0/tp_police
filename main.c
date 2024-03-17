#include "fonctions.h"

int lire_num(char ***liste) { // définie la fonction pour lire les caractères dans le fichier désordonné
    FILE* releve_tel = fopen("releve_tel.txt", "r"); // ouvre le fichier
    if (releve_tel == NULL) { // si il y a un problème
        printf("Erreur lors de l'ouverture du fichier releve_tel.\n"); // printf l'erreur
        return 1;
    }

    *liste = (char**)malloc(MAX_I * sizeof(char*)); // alloue la mémoire
    if (*liste == NULL) { // si problème
        perror("Erreur lors de l'allocation de mémoire"); // printf l'erreur
        return 1;
    }

    for (int i = 0; i < MAX_I; i++) { // pour chaque ligne
        (*liste)[i] = (char*)malloc(100 * sizeof(char)); // alloue la mémoire
        if ((*liste)[i] == NULL) { // si problème
            perror("Erreur lors de l'allocation de mémoire"); // printf l'erreur
            return 1;
        }
        fgets((*liste)[i], 100, releve_tel); // récupère les lignes
    }

    fclose(releve_tel); // ferme le fichier

    return 0;
}


int ecrire_num(char **liste, int taille) { // définie la fonction pour écrire dans le fichier de tri
    FILE* releve_tel_trie = NULL;

    releve_tel_trie = fopen("releve_tel_trie.txt", "w"); // ouvre le fichier
    if (releve_tel_trie == NULL) { // si problème
        printf("Erreur lors de l'ouverture du fichier releve_tel_trie.\n"); // printf l'erreur
        return 1;
    }

    for (int i = 0; i < taille; i++) { // pour chaque lignes
        fprintf(releve_tel_trie, "%s", liste[i]); // printf les caract_ères
    }

    fclose(releve_tel_trie); // ferme le fichier

    return 0;
}

int main() {
    char **liste; // caractérise la liste
    int choix; // intialise le choix pour le menu

    printf("\nMenu :\n" // affiche le menu
           "1) Tri bulle\n"
           "2) Tri par insertion\n"
           "3) Historigramme\n");
    fflush(stdin); // vide l'entrée clavier
    scanf("%d", &choix); // scane le choix

    if(choix<1 || choix>3) {
        printf("Veuillez choisir une option valable");
    }

    switch (choix) { // en fonction du choix
        case 1:
            start_timer(); // débute le timer

            lire_num(&liste); // appelle la fonction pour lire les caractères

            tri_bulle(liste, MAX_I); // appelle la fonction pour le tri bulle

            ecrire_num(liste, MAX_I); // appelle la fonction pour écrire dans le fichier trié

            printf("\n\n");
            stop_timer(); // arrête le timer

            for (int i = 0; i < MAX_I; i++) { // pour chaque ligne
                free(liste[i]); // libère la mémoire
            }

        case 2:
            start_timer(); // débute le timer

            lire_num(&liste); // appelle la fonction pour lire les caractères

            tri_insertion(liste, MAX_I); // appelle la fonction pour le tri bulle

            ecrire_num(liste, MAX_I); // appelle la fonction pour écrire dans le fichier trié

            printf("\n\n");
            stop_timer(); // arrête le timer

            for (int i = 0; i < MAX_I; i++) { // pour chaque ligne
                free(liste[i]); // libère la mémoire
            }
        case 3 :
            start_timer(); //débute le timer

            lire_num(&liste); // appelle la fonction pour lire les caractères

            histogramme(liste);

            stop_timer(); //finit le timer et affiche le temps pris

            for (int i = 0; i < MAX_I; i++) { // pour chaque ligne
                free(liste[i]); // libère la mémoire
            }
    }

    free(liste); // libère la liste

    return 0;
}

