#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "joueuses.h"
#include "personnages.h"
#include "zones.h"
#include "cartes.h"
#include "interface.h"

int main()
{
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Création des joueuses
    joueuse* joueuse1 = NULL;
    joueuse* joueuse2 = NULL;
    creer_joueuses(joueuse1, joueuse2);

    // initialisation de leur capital
    reinitialiser_capital(joueuse1);
    reinitialiser_capital(joueuse2);

    // Initiallation de la joueuse dont c'est le tour
    joueuse* joueuse_courantE = joueuse_tour(joueuse1, joueuse2);

    // Création des zones
    zones* zones = createZones(10);

    // Indice de la joueuse dont c'est le tour
    int tour = 0; 

    // Zone de depart pour la joueuse
    zone* zone_depart;

    // Création de la zone du MONSTRE
    zone* zone_monstre =  getZoneById(zones, 1);

    // Creation du personage MONSTRE en le mettant dans sa zone
    personnage*  monstre =  createPerso(MONSTRE, zone_monstre);
    
    /*Boucle principale du jeu
    * Quand tous les membres de l'ecole d'une des joueuse n'ont pas etaits mangé
    */ 
    while (!verifie_manges(joueuse1) && !verifie_manges(joueuse2)) {
        // Affichage des informations du jeu
        afficher_informations(zones, tour, joueuse1, joueuse2);
        
        // Demande du capital à utiliser pour la joueuse courante
        int capital = demander_capital_joueuse(joueuse_courantE, tour);

        // utiliser le capital pour la joueuse courante
        utiliser_capital(joueuse_courantE, capital);
        
        // Demander une carte a la joueuse courante
        carte* carte_jouee = demander_carte_joueuse(joueuse_courantE, tour);

        // si la carte demandé est non null alors on joue la carte
        if (carte_jouee != NULL) {
            jouer_carte(joueuse_courantE, carte_jouee);
        }

        // Déplacement du monstre
        zone_monstre = getZoneById(zones, getZonePerso(monstre));
        int num_zone_arrivee_monstre = getNextZone(zone_monstre);
        movePerso(monstre, getZoneById(zones, num_zone_arrivee_monstre));

        int nb_membres_ecole = nb_joueurs_ecoles(joueuse_courantE);
        if (nb_membres_ecole > 0) {
            // Déplacement des membres de l'école
            personnage** membres_ecolE = membres_joueurs(joueuse_courantE);
            for (int i = 0; i < nb_membres_ecole; i++) {
                zone_depart = getZoneById(zones, getZonePerso(membres_ecolE[i]));
                int num_zone_arrivee = getNextZone(zone_depart);

                // Déplacement des personnages
                movePerso(membres_ecolE[i], getZoneById(zones, num_zone_arrivee));
                afficher_membre_deplacE(membres_ecolE[i]);

                // si le personage se depalce dans la zone du montre il est mangés
                if (zone_monstre == getZoneById(zones, getZonePerso(membres_ecolE[i]))) {
                    afficher_membre_mangE(membres_ecolE[i]);
                    isEaten(membres_ecolE[i]);
                    i--;
                }
                // int montant_utilise = 1;
                if (capital > 0) {
                    apply_decision(zones, capital);
                }
            }
            free(membres_ecolE);
        }

        // On vérifie si une joueuse a perdu
        if (verifie_manges(joueuse1) || verifie_manges(joueuse2)) {
            break;
        }
        
        // On passe au tour de l'autre joueuse
        tour++;
        joueuse_courantE = joueuse_tour(joueuse1, joueuse2);
    }
    
    // Affichage du message de fin de jeu
    afficher_fin_jeu();
    
    // Libération de la mémoire
    liberermemoire(joueuse1, joueuse2);
    freeZones(zones);
    
    return 0;
}
