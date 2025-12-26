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
    printf("║  1️⃣  Enregistrer un étudiant                 ║\n");
    printf("║  2️⃣  Modifier un étudiant                    ║\n");
    printf("║  3️⃣  Rechercher un étudiant (dichotomie)     ║\n");
    printf("║  4️⃣  Supprimer un étudiant                   ║\n");
    printf("║  5️⃣  Trier par ordre alphabétique (Nom)      ║\n");
    printf("║  6️⃣  Calculer l'âge d'un étudiant            ║\n");
    printf("║  7️⃣  Trier par filière                       ║\n");
    printf("║  8️⃣  Afficher la liste des étudiants         ║\n");
    printf("║                                             ║\n");
    printf("║  0️⃣  Quitter                                 ║\n");
    printf("╚══════════════════════════════════════════════ ╝\n");
    printf(" Votre choix : ");
}

/* ===== ENREGISTRER PLUSIEURS ETUDIANTS ===== */
/* Cette fonction correspond AU CASE 1 DU MENU */

void ajouter_etudiant(Gestion_des_Etudians tab[], int *n)
{
    int nb;
    int i;

    printf("Combien d'etudiants voulez-vous enregistrer ? ");
    scanf("%d", &nb);

    if (*n + nb > MAX)
    {
        printf("Erreur : nombre maximum d'etudiants depasse.\n");
        return;
    }

    for (i = 0; i < nb; i++)
    {
        printf("\n--- Etudiant %d ---\n", i + 1);

        printf("Matricule : ");
        scanf("%s", tab[*n].matricule);

        printf("Nom : ");
        scanf("%s", tab[*n].nom);

        printf("Prenom : ");
        scanf("%s", tab[*n].prenom);

        printf("Date de naissance (JJ MM AAAA) : ");
        scanf("%d %d %d",
              &tab[*n].date_naissance.jour,
              &tab[*n].date_naissance.mois,
              &tab[*n].date_naissance.annee);

        do{
          printf("Sexe (M/F) : ");
          scanf(" %c", &tab[*n].sexe);

          if (tab[*n].sexe != 'M' && tab[*n].sexe != 'm' && tab[*n].sexe != 'F' && tab[*n].sexe != 'f'){
             printf("Erreur : vous devez entrer M ou F uniquement.\n");
          }
        } while (tab[*n].sexe != 'M' && tab[*n].sexe != 'm' && tab[*n].sexe != 'F' && tab[*n].sexe != 'f');


        printf("Departement : ");
        scanf("%s", tab[*n].departement);

        printf("Filiere : ");
        scanf("%s", tab[*n].filiere);

        printf("Region d'origine : ");
        scanf("%s", tab[*n].region_origine);

        (*n)++;
    }

    printf("\n Enregistrement termine avec succes !\n");
}


/* ========= TRI ========= */

void trier_par_nom(Gestion_des_Etudians tab[], int n)
{
    int i, j;
    Gestion_des_Etudians temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(tab[i].nom, tab[j].nom) > 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

void trier_par_filiere(Gestion_des_Etudians tab[], int n)
{
    int i, j;
    Gestion_des_Etudians temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(tab[i].filiere, tab[j].filiere) > 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

/* ========= RECHERCHE PAR DICHOTOMIE ========= */

int rechercher_etudiant(Gestion_des_Etudians tab[], int n, char mat[])
{

}

/* ========= MODIFIER ========= */

void modifier_etudiant(Gestion_des_Etudians tab[], int n)
{
    char matricule[10];
    int i;
    int trouve = 0;

    printf("Entrez le matricule de l'etudiant a modifier : ");
    scanf("%s", matricule);

    for (i = 0; i < n; i++)
    {
        if (strcmp(tab[i].matricule, matricule) == 0)
        {
            printf("\n--- Modification de l'etudiant ---\n");

            printf("Nom : ");
            scanf("%s", tab[i].nom);

            printf("Prenom : ");
            scanf("%s", tab[i].prenom);

            printf("Date de naissance (JJ MM AAAA) : ");
            scanf("%d %d %d",
                  &tab[i].date_naissance.jour,
                  &tab[i].date_naissance.mois,
                  &tab[i].date_naissance.annee);

            do{
              printf("Sexe (M/F) : ");
              scanf(" %c", &tab[i].sexe);

              if (tab[i].sexe != 'M' && tab[i].sexe != 'm' && tab[i].sexe != 'F' && tab[i].sexe != 'f'){
                 printf("Erreur : vous devez entrer M ou F uniquement.\n");
              }
            } while (tab[i].sexe != 'M' && tab[i].sexe != 'm' && tab[i].sexe != 'F' && tab[i].sexe != 'f');

            printf("Departement : ");
            scanf("%s", tab[i].departement);

            printf("Filiere : ");
            scanf("%s", tab[i].filiere);

            printf("Region d'origine : ");
            scanf("%s", tab[i].region_origine);

            trouve = 1;
        }
    }

    if (!trouve)
    {
        printf("\nEtudiant non trouve.\n");
    }
}

/* ========= SUPPRESSION ========= */

void supprimer_etudiant(Gestion_des_Etudians tab[], int *n)
{

    char matricule[10];
    int i, j;
    int trouve = 0;

    printf("Entrez le matricule de l'etudiant a supprimer : ");
    scanf("%s", matricule);

    for (i = 0; i < *n; i++)
    {
        if (strcmp(tab[i].matricule, matricule) == 0)
        {
            for (j = i; j < *n - 1; j++)
            {
                tab[j] = tab[j + 1];
            }
            (*n)--;
            trouve = 1;
            printf("\nEtudiant supprime avec succes.\n");
            break;
        }
    }

    if (!trouve)
    {
        printf("\nEtudiant non trouve.\n");
    }
    
}

/* ========= AFFICHAGE ========= */

void afficher_etudiants(Gestion_des_Etudians tab[], int n)
{
    int i;

    if (n == 0)
    {
        printf("\nAucun etudiant enregistre.\n");
        return;
    }

    printf("\n========== LISTE DES ETUDIANTS ==========\n");

    for (i = 0; i < n; i++)
    {
        printf("\nEtudiant %d\n", i + 1);
        printf("Matricule        : %s\n", tab[i].matricule);
        printf("Nom              : %s\n", tab[i].nom);
        printf("Prenom           : %s\n", tab[i].prenom);
        printf("Date de naissance: %02d/%02d/%04d\n",
               tab[i].date_naissance.jour,
               tab[i].date_naissance.mois,
               tab[i].date_naissance.annee);
        printf("Sexe             : %c\n", tab[i].sexe);
        printf("Departement      : %s\n", tab[i].departement);
        printf("Filiere          : %s\n", tab[i].filiere);
        printf("Region d'origine : %s\n", tab[i].region_origine);
    }

    printf("\n========================================\n");
}


/* ========= AGE ========= */

int calculer_age(Gestion_des_Etudians e)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int age = (tm.tm_year + 1900) - e.date_naissance.annee;
   return age;
    }
