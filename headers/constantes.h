#ifndef CONSTANTES_H
#define CONSTANTES_H

/*****************************************
 * ***************************************
 * ***************************************
 *       TACHE B4 : CONSTANTES
 * ***************************************
 * ***************************************
 * ***************************************
*/

// nombre de zones de jeu
#define NB_ZONES 10

// nombre de joueuses
#define NB_JOUEUSES 2

// nombre de montres en debut de partie
#define NB_MONSTRES_DEBUT 1

// zone initiale du monstre
#define ZONE_INITIALE_MONSTRE 1

// zones initiales pour les personnages de la premiere joueuse
#define ZONE_INITIALE_JOUEUSE_1 { 2 , 3}

// zones initiales pour les personnages de la deuxieme joueuse
#define ZONE_INITIALE_JOUEUSE_2 { 4 , 5 }

// nombre de membres par joueuses au debut du jeu
#define NB_MEMBRES_PAR_JOUEUSE 5

// nombre de cartes dans la main d'une joueuse au début de partie
#define NB_CARTES_MAIN_DEBUT 5

// probabilités initiales pour toutes les zones de jeu
#define PROBABILITE_INITIALE 0.1


// capital par defaut de chaque joueuse au début de chaque tour
#define CAPITAL_DEBUT_TOUR 5


// augmentation de capital et nombre de tours pour la carte Massinissat Merabet {augmentation de capial = 2, nombre de tours = 3}
#define VAL_MASSINISSAT_MERABET { 2 , 3 }

// nombre de déplacements du monstre par la carte Valentin Honoré
#define NB_DEPLACEMENTS_MONSTRE_VAL_HONORE 3

// nombre de points obtenus par le sacrifice d'un membre d'ecole lors de l'utilisation de la carte Djibril-Aurelien Dembele-Cabot
#define NB_POINTS_SACRIFICE 15

// Nombre de tours pendants lesquels chaque monstre disparaîtra lors de l'utilisation de la carte Christine Matias
#define NB_TOURS_DISPARITION_MONSTRE 2

// Nombre de tours pendants lesquels chaque point de capital peut déplacer autant de valeurs de probabilités lors de l'utilisation de la carte Katrin Salhab
#define NB_TOURS_DEPLACEMENT_PROBABILITES 3

// Nombre de tours pendant lesquels les membres d'école d'une joueuse ne peuvent pas être mangés lors de l'utilisation de la carte Laurent Prével
#define NB_TOURS_PROTECTION_MANGE 4 

// autres constantes...

#endif /* CONSTANTES_H */
