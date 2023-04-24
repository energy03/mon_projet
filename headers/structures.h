// Protection contre les inclusions multiples
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "cartes.h"
// structures.h
#include <stdlib.h>
#include "cartes.h"

typedef struct CarteStruct {
    int valeur;
    const char *couleur;
} CarteStruct;



typedef struct ListeCartes ListeCartes;
/**
 * @brief Crée et initialise une nouvelle liste de cartes.
 * @assigns * \return Un pointeur vers une nouvelle liste de cartes allouée dynamiquement.
 * @ensures La liste retournée est non nulle et vide, avec une capacité initiale de 10 cartes.
 */
ListeCartes *creer_liste_cartes();
/**
 * @brief Supprime et libère la mémoire allouée pour une liste de cartes.
 * @param liste La liste de cartes à supprimer.
 * @requires liste doit être un pointeur valide vers une ListeCartes.
 * @assigns * Libère la mémoire allouée pour la liste de cartes et ses éléments.
 * @ensures La mémoire allouée pour la liste de cartes et ses éléments est libérée.
 */
void supprimer_liste_cartes(ListeCartes *liste);

/**
 * @brief Ajoute une carte à la liste de cartes.
 * @param liste La liste de cartes à laquelle ajouter la carte.
 * @param carte La carte à ajouter à la liste.
 * @requires liste doit être un pointeur valide vers une ListeCartes.
 * @assigns * Ajoute la carte à la liste et augmente sa capacité si nécessaire.
 * @ensures La carte est ajoutée à la fin de la liste de cartes.
 */
void ajouter_carte(ListeCartes *liste, CarteStruct carte);

/**
 * @brief Retire une carte de la liste de cartes à un index spécifié.
 * @param liste La liste de cartes de laquelle retirer la carte.
 * @param index L'index de la carte à retirer.
 * @requires liste doit être un pointeur valide vers une ListeCartes.
 * @requires index doit être un entier valide compris entre 0 et nombre-1, où nombre est le nombre de cartes dans la liste.
 * @assigns * Retire la carte à l'index spécifié de la liste de cartes.
 * @ensures La carte à l'index spécifié est retirée de la liste et la taille de la liste est réduite de 1.
 */
void retirer_carte(ListeCartes *liste, int index);

/**
 * @brief Obtient une copie d'une carte dans la liste de cartes à un index spécifié.
 * @param liste La liste de cartes de laquelle obtenir la carte.
 * @param index L'index de la carte à obtenir.
 * @requires liste doit être un pointeur valide vers une ListeCartes.
 * @requires index doit être un entier valide compris entre 0 et nombre-1, où nombre est le nombre de cartes dans la liste.
 * @return Une copie de la carte à l'index spécifié dans la liste de cartes.
 */
CarteStruct obtenir_carte(const ListeCartes *liste, int index);



void calculer_et_afficher_probabilites(ListeCartes *liste);


// Définition des structures pour la liste de cartes et la matrice de probabilités

typedef struct MatriceProbabilites MatriceProbabilites;

// Fonctions pour gérer la MatriceProbabilites
/**
 * @brief Crée et initialise une nouvelle matrice de probabilités.
 * @param lignes Le nombre de lignes de la matrice.
 * @param colonnes Le nombre de colonnes de la matrice.
 * @requires lignes et colonnes doivent être des entiers positifs.
 * @assigns * \return Un pointeur vers une nouvelle matrice de probabilités allouée dynamiquement.
 * @ensures La matrice retournée est non nulle, avec le nombre de

* lignes et colonnes spécifiés, et toutes les valeurs sont initialisées à 0.0.
 */

MatriceProbabilites *creer_matrice_probabilites(int lignes, int colonnes);
/**
 * @brief Supprime et libère la mémoire allouée pour une matrice de probabilités.
 * @param matrice_probabilites La matrice de probabilités à supprimer.
 * @requires matrice_probabilites doit être un pointeur valide vers une MatriceProbabilites.
 * @assigns * Libère la mémoire allouée pour la matrice de probabilités et ses éléments.
 * @ensures La mémoire allouée pour la matrice de probabilités et ses éléments est libérée.
 */
void supprimer_matrice_probabilites(MatriceProbabilites *matrice_probabilites);

/**
 * @brief Définit la valeur d'un élément dans la matrice de probabilités à une ligne et colonne spécifiées.
 * @param matrice_probabilites La matrice de probabilités dont on souhaite modifier une valeur.
 * @param ligne La ligne de l'élément à modifier.
 * @param colonne La colonne de l'élément à modifier.
 * @param valeur La nouvelle valeur à attribuer à l'élément.
 * @requires matrice_probabilites doit être un pointeur valide vers une MatriceProbabilites.
 * @requires ligne et colonne doivent être des entiers valides compris entre 0 et nombre-1, où nombre est le nombre de lignes et colonnes dans la matrice.
 * @assigns * Modifie la valeur de l'élément à la ligne et colonne spécifiées.
 * @ensures L'élément à la ligne et colonne spécifiées a maintenant la valeur donnée.
 */

void definir_valeur_matrice_probabilites(MatriceProbabilites *matrice_probabilites, int ligne, int colonne, double valeur);

/**
 * @brief Obtient la valeur d'un élément dans la matrice de probabilités à une ligne et colonne spécifiées.
 * @param matrice_probabilites La matrice de probabilités dont on souhaite obtenir une valeur.
 * @param ligne La ligne de l'élément à obtenir.
 * @param colonne La colonne de l'élément à obtenir.
 * @requires matrice_probabilites doit être un pointeur valide vers une MatriceProbabilites.
 * @requires ligne et colonne doivent être des entiers valides compris entre 0 et nombre-1, où nombre est le nombre de lignes et colonnes dans la matrice.
 * @return La valeur de l'élément à la ligne et colonne spécifiées.
 */

double obtenir_valeur_matrice_probabilites(const MatriceProbabilites *matrice_probabilites, int ligne, int colonne);



#endif // STRUCTURES_H
