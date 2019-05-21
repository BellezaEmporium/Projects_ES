#include <stdio.h>
#include <stdlib.h>

float leibniz(float n) // Formule de Leibniz
{
    double pi=1.0;
    int i;
    int N;
    for (i=3, N=2*n+1; i<=N; i+=2)
        pi += ((i&2) ? -1.0 : 1.0) / i;
    return 4*pi;
}

int main(void) {
    printf("Pi: %f\n", leibniz(120));
    return 0;
}