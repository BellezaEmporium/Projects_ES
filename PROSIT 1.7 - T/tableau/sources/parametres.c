//Paramètres du code

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/personnes.h"

bool LireInfos(personnes *Personnes, FILE *PersonnesInfos) {
    if (PersonnesInfos != NULL) {
        fscanf(PersonnesInfos, "%d %s %s %d", &Personnes->distance, Personnes->nom, Personnes->prenom, &Personnes->Departement);
        return true;
    } else
        return false;
}

void AfficherInfos(personnes *Personnes, FILE *PersonnesSortie) {
    if (PersonnesSortie != NULL) {
        fprintf(PersonnesSortie, "%d %s %s %d\n", Personnes->distance, Personnes->nom, Personnes->prenom, Personnes->Departement);
    }
}

size_t getSize(FILE **PersonnesInfos) {
    size_t size = 0;
    fscanf(*PersonnesInfos, "%llu", &size);
    return size;
}

void pifpouf(personnes *a, personnes *b) {
    personnes temp = *a;
    *a = *b;
    *b = temp;
}
int ComparerPersonnes(const personnes *a, const personnes *b) {
    if ((a->Departement == b->Departement) && (a->distance == b->distance))
        return 0;
    else if (((a->Departement == b->Departement) && (a->distance > b->distance)) ||
             (a->Departement > b->Departement))
        return 1;
    else
        return -1;
}

void graffiti(personnes a[], personnes b[], size_t size){
    for(int i = 0; i < size; i++){
        b[i] = a[i];
    }
}