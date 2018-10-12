#include <stdio.h>
#include <stdlib.h>

int main()
{
    double nombre_un = 0, nombre_deux = 0, resultat = 0;
    int restart = 0, operation = 0;
    do
    {
        printf("Entre le premier nombre :\n");
        scanf("%lf", &nombre_un);
        printf("Entre le deuxieme nombre :\n");
        scanf("%lf", &nombre_deux);
        printf("Choisis une operation :\n1.Addition\n2.Soustraction\n3.Multiplication\n4.Division\n");
        scanf("%d", &operation);
                switch (operation)
        {
            case 1:
                resultat = nombre_un + nombre_deux;
                break;
            case 2:
                resultat = nombre_un - nombre_deux;
                break;
            case 3:
                resultat = nombre_un * nombre_deux;
                break;
            case 4:
                if (nombre_deux == 0)
                {
                    printf("Il est impossible de faire une division avec 0, cono.");
                    return 1;
                }
                resultat = nombre_un / nombre_deux;
                break;
        }
        printf("Le resultat est %f\nRefaire un calcul ?\n0.Oui\n1.Non\n", resultat);
        scanf("%d", &restart);
    } while (restart != 1);
    return 0;
}