#include "cartes.h"
#include "zones.h"
#include "joueuses.h"
#include "personnages.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void effet_carte_massinissa_merabet(joueuse *joueuse) {
    (*joueuse)->capital= 3;
}

void effet_carte_fetia_bannour(zones *zones, int zone1, int zone2) {
    personnage temp= malloc(sizeof(personnage));
    *temp = (*zones)->tabZones[zone1].personnages;
    (*zones)->tabZones[zone1].perso = (*zones)->tabZones[zone2].perso;
    (*zones)->tabZones[zone2].perso = temp;
}

void effet_carte_valentin_honore(zones *zones, personnage *monstres) {
    for (int i = 0; i < monstres->nombre_monstres; i++) {
        deplacer_monstre(zones, &(monstres->liste_monstres[i]));
        manger_personnages(zones, &(monstres->liste_monstres[i]));
    }
}

void effet_carte_renaud_rioboo(joueuse *joueuse_adverse) {
    joueuse_adverse->prochain_tour_aleatoire = 1;
}

void effet_carte_kevin_goilard(joueuse *joueuse_actuelle, joueuse *joueuse_adverse) {
    (*joueuse_actuelle)->peut_jouer = 0;
    joueuse_adverse->peut_jouer = 1;
}

void effet_carte_denisse_munante(zones *zones, Monstres *monstres) {
    // Implémentez l'effet de la carte ici
}

void effet_carte_cyril_benezet(const personnage *monstre, int zone_cible) {
    monstre->position = zone_cible;
}

void effet_carte_anne_laure_ligozat(personnage *personnage) {
    personnage->deplacements_par_tour = 2;
}

void effet_carte_christophe_mouilleron(personnage *personnage_adverse, personnage *personnage_actuel) {
    personnage_adverse->ecole = personnage_actuel->ecole;
}

void effet_carte_djibril_aurelien_dembele_cabot(personnage *personnage_sacrifie, joueuse *joueuse) {
    personnage_sacrifie->est_mange = 1;
    joueuse->capital_bonus += 15;
}

void effet_carte_christine_matias(personnage *monstres) {
    for (int i = 0; i < monstres->nombre_monstres; i++) {
        monstres->liste_monstres[i].tour_disparition_restant = 2;
    }
}

/*void jouer_carte(joueuse *joueuse_actuelle, joueuse *joueuse_adverse, zones *zones, personnage *monstres, carte *carte) {*/
void jouer_carte(joueuse *joueuse_actuelle, joueuse *joueuse_adverse, zones *zones, personnage *monstres, carte *carte) {
    // Implémentez la logique pour jouer la carte en fonction de son effet
    switch (carte->effet) {
        case MASSINISSA_MERABET:
            effet_carte_massinissa_merabet(joueuse_actuelle);
            break;
        case FETIA_BANNOUR:
            effet_carte_fetia_bannour(zones, /* zone1 */, /* zone2 */, /* zone3 */); // Remplacez zone1, zone2, zone3 par les indices des zones concernées
            break;
        case VALENTIN_HONORE:
            effet_carte_valentin_honore(zones, monstres);
            break;
        case RENAUD_RIOBOO:
            effet_carte_renaud_rioboo(joueuse_adverse);
       ²     break;
        case KEVIN_GOILARD:
            effet_carte_kevin_goilard(joueuse_actuelle, joueuse_adverse);
            break;
        case LAURENCE_BOURARD:
            effet_carte_laurence_bourard(zones, monstres, joueuse_actuelle, joueuse_adverse);
            break;
        case DENISSE_MUNANTE:
            effet_carte_denisse_munante(zones, monstres);
            break;
        case CYRIL_BENEZET:
            effet_carte_cyril_benezet(monstres, /* int monstre_index */, /* int zone_cible */); // Remplacez monstre_index et zone_cible par les indices correspondants
            break;
        case ANNE_LAURE_LIGOZAT:
            effet_carte_anne_laure_ligozat(joueuse_actuelle->personnage, /* int personnage_index */); // Remplacez personnage_index par l'indice du personnage choisi
            break;
        case CHRISTOPHE_MOUILLERON:
            effet_carte_christophe_mouilleron(joueuse_adverse->personnage, /* int personnage_adverse_index */, joueuse_actuelle->personnage); // Remplacez personnage_adverse_index par l'indice du personnage adverse choisi
            break;
        // Ajoutez les autres effets de cartes ici en suivant la même logique
        default:
            // Gérer les cas non pris en charge ou les erreurs
            break;
    }
}
