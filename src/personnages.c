#include "../headers/personnages.h"





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
    RolePerso role; // MONSTRE ou MEMBRE
    Filiere filiere; // FISE ou FISA s'il s'agit d'un membre d'école
    zone* zone_perso; // zone où se trouve le personnage
    Vie_Perso vie; // VIVANT ou MANGE s'il s'agit d'un personnage d'école
};

// getters

/// @brief recuperation de la filière d'un personnage
/// @param perso pointeur sur le personnage
/// @return filière du personnage
Filiere get_filiere_personnage(personnage* perso){
    return perso->filiere;
}


/// @brief recuperation de la vie d'un personnage
/// @param perso pointeur sur le personnage
/// @return vie du personnage
Vie_Perso get_vie_personnage(personnage* perso){
    return perso->vie;
}

/// @brief recuperation du role d'un personnage
/// @param perso pointeur sur le personnage
/// @return role du personnage
RolePerso get_role_personnage(personnage* perso){
    return perso->role;
}

// setters
/// @brief modification de la filière d'un personnage
/// @param perso pointeur sur le personnage
/// @param filiere nouvelle filière du personnage
void set_filiere_personnage(personnage* perso, Filiere filiere){
    perso->filiere = filiere;
}

/// @brief modification de la vie d'un personnage
/// @param perso pointeur sur le personnage
/// @param vie nouvelle vie du personnage
void set_vie_personnage(personnage* perso, Vie_Perso vie){
    perso->vie = vie;
}

/// @brief modification du role d'un personnage
/// @param perso pointeur sur le personnage
/// @param role nouveau role du personnage
void set_role_personnage(personnage* perso, RolePerso role){
    perso->role = role;
}



/**************************************************
 * ************************************************
 * ************************************************
 * fin   TACHE B5
 * ************************************************
 * ************************************************
 * ************************************************
*/