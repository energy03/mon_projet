#include "../headers/joueuses.h"
#include "../headers/constantes.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

/*****************************************
 * ***************************************
 * ***************************************
 *    debut   TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/

/// @brief enregistrement joueuses qui contient les informations sur une joueuse
struct joueuse
{
    char nom[20]; // nom de la joueuse
    int capital; // capital de la joueuse
    int nb_membres; // nombre de membres de la joueuse
    personnage* membres[10]; // tableau de pointeurs sur les personnages de la joueuse
    int nb_cartes; // nombre de cartes de la joueuse
    carte cards[10]; // tableau de pointeurs sur les cartes de la joueuse
    int tour;   // 1 si c'est le tour de la joueuse, 0 sinon
};

// getters

/// @brief recupération du nom d'une joueuse
/// @param player pointeur sur la joueuse
/// @return nom de la joueuse
char* get_nom_joueuse(joueuse player)
{
    return player->nom;
}

/// @brief recupération du capital d'une joueuse
/// @param player pointeur sur la joueuse
/// @return capital de la joueuse
int get_capital_joueuse(joueuse player)
{
    return player->capital;
}


/// @brief recupération du nombre de membres d'une joueuse
/// @param player pointeur sur la joueuse
/// @return nombre de membres de la joueuse
int get_nb_membres_joueuse(joueuse player)
{
    return player->nb_membres;
}


///setters

/// @brief modification du nom d'une joueuse
/// @param player pointeur sur la joueuse
/// @param nom nouveau nom de la joueuse
void set_nom_joueuse(joueuse player, char* nom)
{
    strcpy(player->nom, nom);
} 

/// @brief modification du capital d'une joueuse
/// @param player pointeur sur la joueuse
/// @param capital nouveau capital de la joueuse
void set_capital_joueuse(joueuse player, int capital)
{
    player->capital = capital;
}

/// @brief modification du nombre de membres d'une joueuse
/// @param player pointeur sur la joueuse
/// @param nb_membres nouveau nombre de membres de la joueuse
void set_nb_membres_joueuse(joueuse player, int nb_membres)
{
    player->nb_membres = nb_membres;
}

/// @brief modification du nombre de cartes d'une joueuse
/// @param player pointeur sur la joueuse
/// @param nb_cartes nouveau nombre de cartes de la joueuse
void set_nb_cartes_joueuse(joueuse player, int nb_cartes)
{
    player->nb_cartes = nb_cartes;
}

/*****************************************
 * ***************************************
 * ***************************************
 *    fin   TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/

void creer_joueuses(joueuse* joueuse1, joueuse* joueuse2) {
    *joueuse1 = malloc(sizeof(struct joueuse));
    *joueuse2 = malloc(sizeof(struct joueuse));
    
    // Initialisation des attributs des joueuses
    (*joueuse1)->capital = CAPITAL_DEBUT_TOUR;
    // (*joueuse1)->nom = NULL;
    (*joueuse1)->nb_membres = NB_MEMBRES_PAR_JOUEUSE;
    // (*joueuse1)->membres = NULL;
    (*joueuse1)->nb_cartes = NB_CARTES_MAIN_DEBUT;
    // (*joueuse1)->cards = NULL;
    (*joueuse1)->tour = 0;
    
    (*joueuse2)->capital = CAPITAL_DEBUT_TOUR;
    // (*joueuse2)->nom = NULL;
    (*joueuse2)->nb_membres = NB_MEMBRES_PAR_JOUEUSE;
    // (*joueuse2)->membres = NULL;
    (*joueuse2)->nb_cartes = NB_CARTES_MAIN_DEBUT;
    // (*joueuse2)->cards = NULL;
    (*joueuse2)->tour = 1;
}

// Fonction pour libérer la mémoire allouée lors de la création des joueuses
void liberermemoire(joueuse* joueuse1, joueuse* joueuse2) {
    free(*joueuse1);
    free(*joueuse2);
}

// Fonction qui indique la joueuse dont c'est le tour
joueuse* joueuse_tour(joueuse* joueuse1, joueuse* joueuse2) {
    // Implémentation dépendante de la manière dont le tour est déterminé
    // Exemple : si un booléen 'tour' est présent dans la structure joueuse
    if ((*joueuse1)->tour == 1) {
        (*joueuse1)->tour = 0;
        (*joueuse2)->tour = 1;
        return joueuse1;
    } else {
        (*joueuse1)->tour = 1;
        (*joueuse2)->tour = 0;
        return joueuse2;
    }
}

// Fonction qui renvoie l'ensemble des membres de l'école d'une joueuse
personnage** membres_joueurs(joueuse* j) {
    return (*j)->membres;
}

// Fonction qui renvoie le nombre de membres de l'école d'une joueuse
int nb_joueurs_ecoles(joueuse* j) {
    return (*j)->nb_membres;
}

// Fonction qui vérifie si tous les membres d'école d'une joueuse ont été mangés
int verifie_manges(joueuse* joueuse) {
    int cpt = 0; 
    for (int i = 0; i < (*joueuse)->nb_membres; i++) {
        // if ((*joueuse)->membres[i]->mange) {
        //     cpt++;
        // }
    }
    //Si tous les membres sont mangés, on renvoie 1, sinon on renvoie 0
    int res = 0;
    if(cpt==0){
        res = 1;
    }
    return res;
}

// Fonction pour réinitialiser le capital d'une joueuse
void reinitialiser_capital(joueuse* joueuse) {
    (*joueuse)->capital = 0;
}

// Fonction pour utiliser un certain montant du capital d'une joueuse
void utiliser_capital(joueuse* joueuse, int montant) {
    (*joueuse)->capital -= montant;
    if ((*joueuse)->capital < 0) {
        (*joueuse)->capital = 0;
    }
}

// Fonction pour permettre à une joueuse de jouer une carte
void jouer_carte(joueuse* joueuse, carte* carte) {
    // On utilise un index pour savoir quelle carte est jouée
    int index = -1;
    for (int i = 0; i < (*joueuse)->nb_cartes; i++) {
        if ((*joueuse)->cards[i] == *carte) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Appliquer l'effet de la carte sur les joueurs et/ou personnages
        // en fonction de la logique du jeu

        // Exemple : si on suppose que la carte a une fonction 'appliquer_effet' qui prend en paramètre les joueuses
        // appliquer_effet(carte, *joueuse, index == 0 ? *joueuse2 : *joueuse1);

        // Retirer la carte de la main du joueur
        for (int i = index; i < (*joueuse)->nb_cartes - 1; i++) {
            (*joueuse)->cards[i] = (*joueuse)->cards[i + 1];
        }
        (*joueuse)->nb_cartes--;
    } else {
        // La carte n'est pas dans la main du joueur, on ne fait rien
    }
}