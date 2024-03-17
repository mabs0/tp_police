#include "fonctions.h"

int iteration(char nom, t_comptageHistogramme tab[MAX_I]){ //permet de vérifier si le nom apparaît déjà dans le tableau
   int j;
    for (j = 0; j < MAX_I; j++){ // parcoure la liste
        if (nom == tab[j].nom) { //signale une itération
            return j; // retourne la position s'il y a déjà une itération
        }
    }
    return 0; // retourne 0 pour signifier qu'il n'y a aucune itération
}

void histogramme (char **liste) {
    t_comptageHistogramme tableau[MAX_I]; //initialise le tableau répertoriant le nombre d'occurences de chaque nom
    int i, j, sommet = 0; //initialise nos variables de comptage et une variable sommet indiquant le nombre de cases remplies dans le tableau
    for (i = 0; i < MAX_I; i++) { //parcoure la liste de 0 à 1000
        j = iteration(*liste[i],tableau); // attribue à j la valeur retourné par la fonction iteration
        if (j!=0) { //si  elle est différente de 0 alors on incrémente le nombre d'apparitions de ce nom
            tableau[j].apparitions++;
        }
        else { //sinon on inscrit ce nom dans notre tableau et on actualise son nombre d'apparition et le nombre de cases remplies dans le tableau
            tableau[sommet].nom = *liste[i];
            tableau[sommet].apparitions = 1;
            sommet++;
        }
    }
    for (j = 0; j < MAX_I; j++) {
        printf("\nNom : %s Apparitions : %d", tableau[j].nom, tableau[j].apparitions); // affiche chaque nom du tableau ainsi que son nombre d'apparitions
    }
}
