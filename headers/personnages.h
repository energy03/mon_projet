#ifndef PERSONNAGES_H
#define PERSONNAGES_H

#include "zones.h"

/*  Enumération FonctionPersonnage
    *   Permet de préciser si un personnage est un Monstre (MONSTRE)    ou un membre d'école (MEMBRE)
*/
typedef enum RolePerso {MONSTRE, MEMBRE} RolePerso;

/*  Enumeration Vie_Perso si un personnage est vivant ( VIVANT ) ou mangé ( MANGE )

*/
typedef enum Vie_Perso {VIVANT, MANGE} Vie_Perso;

/*
    *   type abstrait personnage (Pointeur sur un "structure personnage")
    *   contient les informations sur un personnage
    *   
    */

typedef struct personnage personnage;

/*  Creation de Personnage  */



personnage* createPerso(RolePerso V_ou_M,zone* num);

/*Fonction freePerso : Libération de la mémoire allouée pour la création du Personnage perso
 *  @requires   perso (type personnage)
 *  @assigns Libère la memoire allouée 
 *  @ensures
 */
void freePerso(personnage* perso);

/*Déplacer un Personnage
 *@requires un 
 */
void movePerso(personnage* perso,zone* zone_coord);

/*Récuperer la zone*/
int getZonePerso(personnage* perso);

/*Vérifier si un personnage est mangé ou pas*/
void isEaten(personnage* perso); 

/*****************************************
 * ***************************************
 * ***************************************
 *       TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/


/*****************************************
 * ***************************************
 * ***************************************
 *       TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/



#endif