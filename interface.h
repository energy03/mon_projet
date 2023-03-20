#ifndef INTERFACE_H
#define INTERFACE_H

#include "cartes.h"
#include "joueuses.h"

/*
Fonction pour afficher toutes les informations du jeu
*/
void afficher_informations();

/*
Fonction pour demander à une joueuse combien de capital elle veut utiliser  
*/
int demander_capital_joueuse(joueuse* joueeuse);

/*
Fonction pour demander à une joueuse si elle veut jouer une carte et si oui, laquelle
Si elle ne désire pas jouer une carte, on retourne NULL
*/
carte* demander_carte_joueuse(joueuse* joueeuse);

/*
Fonction pour afficher un message quand le jeu est fini
*/
void afficher_fin_jeu();

/*
Fonction pour afficher si un membre a été mangé
*/
void afficher_membre_mangE();

/*
Fonction pour afficher si un membre a été déplacé
*/
void afficher_membre_deplacE();


#endif