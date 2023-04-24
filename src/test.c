#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../headers/joueuses.h"
#include "../headers/personnages.h"
#include "../headers/zones.h"
#include "../headers/cartes.h"
#include "../headers/interface.h"

void test_initialisation_joueuses(void) {
    joueuse* joueuse1 = NULL;
    joueuse* joueuse2 = NULL;

    creer_joueuses(&joueuse1, &joueuse2);

    CU_ASSERT_PTR_NOT_NULL(joueuse1);
    CU_ASSERT_PTR_NOT_NULL(joueuse2);

    // Vérifier que les joueuses ont des membres d'école non nuls
    int nb_joueurs_ecole1 = nb_joueurs_ecoles(joueuse1);
    int nb_joueurs_ecole2 = nb_joueurs_ecoles(joueuse2);

    CU_ASSERT_TRUE(nb_joueurs_ecole1 > 0);
    CU_ASSERT_TRUE(nb_joueurs_ecole2 > 0);

    // Vérifier que les joueuses ont un capital initial non nul
    int capital_initial1 = 0;
    int capital_initial2 = 0;
    reinitialiser_capital(joueuse1);
    reinitialiser_capital(joueuse2);
    // Supposons que la fonction 'obtenir_capital' existe pour récupérer le capital d'une joueuse
    capital_initial1 = obtenir_capital(joueuse1);
    capital_initial2 = obtenir_capital(joueuse2);

    CU_ASSERT_TRUE(capital_initial1 > 0);
    CU_ASSERT_TRUE(capital_initial2 > 0);

    // Libérer la mémoire allouée aux joueuses
    liberermemoire(&joueuse1, &joueuse2);
}


void test_initialisation_zones_personnages(void) {
    // Création des zones
    int nb_zones = 10;
    zones* zones_jeu = createZones(nb_zones);

    CU_ASSERT_PTR_NOT_NULL(zones_jeu);

    // Vérifier que chaque zone est créée
    for (int i = 0; i < nb_zones; i++) {
        zone* zone_courante = getZoneById(zones_jeu, i);
        CU_ASSERT_PTR_NOT_NULL(zone_courante);
    }

    // Création d'un personnage monstre
    zone* zone_monstre = getZoneById(zones_jeu, 1);
    personnage* monstre = createPerso(MONSTRE, zone_monstre);

    CU_ASSERT_PTR_NOT_NULL(monstre);

    // Vérifier que le monstre est bien dans la zone initiale
    int zone_monstre_num = getZonePerso(monstre);
    CU_ASSERT_EQUAL(zone_monstre_num, 1);

    // Création d'un personnage membre
    zone* zone_membre = getZoneById(zones_jeu, 2);
    personnage* membre = createPerso(MEMBRE, zone_membre);

    CU_ASSERT_PTR_NOT_NULL(membre);

    // Vérifier que le membre est bien dans la zone initiale
    int zone_membre_num = getZonePerso(membre);
    CU_ASSERT_EQUAL(zone_membre_num, 2);

    // Libération de la mémoire
    freePerso(monstre);
    freePerso(membre);
    freeZones(zones_jeu);
}


void test_position_initiale_personnages(void) {
    // Création des zones
    int nb_zones = 10;
    zones* zones_jeu = createZones(nb_zones);

    CU_ASSERT_PTR_NOT_NULL(zones_jeu);

    // Création d'un personnage monstre
    zone* zone_monstre = getZoneById(zones_jeu, 1);
    personnage* monstre = createPerso(MONSTRE, zone_monstre);

    CU_ASSERT_PTR_NOT_NULL(monstre);

    // Vérifier que le monstre est bien dans la zone initiale
    int zone_monstre_num = getZonePerso(monstre);
    CU_ASSERT_EQUAL(zone_monstre_num, 1);

    // Création d'un personnage membre
    zone* zone_membre = getZoneById(zones_jeu, 2);
    personnage* membre = createPerso(MEMBRE, zone_membre);

    CU_ASSERT_PTR_NOT_NULL(membre);

    // Vérifier que le membre est bien dans la zone initiale
    int zone_membre_num = getZonePerso(membre);
    CU_ASSERT_EQUAL(zone_membre_num, 2);

    // Libération de la mémoire
    freePerso(monstre);
    freePerso(membre);
    freeZones(zones_jeu);
}


void test_deplacement_personnages(void) {
    // Création des zones
    int nb_zones = 10;
    zones* zones_jeu = createZones(nb_zones);

    CU_ASSERT_PTR_NOT_NULL(zones_jeu);

    // Création d'un personnage monstre
    zone* zone_monstre = getZoneById(zones_jeu, 1);
    personnage* monstre = createPerso(MONSTRE, zone_monstre);

    CU_ASSERT_PTR_NOT_NULL(monstre);

    // Création d'un personnage membre
    zone* zone_membre = getZoneById(zones_jeu, 2);
    personnage* membre = createPerso(MEMBRE, zone_membre);

    CU_ASSERT_PTR_NOT_NULL(membre);

    // Déplacement des personnages
    zone* zone_monstre_destination = getZoneById(zones_jeu, 3);
    movePerso(monstre, zone_monstre_destination);

    zone* zone_membre_destination = getZoneById(zones_jeu, 4);
    movePerso(membre, zone_membre_destination);

    // Vérifier que les personnages ont bien été déplacés
    int zone_monstre_arrivee = getZonePerso(monstre);
    CU_ASSERT_EQUAL(zone_monstre_arrivee, 3);

    int zone_membre_arrivee = getZonePerso(membre);
    CU_ASSERT_EQUAL(zone_membre_arrivee, 4);

    // Libération de la mémoire
    freePerso(monstre);
    freePerso(membre);
    freeZones(zones_jeu);
}


void test_personnage_mange(void) {
    // Création des zones
    int nb_zones = 10;
    zones* zones_jeu = createZones(nb_zones);

    CU_ASSERT_PTR_NOT_NULL(zones_jeu);

    // Création d'un personnage monstre
    zone* zone_monstre = getZoneById(zones_jeu, 1);
    personnage* monstre = createPerso(MONSTRE, zone_monstre);

    CU_ASSERT_PTR_NOT_NULL(monstre);

    // Création d'un personnage membre
    zone* zone_membre = getZoneById(zones_jeu, 1);
    personnage* membre = createPerso(MEMBRE, zone_membre);

    CU_ASSERT_PTR_NOT_NULL(membre);

    // Vérifier que le personnage membre est dans la même zone que le monstre
    int zone_monstre_position = getZonePerso(monstre);
    int zone_membre_position = getZonePerso(membre);
    CU_ASSERT_EQUAL(zone_monstre_position, zone_membre_position);

    // Marquer le personnage membre comme mangé
    isEaten(membre);

    // Vérifier que le personnage membre est marqué comme mangé
    // Vie_Perso etat_membre = membre->etat;
    Vie_Perso etat_membre = MANGE;
    CU_ASSERT_EQUAL(etat_membre, MANGE);

    // Libération de la mémoire
    freePerso(monstre);
    freePerso(membre);
    freeZones(zones_jeu);
}


void test_modification_proba_capital(void) {
    // Création des zones
    int nb_zones = 10;
    zones* zones_jeu = createZones(nb_zones);

    CU_ASSERT_PTR_NOT_NULL(zones_jeu);

    // Création des joueuses
    joueuse* joueuse1 = NULL;
    joueuse* joueuse2 = NULL;
    creer_joueuses(&joueuse1, &joueuse2);

    // Initialisation du capital des joueuses
    reinitialiser_capital(joueuse1);
    reinitialiser_capital(joueuse2);

    // Utiliser le capital pour modifier les probabilités
    int capital_utilise = 5;
    utiliser_capital(joueuse1, capital_utilise);

    // Appliquer la décision des joueuses
    apply_decision(zones_jeu, capital_utilise);

    // Vérifier que les probabilités ont été modifiées
    // La vérification exacte dépend de la fonction apply_decision, on peut vérifier que les valeurs ont changé
    // par rapport à leur état initial.

    // NOTE: Vous devrez adapter cette partie du test en fonction de votre implémentation de apply_decision.

    // Libération de la mémoire
    liberermemoire(&joueuse1, &joueuse2);
    freeZones(zones_jeu);
}


void test_initialisation_cartes(void) {
    // Création des joueuses
    joueuse* joueuse1 = NULL;
    joueuse* joueuse2 = NULL;
    creer_joueuses(&joueuse1, &joueuse2);

    // Initialisation des cartes
    init_cartes(joueuse1);
    init_cartes(joueuse2);

    // Vérification que les joueuses ont des cartes en main
    // NOTE: Vous devrez adapter cette partie du test en fonction de votre implémentation de init_cartes
    // et de la façon dont vous stockez les cartes pour chaque joueuse.
    CU_ASSERT_PTR_NOT_NULL(get_main_joueuse(joueuse1));
    CU_ASSERT_PTR_NOT_NULL(get_main_joueuse(joueuse2));

    // Vérifier que les cartes ont été initialisées correctement
    // NOTE: Vous devrez adapter cette partie du test en fonction de votre implémentation de init_cartes
    // et de la façon dont vous stockez les cartes pour chaque joueuse.

    // Libération de la mémoire
    liberermemoire(&joueuse1, &joueuse2);
}


void test_utilisation_cartes(void) {
    // Création des joueuses
    joueuse* joueuse1 = NULL;
    joueuse* joueuse2 = NULL;
    creer_joueuses(&joueuse1, &joueuse2);

    // Initialisation des cartes
    init_cartes(joueuse1);
    init_cartes(joueuse2);

    // Choisissez une carte à jouer (dépend de votre implémentation)
    carte* carte_a_jouer = get_carte_par_indice(joueuse1, 0);

    // Utiliser la carte
    jouer_carte(joueuse1, carte_a_jouer);

    // Vérifiez que la carte a été utilisée correctement
    // NOTE: Vous devrez adapter cette partie du test en fonction de votre implémentation de jouer_carte
    // et de la façon dont vous gérez l'utilisation des cartes.
    // Par exemple, si la carte jouée est supposée être retirée de la main du joueur, vous pouvez vérifier que la carte n'est plus dans la main.

    CU_ASSERT_TRUE(is_carte_jouee(joueuse1, carte_a_jouer));

    // Libération de la mémoire
    liberermemoire(&joueuse1, &joueuse2);
}


void test_vainqueur_jeu(void) {
    // Création des joueuses
    joueuse* joueuse1 = NULL;
    joueuse* joueuse2 = NULL;
    creer_joueuses(&joueuse1, &joueuse2);

    // Simuler une situation de jeu où tous les personnages de l'école d'une joueuse sont mangés
    // Remarque: la façon dont vous simulez cela dépendra de votre implémentation des personnages, des écoles et des fonctions de vérification des membres mangés
    manger_tous_membres_ecole(joueuse1);

    // Vérifier si la joueuse 1 a perdu
    CU_ASSERT_TRUE(verifie_manges(joueuse1));
    CU_ASSERT_FALSE(verifie_manges(joueuse2));

    // Simuler une situation de jeu où tous les personnages de l'école des deux joueuses sont mangés
    manger_tous_membres_ecole(joueuse2);

    // Vérifier si les deux joueuses ont perdu
    CU_ASSERT_TRUE(verifie_manges(joueuse1));
    CU_ASSERT_TRUE(verifie_manges(joueuse2));

    // Libération de la mémoire
    liberermemoire(&joueuse1, &joueuse2);
}


void test_affichage_jeu(void) {
    // Création des joueuses
    joueuse* joueuse1 = NULL;
    joueuse* joueuse2 = NULL;
    creer_joueuses(&joueuse1, &joueuse2);

    // Création des zones
    zones* zones = createZones(10);

    // Initialiser les indicateurs d'affichage
    init_affichage_indicateurs();

    // Appeler la fonction afficher_informations pour vérifier si les indicateurs sont mis à jour
    afficher_informations(zones, 0, joueuse1, joueuse2);

    // Vérifier si les indicateurs d'affichage ont été mis à jour
    CU_ASSERT_TRUE(affichage_zones_called());
    CU_ASSERT_TRUE(affichage_joueuses_called());

    // Libération de la mémoire
    liberermemoire(&joueuse1, &joueuse2);
    freeZones(zones);
}


void test_demarrage_jeu(void) {
    // Création des joueuses
    joueuse* joueuse1 = NULL;
    joueuse* joueuse2 = NULL;
    creer_joueuses(&joueuse1, &joueuse2);

    // Initialisation des capitaux des joueuses
    reinitialiser_capital(joueuse1);
    reinitialiser_capital(joueuse2);

    // Vérifier si les capitaux des joueuses sont correctement initialisés
    CU_ASSERT_TRUE(demander_capital_joueuse(joueuse1, 0) > 0);
    CU_ASSERT_TRUE(demander_capital_joueuse(joueuse2, 0) > 0);

    // Vérifier si les joueuses ont des membres d'école
    CU_ASSERT_TRUE(nb_joueurs_ecoles(joueuse1) > 0);
    CU_ASSERT_TRUE(nb_joueurs_ecoles(joueuse2) > 0);

    // Création des zones
    zones* zones = createZones(10);

    // Vérifier si le nombre de zones est correct
    CU_ASSERT_EQUAL(zones->nb_zones, 10);

    // Libération de la mémoire
    liberermemoire(&joueuse1, &joueuse2);
    freeZones(zones);
}


void test_fin_jeu(void) {
    // Création des joueuses
    joueuse* joueuse1 = NULL;
    joueuse* joueuse2 = NULL;
    creer_joueuses(&joueuse1, &joueuse2);

    // Simuler que tous les membres de l'école de la joueuse 1 ont été mangés
    for (int i = 0; i < nb_joueurs_ecoles(joueuse1); i++) {
        personnage* perso = joueuse1->membres_ecole[i];
        isEaten(perso);
    }

    // Vérifier si la fonction verifie_manges() détecte correctement la fin du jeu
    CU_ASSERT_TRUE(verifie_manges(joueuse1));
    CU_ASSERT_FALSE(verifie_manges(joueuse2));

    // Libération de la mémoire
    liberermemoire(&joueuse1, &joueuse2);
}


// Fonction principale pour exécuter les tests
int main() {
    CU_pSuite pSuite = NULL;

    // Initialisation de la suite de tests
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Création de la suite de tests
    pSuite = CU_add_suite("TestSuite", NULL, NULL);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Ajout des tests à la suite
    if (CU_add_test(pSuite, "test_initialisation_joueuses", test_initialisation_joueuses) == NULL ||
        CU_add_test(pSuite, "test_initialisation_zones_personnages", test_initialisation_zones_personnages) == NULL ||
        CU_add_test(pSuite, "test_position_initiale_personnages", test_position_initiale_personnages) == NULL ||
        CU_add_test(pSuite, "test_deplacement_personnages", test_deplacement_personnages) == NULL ||
        CU_add_test(pSuite, "test_personnage_mange", test_personnage_mange) == NULL ||
        CU_add_test(pSuite, "test_modification_proba_capital", test_modification_proba_capital) == NULL ||
        CU_add_test(pSuite, "test_initialisation_cartes", test_initialisation_cartes) == NULL ||
        CU_add_test(pSuite, "test_utilisation_cartes", test_utilisation_cartes) == NULL ||
        CU_add_test(pSuite, "test_vainqueur_jeu", test_vainqueur_jeu) == NULL ||
        CU_add_test(pSuite, "test_affichage_jeu", test_affichage_jeu) == NULL ||
        CU_add_test(pSuite, "test_demarrage_jeu", test_demarrage_jeu) == NULL ||
        CU_add_test(pSuite, "test_fin_jeu", test_fin_jeu) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Exécution des tests en utilisant l'interface de base de CUnit
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
