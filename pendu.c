#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "pendu.h"


int main (int argc, char* argv[])
{
    int i , j;
    char motSecret[] = "MARRON";
    char motDecouvert[] = "******";
    char caractereRecup = 0;

    printf("Bienvenue dans le jeu du pendu\n");

    for (i = 0 ; i < 10 ; i++) // compteur pour le nombre de partie
    {
        printf("Il vous reste %d coups\n", 10-i);
        printf("Quel est le mot secret ? %s\n",motDecouvert);
        caractereRecup = recupCaract();
        //ici on recupère le caractere via une fonction qui va en plus vider le buffer et passer le caracter en majuscule

        for (j = 0 ; motSecret[j] != '\0' ; j++) 
        // compteur pour passer en revue les caractere du mot Secret et le comparé avec le caractere saisi
        {
            if (motSecret[j] == caractereRecup)
            // Si la caractere saisi est dans le motsecret alors on l'affiche 
            {
                motDecouvert[j] = caractereRecup;
            }
        }
        printf("%s\n",motDecouvert);

        if (verification(motDecouvert))
        //cette fonction regarde s'il reste des caractere non trouvé '*' dans le mot et retourne 1 si non
        {
            printf("Vous avez gagné !\n");
            exit(0);
        }
    }

    
    return 0;
}