#include <stdio.h>
#include <stdlib.h>

double racine(double square) // Racine carrée.
{
    double root=square/3;
    int i;
    if (square <= 0) return 0;
    for (i=0; i<32; i++)
        root = (root + square / root) / 2;
    return root;
}
unsigned int factorielle(unsigned int n) // Factorielle
 {
 	unsigned int retval = 1;
 	for (int i = n; i > 1; --i)
 		retval *= i;
 	return retval;
 }
float leibniz(float n) // Formule de Leibniz
{
    double pi=1.0;
    int i;
    int N;
    for (i=3, N=2*n+1; i<=N; i+=2)
        pi += ((i&2) ? -1.0 : 1.0) / i;
    return 4*pi;
}
int main(int argc, char *argv[ ])
{
    int a,b,opsimple,opscientifique,choixdep,opcarree,opleibniz,opfactorielle;
    int continuer = 1;
    do
    {
        printf("---------- Shadix Corporation, 2018 - Calculatrice ----------\n");
        printf("Entrez le premier nombre entier : ");
        scanf("%i", &a);
        printf("Entrez le second nombre entier : ");
        scanf("%i", &b);
        printf("---------- Nombres enregistres ! ----------\n");

        printf("---------- Choisir le type d'operation a effectuer : ----------\n");
        printf("1 - Operations simples\n");
        printf("2 - Operations complexes (scientifiques)\n");
        scanf("%i", &choixdep);

        switch (choixdep)
        {
            case 1:
                printf("---------- Vous avez choisi de faire des operations simples. Choisissez le type d'operations : ----------\n");
                printf("1 - Addition\n");
                printf("2 - Soustraction\n");
                printf("3 - Multiplication\n");
                printf("4 - Division\n");
                scanf("%i", &opsimple);
            switch (opsimple)
            {
                case 1:
                    printf("Le resultat de l'addition est : %d\n", a+b);
                break;
                case 2:
                    printf("Le resultat de la soustraction est : %d\n", a-b);
                break;
                case 3:
                    printf("Le resultat de la multiplication est : %d\n", a*b);
                break;
                case 4:
                    printf("Le resultat de la division est : %d\n", a/b);
                break;
                default :
                    printf("Desole, je n'ai pas compris votre choix d'operation\n");
                break;
            }break;
                case 2:
                    printf("---------- Vous avez choisi de faire des operations scientifiques. Choisissez le type d'operations : ----------\n");
                    printf("5 - Racine carree\n");
                    printf("6 - Formule de Leibniz\n");
                    printf("7 - Factorielle\n");
                    scanf("%i", &opscientifique);
                switch (opscientifique)
                {
                    case 5:
                        printf("---------- Vous avez choisi le calcul d'une racine carree. Choisissez le type d'operations : ----------\n");
                        printf("10 - Addition\n");
                        printf("11 - Soustraction\n");
                        printf("12 - Multiplication\n");
                        printf("13 - Division\n");
                        scanf("%i", &opcarree);
                    switch (opcarree)
                    {
                        case 10:
                            printf("Le resultat de l'addition de racine carree est : %f\n", racine(a)+racine(b));
                        break;
                        case 11:
                            printf("Le resultat de la soustraction de racine carree est : %f\n", racine(a)-racine(b));
                        break;
                        case 12:
                            printf("Le resultat de la multiplication de racine carree est : %f\n", racine(a)*racine(b));
                        break;
                        case 13:
                            printf("Le resultat de la division de racine carree est : %f\n", racine(a)/racine(b));
                        break;
                        default :
                            printf("Desole, je n'ai pas compris votre choix d'operation\n");
                        break;
                    }break;
                    case 6:
                        printf("---------- Vous avez choisi le calcul de derivee de Pi avec la formule de Leibniz. Choisissez le type d'operations : ----------\n");
                        printf("20 - Addition\n");
                        printf("21 - Soustraction\n");
                        printf("22 - Multiplication\n");
                        printf("23 - Division\n");
                        scanf("%i", &opleibniz);
                    switch (opleibniz)
                    {
                        case 20:
                            printf("Le resultat de l'addition de l'equation de Pi (avec formule de Leibniz) est : %f\n", leibniz(a)+leibniz(b));
                        break;
                        case 21:
                            printf("Le resultat de la soustraction de l'equation de Pi (avec formule de Leibniz) est: %f\n", leibniz(a)-leibniz(b));
                        break;
                        case 22:
                            printf("Le resultat de la multiplication de l'equation de Pi (avec formule de Leibniz) est : %f\n", leibniz(a)*leibniz(b));
                        break;
                        case 23:
                            printf("Le resultat de la division de l'equation de Pi (avec formule de Leibniz) est: %f\n", leibniz(a)/leibniz(b));
                        default :
                            printf("Desole, je n'ai pas compris votre choix d'operation\n");
                        break;
                    }break;
                    case 7:
                        printf("---------- Vous avez choisi le calcul de factorielle. Choisissez le type d'operations : ----------\n");
                        printf("20 - Addition\n");
                        printf("21 - Soustraction\n");
                        printf("22 - Multiplication\n");
                        printf("23 - Division\n");
                        scanf("%i", &opfactorielle);
                    switch (opfactorielle)
                    {
                        case 30:
                            printf("Le resultat de l'addition des deux factorielles est : %u\n", factorielle(a)+factorielle(b));
                        break;
                        case 31:
                            printf("Le resultat de la soustraction des deux factorielles est : %u\n", factorielle(a)-factorielle(b));
                        break;
                        case 32:
                            printf("Le resultat de la multiplication des deux factorielles est : %u\n", factorielle(a)*factorielle(b));
                        break;
                        case 33:
                            printf("Le resultat de la division des deux factorielles est : %u\n", factorielle(a)/factorielle(b));
                        break;
                        default :
                            printf("Desole, je n'ai pas compris votre choix d'operation\n");
                        break;
                    }break;
                }
        }
        printf("Continuer=1 ;Quitter=0 :");
        scanf("%d", &continuer);
    }
    while (continuer) ;
    system("PAUSE");
    return 0;
}
