#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double racine_nieme(int A, int k, int n)
{
    double valeur_plus = 1;
    while(k--)
        valeur_plus = 1.0/n * ((k*(n - 1.0)) + A / pow(k, (n - 1.0)));
    return n;
}

int main()
{
    int k, n, A;
    double operation;
    printf("Veuillez entrer la valeur de A : \n");
    scanf("%d", &A);
    printf("Veuillez entrer la valeur de k : \n");
    scanf("%d", &k);
    printf("Veuillez entrer l'exposant n : \n");
    scanf("%d", &n);
    operation=racine_nieme(A, k, n);
    printf("%lf", operation);
    return 0;
}
