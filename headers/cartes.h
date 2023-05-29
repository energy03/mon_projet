#ifndef CARTES_H
#define CARTES_H

//Type carte
typedef struct carte * carte;

// getters
/// @brief retourne le nom de la carte
/// @param carte la carte dont on veut le nom
/// @return le nom de la carte
char* get_nom_carte(carte carte);

/// @brief retourne la description de la carte
/// @param carte la carte dont on veut la description
/// @return la description de la carte
char* get_description_carte(carte carte);

/// @brief retourne l'id de la carte
/// @param carte la carte dont on veut l'id
/// @return l'id de la carte
int get_id_carte(carte carte);

/// @brief retourne la carte correspondant à l'id
/// @param id l'id de la carte
/// @return la carte correspondant à l'id
carte get_carte(int id);


/// @brief crée une carte
/// @param id l'id de la carte
/// @param nom le nom de la carte
/// @param description la description de la carte
/// @return la carte créée
carte createCarte(int id, char* nom, char* description);

/// @brief libère la mémoire allouée pour la carte
/// @param carte la carte à libérer
void freeCarte(carte* carte);

#endif
