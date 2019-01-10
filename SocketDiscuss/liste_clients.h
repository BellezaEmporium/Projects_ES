#ifndef LISTE_CLIENTS_H
#define LISTE_CLIENTS_H

typedef struct client
{
    int sock;
    struct client* suivant;
    struct client* precedent;
} Client, *Clients;

Client* lc_creer(int sock);

Client* lc_ajouter_en_tete(Clients* liste, int sock);

Client* lc_extraire(Client* client);

void lc_supprimer(Client* client);

void lc_supprimer_tous(Clients* liste);

int lc_maximum_socket(Clients liste);

void lc_ecrire(Clients liste);

#endif
