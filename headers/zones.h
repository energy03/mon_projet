#ifndef  ZONES_H
#define  ZONES_H




/* type abstrait zone
    *   contient les informations sur une zone
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
    double ** matriceProba;
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

#endif

