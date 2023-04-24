// Inclusion des entêtes
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Définition des structures internes

typedef struct ListeCartes {
    CarteStruct *cartes;
    int nombre;
    int capacite;
} ListeCartes;

// Définition de la structure MatriceProbabilites
typedef struct MatriceProbabilites {
    int lignes;      // Nombre de lignes de la matrice
    int colonnes;    // Nombre de colonnes de la matrice
    double **matrice; // Pointeur vers la matrice de probabilités
} MatriceProbabilites;

ListeCartes *creer_liste_cartes() {
    ListeCartes *liste = (ListeCartes *)malloc(sizeof(ListeCartes));
    liste->nombre = 0;
    liste->capacite = 10;

    liste->cartes = (CarteStruct *)malloc(10 * sizeof(CarteStruct));

    return liste;
}


void supprimer_liste_cartes(ListeCartes *liste) {
    free(liste->cartes);
    free(liste);
}

void ajouter_carte(ListeCartes *liste, CarteStruct carte) {
    if (liste->nombre == liste->capacite) {
        liste->capacite *= 2;
        liste->cartes = (CarteStruct *)realloc(liste->cartes, liste->capacite * sizeof(CarteStruct));
    }
    liste->cartes[liste->nombre++] = carte;
}

void retirer_carte(ListeCartes *liste, int index) {
    for (int i = index; i < liste->nombre - 1; ++i) {
        liste->cartes[i] = liste->cartes[i + 1];
    }
    liste->nombre--;
}

CarteStruct obtenir_carte(const ListeCartes *liste, int index) {
    return liste->cartes[index];
}
// Créer une nouvelle MatriceProbabilites
MatriceProbabilites *creer_matrice_probabilites(int lignes, int colonnes) {
    MatriceProbabilites *matrice_probabilites = (MatriceProbabilites *)malloc(sizeof(MatriceProbabilites));
    matrice_probabilites->lignes = lignes;
    matrice_probabilites->colonnes = colonnes;
    matrice_probabilites->matrice = (double **)malloc(lignes * sizeof(double *));
    for (int i = 0; i < lignes; i++) {
        matrice_probabilites->matrice[i] = (double *)calloc(colonnes, sizeof(double));
    }
    return matrice_probabilites;
}

// Supprimer la MatriceProbabilites et libérer la mémoire
void supprimer_matrice_probabilites(MatriceProbabilites *matrice_probabilites) {
    for (int i = 0; i < matrice_probabilites->lignes; i++) {
        free(matrice_probabilites->matrice[i]);
    }
    free(matrice_probabilites->matrice);
    free(matrice_probabilites);
}

// Définir la valeur d'une cellule de la MatriceProbabilites
void definir_valeur_matrice_probabilites(MatriceProbabilites *matrice_probabilites, int ligne, int colonne, double valeur) {
    if (ligne >= 0 && ligne < matrice_probabilites->lignes && colonne >= 0 && colonne < matrice_probabilites->colonnes) {
        matrice_probabilites->matrice[ligne][colonne] = valeur;
    }
}

// Obtenir la valeur d'une cellule de la MatriceProbabilites
double obtenir_valeur_matrice_probabilites(const MatriceProbabilites *matrice_probabilites, int ligne, int colonne) {
    if (ligne >= 0 && ligne < matrice_probabilites->lignes && colonne >= 0 && colonne < matrice_probabilites->colonnes) {
        return matrice_probabilites->matrice[ligne][colonne];
    }
    return -1.0;
}

int main() {
    // Création de la liste de cartes
    ListeCartes *liste = creer_liste_cartes();
    CarteStruct carte1 = {1, "Coeur"};
    CarteStruct carte2 = {2, "Pique"};

    ajouter_carte(liste, carte1);
    ajouter_carte(liste, carte2);

    for (int i = 0; i < liste->nombre; i++) {
        CarteStruct carte = obtenir_carte(liste, i);
        printf("Carte %d: %d de %s\n", i + 1, carte.valeur, carte.couleur);
    }

    supprimer_liste_cartes(liste);

    // Création de la matrice de probabilités
    int lignes = 3;
    int colonnes = 3;
    MatriceProbabilites *matrice_probabilites = creer_matrice_probabilites(lignes, colonnes);

    // Remplissage de la matrice de probabilités avec des valeurs aléatoires
    srand(time(NULL));
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            double valeur = (double)rand() / RAND_MAX;
            definir_valeur_matrice_probabilites(matrice_probabilites, i, j, valeur);
        }
    }

    // Affichage de la matrice de probabilités
    printf("Matrice de probabilités :\n");
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            double valeur = obtenir_valeur_matrice_probabilites(matrice_probabilites, i, j);
            printf("%.2f ", valeur);
        }
        printf("\n");
    }

    // Suppression de la matrice de probabilités
    supprimer_matrice_probabilites(matrice_probabilites);

    return 0;
}



