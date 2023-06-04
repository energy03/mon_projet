#ifndef  ZONES_H
#define  ZONES_H
#include "personnages.h"




/* type abstrait zone
    *    contient les informations sur une zone
    *    
*/

typedef struct zone * zone;




/*  Type abstrait zones
    *   contient l'ensemble des zones du jeu et une matrice de probabiltés entre les différentes zones
    *   
    * 
*/


struct zones
{
    zone tabZones[10];
    double matriceProba[10][10];
    int nb_zones;
};




typedef struct zones * zones;






/* Fonction createZones: Creation de l'ensemble des zones
    *@requires 
    *@assigns   
    *@ensures retourne
*/

zones createZones(int nb_zones);

/*Libérer l'emplacepment mémoire alloué à un ensemble de zones (zones)*/

void freeZones(zones* zones);

/*Récupérer une zone à partir de son numéro*/
zone getZoneById(zones zones, int numZone);


/*Fonction pour application les décisions des joueuses */
void apply_decision(zones zones,int capital,int zone1,int zone2,int zone3);

/*Fonction pour récupérer une zone successeur aléatoire d'une zone donnée*/
int getNextZone(zone zone);

/*****************************************
 * ***************************************
 * ***************************************
 *   debut    TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/

///getters
/// @brief Récupérer le nombre de zones
/// @param zones pointeur sur les zones
/// @return nombre de zones
int get_nb_zones(zones zones);

/// @brief recupération de la matrice de probabilités entre les zones
/// @param zones pointeur sur les zones
/// @return matrice de probabilités entre les zones
double** get_matrice_proba(zones zones);


/// @brief recupération du nombre de personnages dans une zone
/// @param zone pointeur sur la zone
/// @return nombre de personnages dans la zone
int get_nb_perso_zone(zone zon);

/// @brief recupération du numéro d'une zone
/// @param zone pointeur sur la zone
/// @return numéro de la zone
int get_num_zone(zone zon);


/// @brief recupération du tableau de personnages d'une zone
/// @param zone pointeur sur la zone
/// @return tableau de personnages de la zone
personnage* get_tab_perso_zone(zone zon);

/// setters

/// @brief modification du nombre de personnages dans une zone
/// @param zone pointeur sur la zone
/// @param nb_perso nouveau nombre de personnages dans la zone
void set_nb_perso_zone(zone zon, int nb_perso);

/// @brief modification du numéro d'une zone
/// @param zone pointeur sur la zone
/// @param num nouveau numéro de la zone
void set_num_zone(zone zon, int num);

/// @brief modification du nombre de zones
/// @param zones pointeur sur les zones
/// @param nb_zones nouveau nombre de zones
void set_nb_zones(zones zones, int nb_zones);

/// @brief modification du tableau de personnages d'une zone
/// @param zone pointeur sur la zone
/// @param tab_perso nouveau tableau de personnages de la zone
/// @param nb_perso nouveau nombre de personnages dans la zone
void set_tab_perso_zone(zone zon, personnage* tab_perso, int nb_perso);

/// @brief modification de la matrice de probabilités entre les zones
/// @param zones pointeur sur les zones
/// @param matrice_proba nouvelle matrice de probabilités entre les zones
void set_matrice_proba(zones zones, double** matrice_proba);







/*****************************************
 * ***************************************
 * ***************************************
 *    fin   TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/


#endif

