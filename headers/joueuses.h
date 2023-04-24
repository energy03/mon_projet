#ifndef joueuseS_H
#define joueuseS_H

#include "cartes.h"
#include "personnages.h"

// Définition du type joueuse
typedef struct joueuse *joueuse;

//fonction pour créer les deux joueurs
/*@ requires  
  assigns *
  ensures  */
void creer_joueuses(joueuse* joueuse1, joueuse* joueuse2);

//fonction pour libérer la mémoire 
/*@ requires  
  assigns *
  ensures */

void liberermemoire(joueuse* joueuse1, joueuse* joueuse2);
//fonction qui indique la joueuse dont c'est le tour 
/*@ requires  
  assigns *
  ensures  */
joueuse*  joueuse_tour(joueuse* joueuse1, joueuse* joueuse2);

personnage** membres_joueurs(joueuse* j);//retourne un tableau de joueuse
//fonction qui renvoie l'ensemble des membres de l'école d'une joueuse

  
//une fonction qui renvoie le nombre de membres de l'école d'une joueuse
/*@ requires  
  assigns *
  ensures  */
int nb_joueurs_ecoles( joueuse* j);

//fonction qui vérifie si tous les membres d'école d'une joueuse ont été mangés

int verifie_manges(joueuse* joueuse);

//fonction pour rénitialiser le capital d'une joueuse

void reinitialiser_capital(joueuse* joueuse);

// Fonction pour utiliser un certain montant du capital d'une joueuse
void utiliser_capital(joueuse* joueuse, int montant);

// Fonction pour permettre à une joueuse de jouer une carte
void jouer_carte(joueuse* joueuse, carte* carte);

/*****************************************
 * ***************************************
 * ***************************************
 *       TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/

/// @brief recupération du nom d'une joueuse  
/// @param player pointeur sur la joueuse
/// @return nom de la joueuse
char* get_nom_joueuse(joueuse player);

/// @brief recupération du capital d'une joueuse
/// @param player pointeur sur la joueuse
/// @return capital de la joueuse
int get_capital_joueuse(joueuse player);

/// @brief recupération du nombre de membres d'une joueuse


/// getters
/// @brief recupération du nom d'une joueuse
/// @param player pointeur sur la joueuse
/// @return nombre de membres de la joueuse
char* get_nom_joueuse(joueuse player);

/// @brief recupération du nombre de cartes d'une joueuse
/// @param player pointeur sur la joueuse
/// @return nombre de cartes de la joueuse
int get_nb_cartes_joueuse(joueuse player);

/// @brief recupération du nombre de membres d'une joueuse
/// @param player pointeur sur la joueuse
/// @return nombre de membres de la joueuse
int get_nb_membres_joueuse(joueuse player);

/// @brief recupération du nombre de cartes d'une joueuse
/// @param player pointeur sur la joueuse
/// @return nombre de cartes de la joueuse
int get_nb_cartes_joueuse(joueuse player);

// setters

/// @brief modification du nom d'une joueuse
/// @param player pointeur sur la joueuse
/// @param nom nouveau nom de la joueuse
void set_nom_joueuse(joueuse player, char* nom);

/// @brief modification du capital d'une joueuse
/// @param player pointeur sur la joueuse
/// @param capital nouveau capital de la joueuse
void set_capital_joueuse(joueuse player, int capital);

/// @brief modification du nombre de membres d'une joueuse
/// @param player pointeur sur la joueuse
/// @param nb_membres nouveau nombre de membres de la joueuse
void set_nb_membres_joueuse(joueuse player, int nb_membres);

/// @brief modification du nombre de cartes d'une joueuse
/// @param player pointeur sur la joueuse
/// @param nb_cartes nouveau nombre de cartes de la joueuse
void set_nb_cartes_joueuse(joueuse player, int nb_cartes);

/*****************************************
 * ***************************************
 * ***************************************
 *       TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/

#endif