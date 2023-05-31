// Protection contre les inclusions multiples
#ifndef STRUCTURES_H
#define STRUCTURES_H

// tableaux de void*
typedef void* E;

/// @brief fonction pour ajouter un element dans un tableau de void*
/// @param tab tableau de void*
/// @param element element a ajouter
/// @param size taille du tableau
void add_element(E tab[], E element, int* size);

/// @brief fonction pour supprimer un element dans un tableau de void*
/// @param tab tableau de void*
/// @param element element a supprimer
/// @param size taille du tableau
void remove_element(E tab[], E element,int* size);


/// @brief fonction liberant memoire allouée à une matrice
/// @param matrice matrice à libérer
/// @param nb_lignes nombre de lignes de la matrice
void free_matrice(double*** matrice, int nb_lignes);



#endif // STRUCTURES_H
