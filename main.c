// contient la fonction principale et gère le menu ainsi que les appels aux fonctions de gestion des étudiants.

#include "etudiant.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    Gestion_des_Etudians etudiants[MAX];
    int n = 0;
    int choix;

    do
    {
        menu();
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                ajouter_etudiant(etudiants, &n);
                break;

            case 2:
                /* Modifier un étudiant */
                break;

            case 3:
                /* Rechercher un étudiant (dichotomie) */
                break;

            case 4:
                /* Supprimer un étudiant */
                break;

            case 5:
                if (n < 2){
                  printf("Impossible de trier : moins de 2 etudiants.\n");
                }
                else{
                  trier_par_nom(etudiants, n);
                  printf("Tri par nom effectue.\n");
                  afficher_etudiants(etudiants, n);
              }
            break;
            case 6:
                char mat[20];
                int pos;

                printf("Entrer le matricule : ");
                scanf("%s", mat);

                pos = rechercher_etudiant(etudiants, n, mat);

                if (pos == -1)
                  printf("Etudiant non trouve.\n");
               else
                  printf("Age : %d ans\n", calculer_age(etudiants[pos]));

               break;
            case 7:
               trier_par_filiere(etudiants, n);
               printf("Tri par filiere effectue.\n");
               break;

            case 8:
                 afficher_etudiants(etudiants, n);
                 break;

            case 0:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide !\n");
        }

    } while (choix != 0);

    return 0;
}
