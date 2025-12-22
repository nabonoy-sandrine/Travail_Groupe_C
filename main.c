// contient la fonction principale et gère le menu ainsi que les appels aux fonctions de gestion des étudiants.

#include "etudiant.h"
#include <string.h>

int main()
{
    Gestion_des_Etudians etudiants[MAX];
    int n, choix, pos;
    char mat[15];

    printf("Entrer le nombre initial d'etudiants : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        enregistrer_etudiant(&etudiants[i]);

    do
    {
        menu_beau();
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouter_etudiant(etudiants, &n);
            break;

        case 2:
            modifier_etudiant(etudiants, n);
            break;

        case 3:
            trier_par_nom(etudiants, n);
            printf("Matricule à rechercher : ");
            scanf("%s", mat);
            pos = rechercher_etudiant(etudiants, n, mat);
            if (pos != -1)
                printf(" Étudiant trouvé : %s %s\n",
                       etudiants[pos].nom,
                       etudiants[pos].prenom);
            else
                printf(" Étudiant non trouvé\n");
            break;

        case 4:
            supprimer_etudiant(etudiants, &n);
            break;

        case 5:
            trier_par_nom(etudiants, n);
            printf(" Tri par nom effectué\n");
            break;

        case 6:
            printf("Matricule : ");
            scanf("%s", mat);
            for (int i = 0; i < n; i++)
                if (strcmp(etudiants[i].matricule, mat) == 0)
                    printf(" Âge : %d ans\n", calculer_age(etudiants[i]));
            break;

        case 7:
            trier_par_filiere(etudiants, n);
            printf(" Tri par filière effectué\n");
            break;

        case 8:
            afficher_etudiants(etudiants, n);
            break;
        }
    } while (choix != 0);

    return 0;
}
