#ifndef PERSONNAGES_H
#define PERSONNAGES_H

typedef enum Filiere{FISA,FISE} Filiere;

/*  Enumération FonctionPersonnage
    *   Permet de préciser si un personnage est un Monstre (MONSTRE)    ou un membre d'école (MEMBRE)
*/
typedef enum RolePerso {MONSTRE, MEMBRE} RolePerso;

/*  Enumeration Vie_Perso si un personnage est vivant ( VIVANT ) ou mangé ( MANGE )

*/
typedef enum Vie_Perso {MANGE,VIVANT} Vie_Perso;

/*
    *   type abstrait personnage (Pointeur sur un "structure personnage")
    *   contient les informations sur un personnage
    *   
    */

typedef struct personnage * personnage;

/*  Creation de Personnage  */



personnage createPerso(RolePerso Mo_Me,char* nom,Filiere filiere);

/*Fonction freePerso : Libération de la mémoire allouée pour la création du Personnage perso
 *  @requires   perso (type personnage)
 *  @assigns Libère la memoire allouée 
 *  @ensures
 */
void freePerso(personnage* perso);

/*Déplacer un Personnage
 *@requires un 
 */
void movePerso(personnage perso,int zone_coord);

/*Récuperer la zone*/
int getZonePerso(personnage perso);

/*Vérifier si un personnage est mangé ou pas*/
int isEaten(personnage perso); 

/*****************************************
 * ***************************************
 * ***************************************
 *  debut     TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/

// getters

/// @brief recuperation du nom d'un personnage
/// @param perso pointeur sur le personnage
/// @return nom du personnage
char* get_nom_personnage(personnage perso);

/// @brief recuperation du role d'un personnage
/// @param perso pointeur sur le personnage
/// @return role du personnage
RolePerso get_role_personnage(personnage perso);

/// @brief recuperation de la filière d'un personnage
/// @param perso pointeur sur le personnage
/// @return filière du personnage
Filiere get_filiere_personnage(personnage perso);

/// @brief recuperation de la vie d'un personnage
/// @param perso pointeur sur le personnage
/// @return vie du personnage
Vie_Perso get_vie_personnage(personnage perso);

/// @brief recuperation de la zone d'un personnage
/// @param perso pointeur sur le personnage
/// @return zone du personnage
int get_zone_personnage(personnage perso);

// setters
/// @brief modification du role d'un personnage
/// @param perso pointeur sur le personnage
/// @param role nouveau role du personnage
void set_role_personnage(personnage perso, RolePerso role);

/// @brief modification de la filière d'un personnage
/// @param perso pointeur sur le personnage
/// @param filiere nouvelle filière du personnage
void set_filiere_personnage(personnage perso, Filiere filiere);

/// @brief modification de la vie d'un personnage
/// @param perso pointeur sur le personnage
/// @param vie nouvelle vie du personnage
void set_vie_personnage(personnage perso, Vie_Perso vie);

/// @brief modification de la zone d'un personnage
/// @param perso pointeur sur le personnage
/// @param zone nouvelle zone du personnage
void set_zone_personnage(personnage perso, int zone);



/*****************************************
 * ***************************************
 * ***************************************
 *    fin   TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/



#endif