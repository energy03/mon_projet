#include <stdio.h>
#include "../headers/cartes.h"

/*****************************************
 * ***************************************
 * ***************************************
 *       TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/

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
    DJI_CAB,    // id de la carte Djilali Chaban
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
typedef enum id_card id_card;

struct carte
{   
    id_card id;
    char* nom;
    char* description;
};

/// @brief variable globale contenant les cartes du jeu
struct carte cartes[20]={
    {MAS_MER,"Massinissa Merabet" , "Augmente le capital de 2 pendant les 3 prochains tours"},
    {FET_BAN,"Fetia Bannour" , "Echange des personnages présents dans les deux zones choisies."},
    {VAL_HON,"Valentin Honoré",	"Chaque monstre se déplace 3 fois. Chaque membre d'école qu'un monstre rencontre est mangé."},
    {REN_RIO,"Renaud Rioboo","Lors du prochain tour, la joueuse adverse ne choisit pas comment est utilisé son capital. Chaque point de capital est utilisé aléatoirement: pour chaque point, choisissez les trois zones Z1, Z2 et Z3 uniformément parmi les triplets pouvant être choisis."},
    {KEV_GOI,"Kevin Goilard",	"Lors du prochain tour et du suivant, c'est vous qui jouez. Lors des deux tours suivant, c'est la joueuse adverse qui joue."},
    {LAU_BOU,"Laurence Bourard",	"Lors du prochain déplacement, si deux membres d'écoles adverses se retrouvent sur la même zone, ils se déplacent de nouveau. Si ces deux membres sont sur la zone du monstre avant le second déplacement, ils ne sont pas mangés. On recommence l'opération au plus 100 fois, jusqu'à ce que les membres des écoles adverses soient sur des zones distinctes."},
    {DEN_MUN,"Denisse Munante",	"Les membres d'écoles présents sur la zone où était un monstre avant son dernier déplacement sont mangés."},
    {CYR_BEN,"Cyril Benezet",	"Déplacez un des monstres sur la zone de votre choix. Si un membre d'école se trouve sur la zone du monstre, il n'est pas mangé."},
    {ANN_LIG,"Anne-Laure Ligozat",	"Choisissez un membre de votre école, il effectue désormais deux déplacements au lieu d'un à chaque tour."},
    {CHR_MAT,"Christophe Mouilleron",	"Choisissez un membre de l'école de la joueuse adverse. Ce membre devient un membre de votre école."},
    {DJI_CAB,"Djibril-Aurelien Dembele-Cabot",	"Sacrifiez un membre de votre école de votre choix. Vous avez 15 points de capital en plus à votre prochain tour."},
    {LUC_PAC,"Lucienne Pacave",	"Créez une nouvelle zone. Les membres de votre école sont les seuls à pouvoir se déplacer sur cette zone. Un membre de l'école de l'autre joueuse qui devrait se déplacer sur cette zone ne se déplace pas. La probabilité d'aller sur cette zone est de 0. Depuis cette zone, la probabilité de rester sur cette zone est 1."},
    {JER_HUE,"Jerome Huet",	"Chaque zone effectue une rotation de probabilité. La probabilité d'aller de la zone i à la zone j devient la probabilité d'aller de la zone i à la zone j + 1. La probabilité d'aller de la zone i à la zone 10 devient la probabilité d'aller de la zone i à la zone 1."},
    {CHR_MAT,"Christine Matias",	"Chaque monstre disparaît pendant 2 tours. Il réapparaîtra sur la zone d'où il est parti."},
    {KAT_SAL,"Katrin Salhab",	"Pendant vos 3 prochains tours, un point de capital permet de déplacer une quantité 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9 ou 1 de probabilité."},
    {KAT_SAL,"Sergio Pulido-Nino",	"Mettez à 0 les probabilités permettant de sortir de la zone de chaque monstre et mettez à 1 la probabilité de rester dans la zone de chaque monstre."},
    {DIM_WAT,"Dimitri Watel",	"Choisissez un membre de votre école, il devient FISA et effectue désormais son déplacement un tour sur deux."},
    {MAR_SZA,"Marie Szafranski",	"Ajoutez un monstre sur la zone 1, un membre de votre école sur la zone 2 et un membre de l'école adverse sur la zone 3. Si un membre d'école se trouve sur la même zone qu'un monstre, il n'est pas mangé."},
    {JUL_FOR,"Julien Forest",	"Mettez toutes les probabilités à 0. Puis, pour chaque zone, la probabilité de se déplacer de cette zone vers la zone contenant le monstre passe à 0.5 (s'il y a plusieurs monstres, un des monstres est choisi aléatoirement) ; et la probabilité de se déplacer de cette zone vers une autre zone ne contenant pas de monstre choisie aléatoirement passe également à 0.5."},
    {LAU_PRE,"Laurent Prével",	"Pendant 4 tours, les membres de votre école ne peuvent être mangés par un monstre. S'ils sont sur sa zone à la fin du tour, rien ne se passe, ils restent sur cette case."}
};

/*****************************************
 * ***************************************
 * ***************************************
 *       TACHE B5
 * ***************************************
 * ***************************************
 * ***************************************
*/




