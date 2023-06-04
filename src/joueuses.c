#include "../headers/joueuses.h"
#include "../headers/constantes.h"
#include "../headers/globals.h"
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
    personnage membres[10]; // tableau de pointeurs sur les personnages de la joueuse
    int nb_cartes; // nombre de cartes de la joueuse
    carte cards[10]; // tableau des cartes des joueuses
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

/// @brief recupération du nombre de cartes d'une joueuse
/// @param player pointeur sur la joueuse
/// @return nombre de cartes de la joueuse
int get_nb_cartes_joueuse(joueuse player)
{
    return player->nb_cartes;
}

/// @brief recupération du tableau des personnages d'une joueuse
/// @param player pointeur sur la joueuse
/// @return tableau des personnages de la joueuse
personnage* get_membres_joueuse(joueuse player)
{
    return player->membres;
}

/// @brief recupération du tableau des cartes d'une joueuse
/// @param player pointeur sur la joueuse
/// @return tableau des cartes de la joueuse
carte* get_cartes_joueuse(joueuse player)
{
    return player->cards;
}

/// @brief recupération du tour d'une joueuse
/// @param player pointeur sur la joueuse
/// @return tour de la joueuse
int get_tour_joueuse(joueuse player)
{
    return player->tour;
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

/// @brief modification du tableau des personnages d'une joueuse
/// @param player pointeur sur la joueuse
/// @param membres nouveau tableau des personnages de la joueuse
void set_membres_joueuse(joueuse player, personnage* membres,int nb_membres)
{
    for (int i = 0; i < nb_membres; i++)
    {
        player->membres[i] = membres[i];
    }
    set_nb_membres_joueuse(player,nb_membres);
}

/// @brief modification du tableau des cartes d'une joueuse
/// @param player pointeur sur la joueuse
/// @param cartes nouveau tableau des cartes de la joueuse
void set_cartes_joueuse(joueuse player, carte* cartes,int nb_cartes)
{
    for (int i = 0; i < nb_cartes; i++)
    {
        player->cards[i] = cartes[i];
    }
    set_nb_cartes_joueuse(player,nb_cartes);
}

/// @brief modification du tour d'une joueuse
/// @param player pointeur sur la joueuse
/// @param tour nouveau tour de la joueuse
void set_tour_joueuse(joueuse player, int tour)
{
    player->tour = tour;
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
    (*joueuse1)->nb_membres = 0;
    // (*joueuse1)->membres = NULL;
    (*joueuse1)->nb_cartes = 0;
    // (*joueuse1)->cards = NULL;
    (*joueuse1)->tour = 0;
    set_nom_joueuse(*joueuse1,"Joueuse 1");
    
    (*joueuse2)->capital = CAPITAL_DEBUT_TOUR;
    // (*joueuse2)->nom = NULL;
    (*joueuse2)->nb_membres = 0;
    // (*joueuse2)->membres = NULL;
    (*joueuse2)->nb_cartes = 0;
    // (*joueuse2)->cards = NULL;
    (*joueuse2)->tour = 0;
    set_nom_joueuse(*joueuse2,"Joueuse 2");
}

// Fonction pour libérer la mémoire allouée lors de la création des joueuses
void liberermemoire(joueuse* joueuse1, joueuse* joueuse2) {
    free(*joueuse1);
    free(*joueuse2);
}

/// @todo Fonction qui indique la joueuse dont c'est le tour
joueuse joueuse_tour(joueuse joueuse1, joueuse joueuse2) {
    return TOUR%2 == 1 ? joueuse1 : joueuse2;
}

// Fonction qui renvoie l'ensemble des membres de l'école d'une joueuse
personnage* membres_joueurs(joueuse j) {
    return j->membres;
}

// Fonction qui renvoie le nombre de membres de l'école d'une joueuse
int nb_joueurs_ecoles(joueuse j) {
    return j->nb_membres;
}

// Fonction qui vérifie si tous les membres d'école d'une joueuse ont été mangés
int verifie_manges(joueuse joueuse) {
    int nb_manges = 0;
    int nb_membres = joueuse->nb_membres;
    for (int i = 0; i < nb_membres; i++) {
        if (isEaten(joueuse->membres[i])) {
            nb_manges++;
        }
    }
    return nb_manges == nb_membres;
}

// Fonction pour réinitialiser le capital d'une joueuse
void reinitialiser_capital(joueuse joueuse) {
    joueuse->capital = 5;
}

// Fonction pour utiliser un certain montant du capital d'une joueuse
void utiliser_capital(joueuse joueuse, int montant) {
    joueuse->capital -= montant;
}

// Fonction pour permettre à une joueuse de jouer une carte
void jouer_carte(joueuse joueuse, int carte) {
    printf("Joueuse %s joue carte %d\n", joueuse->nom, carte);
    switch (carte)
    {
    case 1:
        break;
    
    default:
        break;
    }
    // On utilise un index pour savoir quelle carte est jouée
    
}