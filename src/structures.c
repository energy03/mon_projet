#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
// Inclusion des entêtes
#include "../headers/structures.h"



// tableau de void*

/// @brief fonction pour ajouter un élément dans un tableau de void*
/// @param tab tableau de void*
/// @param element void* à ajouter
/// @param *size taille du tableau
void add_element(E tab[], E element, int *size)
{
    tab[*size] = element;
    (*size)++;
}

/// @brief fonction pour supprimer un élément dans un tableau de void*
/// @param tab tableau de void*
/// @param element void* à supprimer
/// @param *size taille du tableau
void remove_element(E tab[],E element, int *size)
{   
     if (tab == NULL || *size == 0) {
        return; // Ne rien faire si le tableau est nul ou vide
    }

    int i, j;

    // Parcourir le tableau pour trouver l'élément à supprimer
    for (i = 0; i < *size; i++) {
        if (tab[i] == element) {
            // Décaler tous les éléments suivants vers la gauche
            for (j = i; j < *size - 1; j++) {
                tab[j] = tab[j + 1];
            }

            // Libérer la mémoire de l'élément supprimé
            tab[*size - 1]=NULL;

            // Réduire la taille du tableau
            (*size)--;

            // Sortir de la boucle
            break;
        }
    }
    /*// Parcours du tableau jusqu'a tomber sur l'élément à supprimer
    if(*size == 1){
        tab[0] = NULL;
    }
    else if(*size > 1){
        int index=0;
        while(tab[index] != element && index < *size)
        {
            index++;
        }
        if(index!=*size-1){
            // Decalage des éléments du tableau
            for(int i = index; i < *size; i++)
            {
                tab[i] = tab[i+1];
            }
            
        }
        tab[*size-1] = NULL;
    }*/
    
}


/// @brief fonction verifiant si un element est dans un tableau de void*
/// @param tab tableau de void*
/// @param element element a verifier
/// @param size taille du tableau
/// @return 1 si l'element est dans le tableau, 0 sinon
int is_in(E tab[], E element, int size)
{
    for(int i=0;i<size;i++){
        if(tab[i] == element){
            return 1;
        }
    }
    return 0;
}

/// @brief fonction liberant memoire allouée à une matrice
/// @param matrice matrice à libérer
/// @param nb_lignes nombre de lignes de la matrice
void free_matrice(double*** matrice, int nb_lignes)
{
    for(int i=0;i<nb_lignes;i++){
        free((*matrice)[i]);
    }
    free(*matrice);
}