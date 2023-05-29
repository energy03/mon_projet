#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/globals.h"
#include "../headers/joueuses.h"
#include "../headers/personnages.h"
#include "../headers/zones.h"
#include "../headers/cartes.h"
#include "../headers/interface.h"
#include "../headers/constantes.h"

joueuse JOUEUSE_1;
joueuse JOUEUSE_2;
personnage MONSTRE_PERS;
personnage MEMBRE_1;
personnage MEMBRE_2;
personnage MEMBRE_3;
personnage MEMBRE_4;
personnage MEMBRE_5;
personnage MEMBRE_6;
personnage MEMBRE_7;
personnage MEMBRE_8;
personnage MEMBRE_9;
personnage MEMBRE_10;

zones ZONES;

/*
enum id_card{
    MAS_MER,    // id de la carte Massinissa Merabet 
    FET_BAN,    // id de la carte Fetia Bannour
    VAL_HON,    // id de la carte Valentin Honoré
    REN_RIO,    // id de la carte Renaud Rioboo
    KEV_GOI,    // id de la carte Kevin Goilard
    LAU_BOU,    // id de la carte Laurence Bourard
    DEN_MUN,    // id de la carte Denisse Munante
    CYR_BEN,    // id de la carte Cyril Benezet
    ANN_LIG,    // id de la carte Anne-Laure Ligozat   
    CHR_MOU,    // id de la carte Christophe Mouilleron
    DJI_CAB,    // id de la carte Djibril-Aurelien Dembele-Cabot
    LUC_PAC,    // id de la carte Lucienne Pacave
    JER_HUE,    // id de la carte Jérome Huet
    CHR_MAT,    // id de la carte Christine Mathias
    KAT_SAL,    // id de la carte Katrin Salhab
    SER_PUL,    // id de la carte Sergio Pulido-Nino
    DIM_WAT,    // id de la carte Dimitri Watel
    MAR_SZA,    // id de la carte Marie Szafranski
    JUL_FOR,    // id de la carte Julien Forest
    LAU_PRE     // id de la carte Laurent Prevel
};
*/

carte CARTES[20];
carte MASSINISSA_MERABET; // carte Massinissa Merabet
carte FETIA_BANNOUR;       // carte Fetia Bannour
carte VALENTIN_HONORE;    // carte Valentin Honoré
carte RENAUD_RIOBOO;      // carte Renaud Rioboo
carte KEVIN_GOILARD;      // carte Kevin Goilard
carte LAURENCE_BOURARD;   // carte Laurence Bourard
carte DENISSE_MUNANTE;    // carte Denisse Munante
carte CYRIL_BENEZET;      // carte Cyril Benezet
carte ANNE_LAURE_LIGOZAT; // carte Anne-Laure Ligozat
carte CHRISTOPHE_MOUILLERON; // carte Christophe Mouilleron
carte DJIBRIL_AURELIEN_DEMBELE_CABOT; // carte Djibril-Aurelien Dembele-Cabot
carte LUCIENNE_PACAVE;    // carte Lucienne Pacave
carte JEROME_HUET;        // carte Jérome Huet
carte CHRISTINE_MATHIAS;  // carte Christine Mathias
carte KATRIN_SALHAB;      // carte Katrin Salhab
carte SERGIO_PULIDO_NINO; // carte Sergio Pulido-Nino
carte DIMITRI_WATEL;      // carte Dimitri Watel
carte MARIE_SZAFRANSKI;   // carte Marie Szafranski
carte JULIEN_FOREST;      // carte Julien Forest
carte LAURENT_PREVEL;     // carte Laurent Prevel

int main()
{
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    creer_joueuses(&JOUEUSE_1,&JOUEUSE_2);

    ZONES=createZones(NB_ZONES);

    MONSTRE_PERS = createPerso(MONSTRE,"Monstre",FISE);
    // Creation des 10 personnages
    MEMBRE_1 = createPerso(MEMBRE,"Membre 1",FISE);
    MEMBRE_2 = createPerso(MEMBRE,"Membre 2",FISE);
    MEMBRE_3 = createPerso(MEMBRE,"Membre 3",FISE);
    MEMBRE_4 = createPerso(MEMBRE,"Membre 4",FISE);
    MEMBRE_5 = createPerso(MEMBRE,"Membre 5",FISE);
    MEMBRE_6 = createPerso(MEMBRE,"Membre 6",FISE);
    MEMBRE_7 = createPerso(MEMBRE,"Membre 7",FISE);
    MEMBRE_8 = createPerso(MEMBRE,"Membre 8",FISE);
    MEMBRE_9 = createPerso(MEMBRE,"Membre 9",FISE);
    MEMBRE_10 = createPerso(MEMBRE,"Membre 10",FISE);

    // Creation des 20 cartes
    MASSINISSA_MERABET = createCarte(0,"Massinissa Merabet","");
    CARTES[0] = MASSINISSA_MERABET;

    FETIA_BANNOUR = createCarte(1,"Fetia Bannour","");
    CARTES[1] = FETIA_BANNOUR;

    VALENTIN_HONORE = createCarte(2,"Valentin Honoré","");
    CARTES[2] = VALENTIN_HONORE;

    RENAUD_RIOBOO = createCarte(3,"Renaud Rioboo","");
    CARTES[3] = RENAUD_RIOBOO;

    KEVIN_GOILARD = createCarte(4,"Kevin Goilard","");
    CARTES[4] = KEVIN_GOILARD;

    LAURENCE_BOURARD = createCarte(5,"Laurence Bourard","");
    CARTES[5] = LAURENCE_BOURARD;

    DENISSE_MUNANTE = createCarte(6,"Denisse Munante","");
    CARTES[6] = DENISSE_MUNANTE;

    CYRIL_BENEZET = createCarte(7,"Cyril Benezet","");
    CARTES[7] = CYRIL_BENEZET;

    ANNE_LAURE_LIGOZAT = createCarte(8,"Anne-Laure Ligozat","");
    CARTES[8] = ANNE_LAURE_LIGOZAT;

    CHRISTOPHE_MOUILLERON = createCarte(9,"Christophe Mouilleron","");
    CARTES[9] = CHRISTOPHE_MOUILLERON;
    
    DJIBRIL_AURELIEN_DEMBELE_CABOT = createCarte(10,"Djibril-Aurelien Dembele-Cabot","");
    CARTES[10] = DJIBRIL_AURELIEN_DEMBELE_CABOT;

    LUCIENNE_PACAVE = createCarte(11,"Lucienne Pacave","");
    CARTES[11] = LUCIENNE_PACAVE;

    JEROME_HUET = createCarte(12,"Jérome Huet","");
    CARTES[12] = JEROME_HUET;

    CHRISTINE_MATHIAS = createCarte(13,"Christine Mathias","");
    CARTES[13] = CHRISTINE_MATHIAS;

    KATRIN_SALHAB = createCarte(14,"Katrin Salhab","");
    CARTES[14] = KATRIN_SALHAB;

    SERGIO_PULIDO_NINO = createCarte(15,"Sergio Pulido-Nino","");
    CARTES[15] = SERGIO_PULIDO_NINO;

    DIMITRI_WATEL = createCarte(16,"Dimitri Watel","");
    CARTES[16] = DIMITRI_WATEL;

    MARIE_SZAFRANSKI = createCarte(17,"Marie Szafranski","");
    CARTES[17] = MARIE_SZAFRANSKI;

    JULIEN_FOREST = createCarte(18,"Julien Forest","");
    CARTES[18] = JULIEN_FOREST;

    LAURENT_PREVEL = createCarte(19,"Laurent Prevel","");
    CARTES[19] = LAURENT_PREVEL;

    // Initialisation du capital des joueuses
    reinitialiser_capital(JOUEUSE_1);
    reinitialiser_capital(JOUEUSE_2);

    // Initialisation des joueuses
    // Ajout des personnages aux tableaux des personnage des joueuses
    personnage* membres_ecole1 = membres_joueurs(JOUEUSE_1);
    membres_ecole1[0] = MEMBRE_1;
    membres_ecole1[1] = MEMBRE_2;
    membres_ecole1[2] = MEMBRE_3;
    membres_ecole1[3] = MEMBRE_4;
    membres_ecole1[4] = MEMBRE_5;
    set_nb_membres_joueuse(JOUEUSE_1, NB_MEMBRES_PAR_JOUEUSE);
    // choix des zones de départ des membres de l'école de la joueuse 1
    for (int i = 0; i < NB_MEMBRES_PAR_JOUEUSE; i++) {
        // Choix aleatoire de 0 ou 1
        int alea = rand() % 2;
        int t1[]=ZONE_INITIALE_JOUEUSE_1;
        int num_zone_1 = t1[alea];
        movePerso(membres_ecole1[i], num_zone_1);
    }

    // Ajout des personnages aux tableaux des personnage des joueuses
    personnage* membres_ecole2 = membres_joueurs(JOUEUSE_2);
    membres_ecole2[0] = MEMBRE_6;
    membres_ecole2[1] = MEMBRE_7;
    membres_ecole2[2] = MEMBRE_8;
    membres_ecole2[3] = MEMBRE_9;
    membres_ecole2[4] = MEMBRE_10;
    set_nb_membres_joueuse(JOUEUSE_2, 5);
    // choix des zones de départ des membres de l'école de la joueuse 2
    for (int i = 0; i < 5; i++) {
        // Choix aleatoire de 0 ou 1
        int alea = rand() % 2;
        int t2[]=ZONE_INITIALE_JOUEUSE_2;
        int num_zone_2 = t2[alea];
        movePerso(membres_ecole2[i], num_zone_2);
    }





    // /*
    // // Création des joueuses
    // joueuse joueuse1;
    // joueuse joueuse2;
    // creer_joueuses(&joueuse1, &joueuse2);

    // // initialisation de leur capital
    // reinitialiser_capital(joueuse1);
    // reinitialiser_capital(joueuse2);

    // // Initiallation de la joueuse dont c'est le tour
    // joueuse joueuse_courante = joueuse_tour(joueuse1, joueuse2);

    // // Création des zones
    // zones zones = createZones(10);

    // // Indice de la joueuse dont c'est le tour
    // int tour = 0; 

    // // Zone de depart pour la joueuse
    // // zone* zone_depart;


    // // Creation du personage MONSTRE en le mettant dans sa zone
    // personnage  monstre =  createPerso(MONSTRE,"Monstre",FISE);
    
    // /*Boucle principale du jeu
    // * Quand tous les membres de l'ecole d'une des joueuse n'ont pas etaits mangé
    // */ 
    // while (!verifie_manges(joueuse1) && !verifie_manges(joueuse2)) {
    //     // Affichage des informations du jeu
    //     afficher_informations(zones, tour, joueuse1, joueuse2);
        
    //     // Demande du capital à utiliser pour la joueuse courante
    //     int capital = demander_capital_joueuse(joueuse_courante);

    //     // utiliser le capital pour la joueuse courante
    //     utiliser_capital(joueuse_courante, capital);
        
    //     // Demander une carte a la joueuse courante
    //     carte carte_jouee = demander_carte_joueuse(joueuse_courante, tour);

    //     // si la carte demandé est non null alors on joue la carte
    //     if (carte_jouee != NULL) {
    //         jouer_carte(joueuse_courante, carte_jouee);
    //     }

    //     // Déplacement du monstre
    //     // int num_zone_arrivee_monstre = getNextZone(zone_monstre);
    //     // movePerso(monstre, getZoneById(zones, num_zone_arrivee_monstre));

    //     int nb_membres_ecole = nb_joueurs_ecoles(joueuse_courante);
    //     if (nb_membres_ecole > 0) {
    //         // Déplacement des membres de l'école
    //         personnage* membres_ecolE = membres_joueurs(joueuse_courante);
    //         for (int i = 0; i < nb_membres_ecole; i++) {
    //             // zone_depart = getZoneById(zones, getZonePerso(membres_ecolE[i]));
    //             // int num_zone_arrivee = getNextZone(zone_depart);

    //             // // Déplacement des personnages
    //             // movePerso(membres_ecolE[i], getZoneById(zones, num_zone_arrivee));
    //             // afficher_membre_deplacE(membres_ecolE[i]);

    //             // si le personage se depalce dans la zone du montre il est mangés
    //             if (get_zone_personnage(monstre) == getZonePerso(membres_ecolE[i])) {
    //                 // afficher_membre_mangE(membres_ecolE[i]);
    //                 isEaten(membres_ecolE[i]);
    //                 i--;
    //             }

    //             // décisions des joueuses
    //             if (capital > 0) {
    //                 // apply_decision(zones, capital);
    //             }
                
    //         }
    //         free(membres_ecolE);
    //     }

    //     // On vérifie si une joueuse a perdu
    //     if (verifie_manges(joueuse1) || verifie_manges(joueuse2)) {
    //         break;
    //     }
        
    //     // On passe au tour de l'autre joueuse
    //     tour++;
    //     joueuse_courante = joueuse_tour(joueuse1, joueuse2);
    // }
    
    // // Affichage du message de fin de jeu
    // afficher_fin_jeu();
    
    // // Libération de la mémoire
    // liberermemoire(&joueuse1, &joueuse2);
    // freeZones(&zones);
    
    return 0;
}
