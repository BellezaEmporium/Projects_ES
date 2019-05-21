// DEFINITION DES PERSONNES - Prosit 1.8
// Code original par Kao.

#ifndef PERSONNES_H
#define PERSONNES_H

typedef struct Personnes personnes;
struct Personnes{
       int distance;
       char prenom[30];
       char nom[30];
       int Departement;
};

#endif // PERSONNES_H