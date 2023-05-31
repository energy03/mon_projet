#include <stdlib.h>
#include <string.h>
#include "../headers/personnages.h"
#include "../headers/zones.h"
#include "../headers/globals.h"
#include "../headers/structures.h"




/*****************************************
 * ***************************************
 * ***************************************
 *  debut     TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/


/// @brief enregistrement personnage qui contient les informations sur un personnage
struct personnage{
    char nom[41]; // nom du personnage
    RolePerso role; // MONSTRE ou MEMBRE
    Filiere filiere; // FISE ou FISA s'il s'agit d'un membre d'école
    int zone_perso; // zone où se trouve le personnage
    Vie_Perso vie; // VIVANT ou MANGE s'il s'agit d'un personnage d'école
};

// getters

/// @brief recuperation du nom d'un personnage
/// @param perso pointeur sur le personnage
/// @return nom du personnage
char* get_nom_personnage(personnage perso){
    return perso->nom;
}

/// @brief recuperation de la filière d'un personnage
/// @param perso pointeur sur le personnage
/// @return filière du personnage
Filiere get_filiere_personnage(personnage perso){
    return perso->filiere;
}


/// @brief recuperation de la vie d'un personnage
/// @param perso pointeur sur le personnage
/// @return vie du personnage
Vie_Perso get_vie_personnage(personnage perso){
    return perso->vie;
}

/// @brief recuperation du role d'un personnage
/// @param perso pointeur sur le personnage
/// @return role du personnage
RolePerso get_role_personnage(personnage perso){
    return perso->role;
}

/// @brief recuperation de la zone d'un personnage
/// @param perso pointeur sur le personnage
/// @return zone du personnage
int get_zone_personnage(personnage perso){
    return perso->zone_perso;
}

// setters

/// @brief modification du nom d'un personnage
/// @param perso pointeur sur le personnage
/// @param nom nouveau nom du personnage
void set_nom_personnage(personnage perso, char* nom){
    strcpy(perso->nom, nom);
}

/// @brief modification de la filière d'un personnage
/// @param perso pointeur sur le personnage
/// @param filiere nouvelle filière du personnage
void set_filiere_personnage(personnage perso, Filiere filiere){
    perso->filiere = filiere;
}

/// @brief modification de la vie d'un personnage
/// @param perso pointeur sur le personnage
/// @param vie nouvelle vie du personnage
void set_vie_personnage(personnage perso, Vie_Perso vie){
    perso->vie = vie;
}

/// @brief modification du role d'un personnage
/// @param perso pointeur sur le personnage
/// @param role nouveau role du personnage
void set_role_personnage(personnage perso, RolePerso role){
    perso->role = role;
}

/// @brief modification de la zone d'un personnage
/// @param perso pointeur sur le personnage
/// @param zone nouvelle zone du personnage
void set_zone_personnage(personnage perso, int zone){
    perso->zone_perso = zone;
}




/**************************************************
 * ************************************************
 * ************************************************
 * fin   TACHE B5
 * ************************************************
 * ************************************************
 * ************************************************
*/

// Création d'un personnage (membre d'école ou monstre)
personnage createPerso(RolePerso Mo_Me,char* nom,Filiere filiere) {
    personnage newPerso = malloc(sizeof(struct personnage));
    newPerso->role = Mo_Me;
    newPerso->filiere = filiere; // À ajuster en fonction de la logique du jeu
    newPerso->vie = VIVANT;
    strcpy(newPerso->nom, nom);

    return newPerso;
}

// Libération de la mémoire allouée pour la création du personnage
void freePerso(personnage* perso) {
    free(*perso);
}

// Déplacer un personnage dans une zone
/// @todo à compléter
void movePerso(personnage perso, int zone_coord) {
    zone anc_zone = getZoneById(ZONES, perso->zone_perso);
    zone nouv_zone = getZoneById(ZONES, zone_coord);
    int nb_perso_anc_zone = get_nb_perso_zone(anc_zone);
    int nb_perso_nouv_zone = get_nb_perso_zone(nouv_zone);
    personnage * tab_pers=get_tab_perso_zone(anc_zone);
    remove_element((void**)tab_pers ,(void*)perso, &nb_perso_anc_zone);
    set_nb_perso_zone(anc_zone, nb_perso_anc_zone);
    personnage * tab_pers_1= get_tab_perso_zone(nouv_zone);
    add_element((void**)tab_pers_1 , (void*)perso , &nb_perso_nouv_zone);
    perso->zone_perso = zone_coord;
    set_nb_perso_zone(nouv_zone, nb_perso_nouv_zone);
}

// Récupérer la zone dans laquelle se situe un personnage
int getZonePerso(personnage perso) {
    return perso->zone_perso;
}

// Indiquer à un membre d'école qu'il a été mangé
int isEaten(personnage perso) {
    return perso->vie == MANGE;
}