#include <stdio.h>
#include <stdlib.h>
#include "../headers/parametres.h"
#include "../headers/algosutilises.h"
#include "../headers/personnes.h"
int main(int argc, char **argv) {

    personnes *pers;
    FILE *PersonnesInfos = NULL;
    FILE *PersonnesSortie = NULL;

    if(argc < 3)
    {
        printf("Trop peu d'arguments, vous devez entrer dans l'ordre le fichier d'entrées, et le nom du fichier de sortie");
        return -1;
    }
    size_t size = 0;

    PersonnesInfos = fopen(argv[1], "r");
    PersonnesSortie = fopen(argv[2], "w+");

    if (PersonnesInfos == NULL || PersonnesSortie == NULL)
        return -1;

    size = getSize(&PersonnesInfos);
    pers = malloc(size*sizeof(personnes));

    if(pers == NULL)
        return -1;

    for (size_t i = 0; i < size; i++) {
        LireInfos(pers + i, PersonnesInfos);
    }

    fclose(PersonnesInfos);

    Fleche(pers, size);

    for (size_t j = 0; j < size; ++j)
        AfficherInfos(pers+j, PersonnesSortie);

    fclose(PersonnesSortie);
    free(pers);
    return 0;
}