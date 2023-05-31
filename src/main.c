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
#include "../headers/structures.h"

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

int TOUR=0;

int main()
{
    init_interface();
    

        // Boucle du jeu
    while(!verifie_manges(JOUEUSE_1) && !verifie_manges(JOUEUSE_2)){
        int choix;
        TOUR++;
        printf("******************Tour %d ******************\n",TOUR);
        // Affichage des informations du jeu
        afficher_informations();
        
        do{
            printf("Choisissez une action à effectuer:\n");
            printf("1. Utiliser votre capital\n");
            printf("2. Utiliser une carte\n");
            printf("3. Passer aux deplacements\n");
            printf("4. Afficher les informations du jeu\n");
            printf("5. Quitter le jeu\n");
            scanf("%d",&choix);
            switch (choix){

                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    
                        

                    break;
                case 4:
                    afficher_informations();
                    break;
                case 5:
                    printf("Au revoir\n");
                    free_interface();
                    exit(0);
                    // Quitter instatanement les deux boucles while
                    
            }

        }while(choix!=3);
        // Deplacement des personnages
        deplacement();
        apply_effet_deplacement();
            
    }

    /// Liberation de la memoire
    free_interface();
    
    return 0;
}
