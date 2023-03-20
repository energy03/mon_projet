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

#endif