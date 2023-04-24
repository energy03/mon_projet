#include "../headers/zones.h"
#include "../headers/personnages.h"
#include <stdio.h>
#include <time.h>

/*****************************************
 * ***************************************
 * ***************************************
 * fin      TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/

/// @brief enregistrement zone qui contient les informations sur une zone
struct zone {
    int num;
    personnage* perso[20]; // ensemble des personnages dans une zone
    int nb_perso; //nombre de personnages dans une zone
};

/// getters

/// @brief Récupérer le nombre de zones
/// @param zones pointeur sur les zones
/// @return nombre de zones
int get_nb_zones(zones zones)
{
    return zones->nb_zones;
}

/// @brief recupération du nombre de personnages dans une zone
/// @param zone pointeur sur la zone
/// @return nombre de personnages dans la zone
int get_nb_perso_zone(zone zon)
{
    return zon.nb_perso;
}

/// @brief recupération du numéro d'une zone
/// @param zone pointeur sur la zone
/// @return numéro de la zone
int get_num_zone(zone zon)
{
    return zon.num;
}

/// setters

/// @brief modification du nombre de personnages dans une zone
/// @param zone pointeur sur la zone
/// @param nb_perso nouveau nombre de personnages dans la zone
void set_nb_perso_zone(zone* zon, int nb_perso)
{
    zon->nb_perso = nb_perso;
}

/// @brief modification du numéro d'une zone
/// @param zone pointeur sur la zone
/// @param num nouveau numéro de la zone
void set_num_zone(zone* zon, int num)
{
    zon->num = num;
}

/// @brief modification du nombre de zones
/// @param zones pointeur sur les zones
/// @param nb_zones nouveau nombre de zones
void set_nb_zones(zones* zones, int nb_zones)
{
    (*zones)->nb_zones = nb_zones;
}



/*****************************************
 * ***************************************
 * ***************************************
 * fin      TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/


// Fonction pour créer une zone
zones* createZones(int nb_zones){
        double probabilities[10][10];
        zones* zones_jeu=malloc(sizeof(zones));
        zones_jeu->nb_zones=nb_zones;
        for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                        zones_jeu->probabilities[i][j] = probabilities[i][j];
                }
        }
        zone* zone1 = malloc(sizeof(zone));
        zone1->num_zone=1;
        zone1->nb_monster=1;
        zone1->nb_perso=0;
        zones_jeu->tab_zone[0]=zone1;
        zone* zone2 = malloc(sizeof(zone));
        zone2->num_zone=2;
        zone2->nb_monster=0;
        zone2->nb_perso=0;
        zones_jeu->tab_zone[1]=zone2;
        zone* zone3 = malloc(sizeof(zone));
        zone3->num_zone=3;
        zone3->nb_perso=0;
        zone3->nb_monster=0;
        zones_jeu->tab_zone[2]=zone3;
        zone* zone4 = malloc(sizeof(zone));
        zone4->num_zone=4;
        zone4->nb_monster=0;
        zone4->nb_perso=0;
        zones_jeu->tab_zone[3]=zone4;
        zone* zone5 = malloc(sizeof(zone));
        zone5->num_zone=5;
        zone5->nb_monster=0;
        zone5->nb_perso=0;
        zones_jeu->tab_zone[4]=zone5;
        zone* zone6 = malloc(sizeof(zone));
        zone6->num_zone=6;
        zone6->nb_monster=0;
        zone6->nb_perso=0;
        zones_jeu->tab_zone[5]=zone6;
        zone* zone7 = malloc(sizeof(zone));
        zone7->num_zone=7;
        zone7->nb_monster=0;
        zone7->nb_perso=0;
        zones_jeu->tab_zone[6]=zone7;
        zone* zone8 = malloc(sizeof(zone));
        zone8->num_zone=8;
        zone8->nb_monster=0;
        zone8->nb_perso=0;
        zones_jeu->tab_zone[7]=zone8;
        zone* zone9 = malloc(sizeof(zone));
        zone9->num_zone=9;
        zone9->nb_monster=0;
        zone9->nb_perso=0;
        zones_jeu->tab_zone[8]=zone9;
        zone* zone10 = malloc(sizeof(zone));
        zone10->num_zone=10;
        zone10->nb_monster=0;
        zone10->nb_perso=0;
        zones_jeu->tab_zone[9]=zone10;
        return zones_jeu;
}

// Fonction pour libérer la mémoire allouée lors de la création des zones
void freeZones(zones* zones) {
    free(zones);
}

// Fonction pour récupérer une zone à partir de son numéro
zone* getZoneById(zones* zones, int numZone) {
    if (numZone >= 0 && numZone < zones->nb_zones) {
        return &zones->tabZones[numZone+1];
    } else {
        printf("Erreur: Numéro de zone invalide.\n");
        exit(EXIT_FAILURE);
    }
}