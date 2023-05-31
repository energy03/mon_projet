#ifndef INTERFACE_H
#define INTERFACE_H

#include "cartes.h"
#include "joueuses.h"

/*
Fonction pour afficher toutes les informations du jeu
*/
void afficher_informations(); //-----

/*
Fonction pour demander à une joueuse combien de capital elle veut utiliser  
*/
int demander_capital_joueuse(joueuse joueuse); //-------


/*
Fonction pour demander à une joueuse sur quelle zone elle veut jouer
*/
int demander_zone_joueuse(joueuse joueuse) ;


/*
Fonction pour demander à une joueuse si elle veut jouer une carte et si oui, laquelle
Si elle ne désire pas jouer une carte, on retourne NULL
on affichera le joueur a qui c'est le tour
*/
carte demander_carte_joueuse();

/*
Fonction pour afficher un message quand le jeu est fini
*/
void afficher_fin_jeu();

/*
Fonction pour afficher si un membre a été mangé
*/
void afficher_membre_mange(personnage personnage);

/*
Fonction pour afficher si un membre a été déplacé
*/
void afficher_membre_deplace(personnage personnage);

/// @brief initialisation de l'interface
void init_interface();

/// @brief liberation de l'interface
void free_interface();

/// @brief déplacement des personnages et des monstres
void deplacement();

/// @brief appliquer les effets des deplacements
// Les personages qui sont dans la meme zone que les monstres sont mangés
// Le tableau des personnages de la zone est mis à jour : la première case du tableau est occupée par le monstre et les autres cases sont mises à NULL
void apply_effet_deplacement();


#endif
