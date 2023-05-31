#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/personnages.h"
#include "../headers/zones.h"
#include "../headers/globals.h"
#include "../headers/structures.h"

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
        for(int j=0;j<nb_zn;j++){
            matrice[i][j]=zones->matriceProba[i][j];
        }
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

/// @brief recupération du tableau de personnages d'une zone
/// @param zone pointeur sur la zone
/// @return tableau de personnages de la zone
personnage* get_tab_perso_zone(zone zon)
{
    return zon->perso;
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

/// @brief modification du tableau de personnages d'une zone
/// @param zone pointeur sur la zone
/// @param tab_perso nouveau tableau de personnages de la zone
/// @param nb_perso nouveau nombre de personnages dans la zone
void set_tab_perso_zone(zone zon, personnage* tab_perso, int nb_perso)
{
    for(int i=0;i<nb_perso;i++){
        zon->perso[i]=tab_perso[i];
    }
    zon->nb_perso = nb_perso;
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
    for(int i=0;i<get_nb_zones(*zones);i++){
        
        free((*zones)->tabZones[i]);
    }
    free(*zones);
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
int sim_dis(double p[], int x[], int n){
    double h=u();
    int l=x[n-1];
    // Étape 2: Trouver le premier indice j* tel que u ≤ Σpi pour i=1 à j*
    double somme=0;
    for(int j=0;j<n;j++){
        somme+=p[j];
        if(h<=somme && p[j]!=0){
            l=x[j];
            break;
        }
    }
    return l;
    
}


// Fonction pour récupérer une zone successeur aléatoire d'une zone donnée
int getNextZone(zone zone) {
    int zn;
    zn= get_num_zone(zone);
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    double** matrice=get_matrice_proba(ZONES);
    int l = sim_dis(matrice[zn-1],x,10);
    free_matrice(&matrice,10);
    return l;
}