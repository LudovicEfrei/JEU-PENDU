#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h> 
#include "pendu.h"


int main (int argc, char* argv[])
{
    int nombreMots = compteurMot();
    int i , j;
    char caractereRecup = 0;
    int numeroMot = tirageMot(nombreMots);
    int nombreLettre = tailleMot(numeroMot);

    //printf("%d %d\n",numeroMot, nombreLettre);

    char* motSecret = NULL;
    motSecret=malloc(nombreLettre * sizeof(char));//on crée un tableau de la taille du mot tiré au hasard
    if (motSecret==NULL)
    {
        exit(0);
    }

    recupMot(numeroMot,nombreLettre,motSecret);
    //affiche(motSecret,nombreLettre);

    char* motMystere = NULL;
    motMystere=malloc(nombreLettre * sizeof(char));
    if (motMystere==NULL)
    {
        exit(0);
    }

    creerMotMystere(nombreLettre,motMystere);


    printf("Bienvenue dans le jeu du pendu\n");

    for (i = 0 ; i < 10 ; i++) // compteur pour le nombre de partie
    {
        printf("Il vous reste %d coups\n", 10-i);
        printf("Quel est le mot secret ? %s\n",motMystere);
        caractereRecup = recupCaract();
        //ici on recupère le caractere via une fonction qui va en plus vider le buffer et passer le caracter en majuscule

        for (j = 0 ; motSecret[j] != '\0' ; j++) 
        // compteur pour passer en revue les caractere du mot Secret et le comparé avec le caractere saisi
        {
            if (motSecret[j] == caractereRecup)
            // Si la caractere saisi est dans le motsecret alors on l'affiche 
            {
                motMystere[j] = caractereRecup;
                i--;
            }
        }
        printf("%s\n",motMystere);

        if (verification(motMystere))
        //cette fonction regarde s'il reste des caractere non trouvé '*' dans le mot et retourne 1 si non
        {
            printf("Vous avez gagné !\n");
            exit(0);
        }
    }

    free(motSecret);
    free(motMystere);
    return 0;
}
