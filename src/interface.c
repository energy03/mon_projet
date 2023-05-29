#include <stdio.h>
#include "../headers/interface.h"

// Fonction pour afficher toutes les informations du jeu
void afficher_informations() {
    
}

// Fonction pour demander à une joueuse combien de capital elle veut utiliser
int demander_capital_joueuse(joueuse joueuse) {
    
    return 0;
}

// Fonction pour demander à une joueuse une zone
int demander_zone_joueuse(joueuse joueuse) {
   
    return 0;
}

// Fonction pour demander à une joueuse si elle veut jouer une carte et si oui, laquelle
carte demander_carte_joueuse(joueuse joueuse, int tour_joueuse) {
    /*int choix;
    int numJoueuse;
    if(tour_joueuse %2 != 0){
        numJoueuse = 2;
    }else{
        numJoueuse = 1;
    }
    printf("%d\n", nb_joueurs_ecoles(joueuse));
    printf("Joueur %d, voulez-vous jouer une carte ? (1: Oui, 0: Non)\n",numJoueuse);
    scanf("%d", &choix);

    if (choix == 1) {
        int index_carte;
        printf("Quelle carte voulez-vous jouer ? (Indiquez l'index de la carte)\n");
        scanf("%d", &index_carte);

        // Vérifiez si l'index est valide et récupérez la carte correspondante
        // if (index_carte >= 0 && index_carte < (*joueuse)->nb_cartes) {
        //     return (*joueuse)->cards[index_carte];
        // } else {
        //     printf("L'index de la carte est invalide.\n");
        //     return NULL;
        // }
        carte* c = NULL;
        return c;
    } else {
        return NULL;
    }*/
    return NULL;
}

// Fonction pour afficher un message quand le jeu est fini
void afficher_fin_jeu() {
    printf("Le jeu est fini !\n");
}

// Fonction pour afficher si un membre a été mangé
void afficher_membre_mange(personnage personnage) {
    // if(personnage->vie == MANGE){
        printf("Le membre %d a été mangé.\n", getZonePerso(personnage));
    // }
    // else{
    //     printf("Le membre %s est en vie.\n", personnage->nom);
    // }
}

// Fonction pour afficher si un membre a été déplacé
void afficher_membre_deplace(personnage personnage) {
    // printf("Le membre %s a été déplacé.\n", personnage->nom);
        printf("%d\n", getZonePerso(personnage));

}
