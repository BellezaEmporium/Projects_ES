// Flèche, le Heap Sort.

#include "../headers/parametres.h"

void Flechette(personnes Personnes[], size_t size, int i);

void Fleche(personnes Personnes[], size_t size){

    for (int i = (int) size / 2 - 1; i >= 0; i--)
        Flechette(Personnes, size, i);
    for (int i = (int) size - 1; i >= 0; i--) {
        pifpouf(&Personnes[0], &Personnes[i]);
        Flechette(Personnes, i, 0);
    }
}

void Flechette(personnes Personnes[], size_t size, int i) {
    int plus_grand = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && ComparerPersonnes(&Personnes[l], &Personnes[plus_grand]) == 1)
        plus_grand = l;
    if (r < size && ComparerPersonnes(&Personnes[r], &Personnes[plus_grand]) == 1)
        plus_grand = r;

    if (plus_grand != i) {
        pifpouf(&Personnes[i], &Personnes[plus_grand]);
        Flechette(Personnes, size, plus_grand);
    }
}