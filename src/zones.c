#include "../headers/zones.h"
#include "../headers/personnages.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

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
    personnage perso[20]; // ensemble des personnages dans une zone
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

/// @brief recupération du nombre de la matrice de probabilité
/// @param zones pointeur sur les zones
/// @return matrice de probabilité
double** get_matrice_proba(zones zones)
{
    double** matrice;
    int nb_zn = get_nb_zones(zones);
    matrice = malloc(nb_zn*sizeof(double*));
    for(int i=0;i<nb_zn;i++){
        matrice[i]=malloc(nb_zn*sizeof(double));
    }
    return matrice;
}

/// @brief recupération du nombre de personnages dans une zone
/// @param zone pointeur sur la zone
/// @return nombre de personnages dans la zone
int get_nb_perso_zone(zone zon)
{
    return zon->nb_perso;
}

/// @brief recupération du numéro d'une zone
/// @param zone pointeur sur la zone
/// @return numéro de la zone
int get_num_zone(zone zon)
{
    return zon->num;
}

/// setters

/// @brief modification du nombre de personnages dans une zone
/// @param zone pointeur sur la zone
/// @param nb_perso nouveau nombre de personnages dans la zone
void set_nb_perso_zone(zone zon, int nb_perso)
{
    zon->nb_perso = nb_perso;
}

/// @brief modification du numéro d'une zone
/// @param zone pointeur sur la zone
/// @param num nouveau numéro de la zone
void set_num_zone(zone zon, int num)
{
    zon->num = num;
}

/// @brief modification du nombre de zones
/// @param zones pointeur sur les zones
/// @param nb_zones nouveau nombre de zones
void set_nb_zones(zones zones, int nb_zones)
{
    zones->nb_zones = nb_zones;
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
zones createZones(int nb_zones){
        zones zones_jeu = malloc(sizeof(struct zones));
        set_nb_zones(zones_jeu, nb_zones);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                zones_jeu->matriceProba[i][j] = 0.1;
            }
            zones_jeu->tabZones[i]=malloc(sizeof(struct zone));
            set_num_zone(zones_jeu->tabZones[i], i+1);
            set_nb_perso_zone(zones_jeu->tabZones[i], 0);
        }
        
        return (zones_jeu);
}

// Fonction pour libérer la mémoire allouée lors de la création des zones
void freeZones(zones* zones) {
    free(zones);
}

// Fonction pour récupérer une zone à partir de son numéro
zone getZoneById(zones zones, int numZone) {
    return zones->tabZones[numZone-1];
    
}

// Simulation de loi uniforme
double u(){
    return (double)rand()/RAND_MAX;
}

//Simulation de la marche aléatoire
int sim_dis(double p[], int x[]){
    int l;
    int j;
    double h = u();
    double s = 0;
    for(j=0;j<10;j++){
        s+=p[j];
        if(h<=s){
            l=x[j];
            break;
        }
        
    }
    return l;
}


// Fonction pour récupérer une zone successeur aléatoire d'une zone donnée
int getNextZone(zone zone) {
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    double p[10] = {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.05,0.05,0.1};
    int l = sim_dis(p,x);
    return l;
}