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

/// @brief fonction verifiant si un element est dans un tableau de void*
/// @param tab tableau de void*
/// @param element element a verifier
/// @param size taille du tableau
/// @return 1 si l'element est dans le tableau, 0 sinon
int is_in(E tab[], E element, int size);



#endif // STRUCTURES_H
