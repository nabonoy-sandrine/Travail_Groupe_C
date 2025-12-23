// implémente les fonctions permettant d’ajouter, afficher, rechercher, modifier et supprimer des étudiants.

#include "etudiant.h"
#include <string.h>
#include <time.h>

/* ========= MENU ========= */

void menu()
{
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                                              ║\n");
    printf("║          GESTION DES ÉTUDIANTS               ║\n");
    printf("║                                              ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║  1️⃣  Enregistrer un étudiant                ║\n");
    printf("║  2️⃣  Modifier un étudiant                   ║\n");
    printf("║  3️⃣  Rechercher un étudiant (dichotomie)    ║\n");
    printf("║  4️⃣  Supprimer un étudiant                  ║\n");
    printf("║  5️⃣  Trier par ordre alphabétique (Nom)     ║\n");
    printf("║  6️⃣  Calculer l'âge d'un étudiant           ║\n");
    printf("║  7️⃣  Trier par filière                      ║\n");
    printf("║  8️⃣  Afficher la liste des étudiants        ║\n");
    printf("║                                              ║\n");
    printf("║  0️⃣  Quitter                                ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf(" Votre choix : ");
}

/* ========= ENREGISTREMENT ========= */

void enregistrer_etudiant(Gestion_des_Etudians *e)
{ 

}

void ajouter_etudiant(Gestion_des_Etudians tab[], int *n)
{
   
}

/* ========= TRI ========= */

void trier_par_nom(Gestion_des_Etudians tab[], int n)
{
   
}

void trier_par_filiere(Gestion_des_Etudians tab[], int n)
{
    
}

/* ========= RECHERCHE PAR DICHOTOMIE ========= */

int rechercher_etudiant(Gestion_des_Etudians tab[], int n, char mat[])
{

}

/* ========= MODIFIER ========= */

void modifier_etudiant(Gestion_des_Etudians tab[], int n)
{
    
}

/* ========= SUPPRESSION ========= */

void supprimer_etudiant(Gestion_des_Etudians tab[], int *n)
{
    
}

/* ========= AFFICHAGE ========= */

void afficher_etudiants(Gestion_des_Etudians tab[], int n)
{
    
}

/* ========= AGE ========= */

int calculer_age(Gestion_des_Etudians e)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Age : %d ans\n", tm.tm_year + 1900 - e.annee);
}
