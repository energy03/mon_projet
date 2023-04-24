#include "../headers/personnages.h"





/*****************************************
 * ***************************************
 * ***************************************
 *       TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/



/// @brief creation d'un enumération Filière permettant de spécifier si un membre d'école est en FISE ou en FISA
enum Filiere {FISE,FISA};

/// @brief creation du type Filiere qui est un enumération Filière; une variable de type Filiere peut prendre les valeurs FISE ou FISA
typedef enum Filiere Filiere;

/// @brief enregistrement personnage qui contient les informations sur un personnage
struct personnage{
    RolePerso role; // MONSTRE ou MEMBRE
    Filiere filiere; // FISE ou FISA s'il s'agit d'un membre d'école
    zone* zone_perso; // zone où se trouve le personnage
    Vie_Perso vie; // VIVANT ou MANGE s'il s'agit d'un personnage d'école
};

/// @brief recuperation de la filière d'un personnage
/// @param perso pointeur sur le personnage
/// @return filière du personnage
Filiere get_filiere_personnage(personnage* perso){
    return perso->filiere;
}


/**************************************************
 * ************************************************
 * ************************************************
 *    TACHE B5
 * ************************************************
 * ************************************************
 * ************************************************
*/