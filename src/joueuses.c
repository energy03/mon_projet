#include "../headers/joueuses.h"

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
    char* nom[20]; // nom de la joueuse
    int capital; // capital de la joueuse
    int nb_membres; // nombre de membres de la joueuse
    personnage* membres[10]; // tableau de pointeurs sur les personnages de la joueuse
    int nb_cartes; // nombre de cartes de la joueuse
    carte* cards[10]; // tableau de pointeurs sur les cartes de la joueuse
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
    strcmp(player->nom, nom);
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
