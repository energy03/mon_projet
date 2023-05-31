#include <stdio.h>
#include "../headers/interface.h"
#include "../headers/globals.h"
#include "../headers/constantes.h"
#include <stdlib.h>
#include <time.h>

// Fonction pour afficher toutes les informations du jeu
void afficher_informations() {
    printf("******************TOUR%d ******************\n",TOUR);
    // affichage des membres présents dans chaque zone
    for(int i=0;i<get_nb_zones(ZONES);i++){
        printf("******************zone %d ******************\n",i+1);
        for(int j=0;j<get_nb_perso_zone(getZoneById(ZONES,i+1));j++){
            personnage* tab_perso=get_tab_perso_zone(getZoneById(ZONES,i+1));

            printf("%s ;; ",get_nom_personnage(tab_perso[j]));
        }
        printf("\n");
    }
    printf("\n");
    

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


/// @brief initialisation de l'interface
void init_interface() {
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

    // Initialisation du monstre
    set_zone_personnage(MONSTRE_PERS,1);
    get_tab_perso_zone(getZoneById(ZONES,1))[0]=MONSTRE_PERS;
    set_nb_perso_zone(getZoneById(ZONES,1),1);

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
        zone zone_1=getZoneById(ZONES,num_zone_1);
        personnage* perso_zone=get_tab_perso_zone(zone_1);
        perso_zone[get_nb_perso_zone(zone_1)]=membres_ecole1[i];
        set_zone_personnage(membres_ecole1[i],num_zone_1);
        set_nb_perso_zone(zone_1,get_nb_perso_zone(zone_1)+1);
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
        zone zone_2=getZoneById(ZONES,num_zone_2);
        personnage* perso_zone=get_tab_perso_zone(zone_2);
        perso_zone[get_nb_perso_zone(zone_2)]=membres_ecole2[i];
        set_zone_personnage(membres_ecole2[i],num_zone_2);
        set_nb_perso_zone(zone_2,get_nb_perso_zone(zone_2)+1);
    }
}

/// @brief liberation de l'interface
void free_interface() {
    liberermemoire(&JOUEUSE_1,&JOUEUSE_2);

    freeZones(&ZONES);

    freePerso(&MONSTRE_PERS);

    freePerso(&MEMBRE_1);
    freePerso(&MEMBRE_2);
    freePerso(&MEMBRE_3);
    freePerso(&MEMBRE_4);
    freePerso(&MEMBRE_5);
    freePerso(&MEMBRE_6);
    freePerso(&MEMBRE_7);
    freePerso(&MEMBRE_8);
    freePerso(&MEMBRE_9);
    freePerso(&MEMBRE_10);

    freeCarte(&MASSINISSA_MERABET);
    freeCarte(&FETIA_BANNOUR);
    freeCarte(&VALENTIN_HONORE);
    freeCarte(&RENAUD_RIOBOO);
    freeCarte(&KEVIN_GOILARD);
    freeCarte(&LAURENCE_BOURARD);
    freeCarte(&DENISSE_MUNANTE);
    freeCarte(&CYRIL_BENEZET);
    freeCarte(&ANNE_LAURE_LIGOZAT);
    freeCarte(&CHRISTOPHE_MOUILLERON);
    freeCarte(&DJIBRIL_AURELIEN_DEMBELE_CABOT);
    freeCarte(&LUCIENNE_PACAVE);
    freeCarte(&JEROME_HUET);
    freeCarte(&CHRISTINE_MATHIAS);
    freeCarte(&KATRIN_SALHAB);
    freeCarte(&SERGIO_PULIDO_NINO);
    freeCarte(&DIMITRI_WATEL);
    freeCarte(&MARIE_SZAFRANSKI);
    freeCarte(&JULIEN_FOREST);
}

/// @brief déplacement des personnages et des monstres
void deplacement(){
    // Déplacement du montre
            zone cur_zn = getZoneById(ZONES,get_zone_personnage(MONSTRE_PERS)) ;
            int next_zn = getNextZone(cur_zn);
            if(next_zn!=get_num_zone(cur_zn)){
                movePerso(MONSTRE_PERS,next_zn);
            }

            // Déplacement des personnages vivants des joueuses
            personnage* membres_ecole1 = get_membres_joueuse(JOUEUSE_1);
            int nb_membres_ecole1 = get_nb_membres_joueuse(JOUEUSE_1);
            for(int i=0;i<nb_membres_ecole1;i++){
                if(!isEaten(membres_ecole1[i])){
                    zone cur_zn_1 = getZoneById(ZONES,get_zone_personnage(membres_ecole1[i])) ;
                    int next_zn_1 = getNextZone(cur_zn_1);
                    if(next_zn_1!=get_num_zone(cur_zn_1)){
                        movePerso(membres_ecole1[i],next_zn_1);
                    }
                }
            }

            personnage* membres_ecole2 = get_membres_joueuse(JOUEUSE_2);
            int nb_membres_ecole2 = get_nb_membres_joueuse(JOUEUSE_2);
            for(int i=0;i<nb_membres_ecole2;i++){
                if(!isEaten(membres_ecole2[i])){
                    zone cur_zn_2 = getZoneById(ZONES,get_zone_personnage(membres_ecole2[i])) ;
                    int next_zn_2 = getNextZone(cur_zn_2);
                    if(next_zn_2!=get_num_zone(cur_zn_2)){
                        movePerso(membres_ecole2[i],next_zn_2);
                    }
                }

            }
}

/// @brief appliquer les effets des deplacements
// Les personages qui sont dans la meme zone que les monstres sont mangés
// Le tableau des personnages de la zone est mis à jour : la première case du tableau est occupée par le monstre et les autres cases sont mises à NULL
void apply_effet_deplacement(){
    // Les personnages qui sont dans la meme zone que les monstres sont mangés

    // Joueuse 1
    personnage* membres_ecole1 = get_membres_joueuse(JOUEUSE_1);
    int nb_membres_ecole1 = get_nb_membres_joueuse(JOUEUSE_1);
    for(int i=0;i<nb_membres_ecole1;i++){
        if(get_zone_personnage(membres_ecole1[i])==get_zone_personnage(MONSTRE_PERS)){
            set_vie_personnage(membres_ecole1[i],MANGE);
            afficher_membre_mange(membres_ecole1[i]);
        }
    }

    // Joueuse 2
    personnage* membres_ecole2 = get_membres_joueuse(JOUEUSE_2);
    int nb_membres_ecole2 = get_nb_membres_joueuse(JOUEUSE_2);
    for(int i=0;i<nb_membres_ecole2;i++){
        if(get_zone_personnage(membres_ecole2[i])==get_zone_personnage(MONSTRE_PERS)){
            set_vie_personnage(membres_ecole2[i],MANGE);
            afficher_membre_mange(membres_ecole2[i]);
        }
    }

    // Le tableau des personnages de la zone est mis à jour : la première case du tableau est occupée par le monstre et les autres cases sont mises à NULL
    zone cur_zn = getZoneById(ZONES,get_zone_personnage(MONSTRE_PERS)) ;
    personnage* tab_perso=get_tab_perso_zone(cur_zn);
    tab_perso[0]=MONSTRE_PERS;
    for(int i=1;i<get_nb_perso_zone(cur_zn);i++){
        tab_perso[i]=NULL;
    }
    set_nb_perso_zone(cur_zn,1);
}