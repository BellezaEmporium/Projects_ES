#include <stdio.h>
#include <stdlib.h>

double racine_nieme(int A, int k, int n)
{
    double valeur_plus = n;
    while(k--)
        valeur_plus =(1/n((n-1)*k+(A/k*(n-1))));
    return n;
}

int main()
{
    int k, n;
    double A, valeur_plus;
    printf("Veuillez entrer la valeur de A : \n");
    scanf("%lf", &A);
    printf("Veuillez entrer la valeur de k : \n");
    scanf("%d", &k);
    printf("Veuillez entrer l'exposant n : \n");
    scanf("%d", &n);
    valeur_plus=racine_nieme(A, k, n);
    printf("%f", n);
    return 0;
}
