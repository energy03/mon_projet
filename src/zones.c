#include "../headers/zones.h"
#include "../headers/personnages.h"


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

