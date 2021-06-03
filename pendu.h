#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char recupCaract ()
{
    char caractere = 0;
    scanf("%c",&caractere);
    caractere = toupper(caractere); // On met en majuscule le caractere saisie par l'utilisateur
    while(getchar() != '\n'); //on vide le buffer

    return caractere; // on renvoit le caractere saisi
}

int verification(char motDecouvert[])
{
    int i;
    for (i=0; motDecouvert[i] != '\0'; i++)
    {
        if (motDecouvert[i]=='*')
            return 0;
    }
    return 1;
}