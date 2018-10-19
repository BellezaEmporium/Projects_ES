// DEFINITION DES PARAMETRES UTILISES - Prosit 1.8
// Code original par Kao.

#ifndef PARAMETRES_H
#define PARAMETRES_H

#include "personnes.h"
#include <stdio.h>
#include <stdbool.h>

void LireInfos(personnes *Personnes, FILE *PersonnesInfos);
size_t getSize(FILE **PersonnesInfos);
void AfficherInfos(personnes *Personnes, FILE *PersonnesSortie);
void pifpouf(personnes *a, personnes *b);
void graffiti(personnes a[], personnes b[]);
int ComparerPersonnes(const personnes *a, const personnes *b);

#endif // PARAMETRES_H