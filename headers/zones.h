#ifndef  ZONES_H
#define  ZONES_H




/* type abstrait zone
    *    contient les informations sur une zone
    *    
*/

typedef struct zone zone;




/*  Type abstrait zones
    *   contient l'ensemble des zones du jeu et une matrice de probabiltés entre les différentes zones
    *   
    * 
*/


struct zones
{
    zone * tabZones;
    double matriceProba[10][10];
    int nb_zones;
};




typedef struct zones * zones;






/* Fonction createZones: Creation de l'ensemble des zones
    *@requires 
    *@assigns   
    *@ensures retourne
*/

zones* createZones(int nb_zones);

/*Libérer l'emplacepment mémoire alloué à un ensemble de zones (zones)*/

void freeZones(zones* zones);

/*Récupérer une zone à partir de son numéro*/
zone* getZoneById(zones* zones, int numZone);


/*Fonction pour application les décisions des joueuses */
void apply_decision(zones* zones,int capital);

/*Fonction pour récupérer une zone successeur aléatoire d'une zone donnée*/
int getNextZone(zone* zone);

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


/// @brief recupération du nombre de personnages dans une zone
/// @param zone pointeur sur la zone
/// @return nombre de personnages dans la zone
int get_nb_perso_zone(zone zon);

/// @brief recupération du numéro d'une zone
/// @param zone pointeur sur la zone
/// @return numéro de la zone
int get_num_zone(zone zon);

/// setters

/// @brief modification du nombre de personnages dans une zone
/// @param zone pointeur sur la zone
/// @param nb_perso nouveau nombre de personnages dans la zone
void set_nb_perso_zone(zone* zon, int nb_perso);

/// @brief modification du numéro d'une zone
/// @param zone pointeur sur la zone
/// @param num nouveau numéro de la zone
void set_num_zone(zone* zon, int num);

/// @brief modification du nombre de zones
/// @param zones pointeur sur les zones
/// @param nb_zones nouveau nombre de zones
void set_nb_zones(zones* zones, int nb_zones);







/*****************************************
 * ***************************************
 * ***************************************
 *    fin   TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/


#endif

