#include <stdio.h>
#include <stdlib.h>

#include "liste_clients.h"

Client* lc_creer(int sock)
{
    Client* client;

    if ((client = malloc(sizeof(Client))) == NULL)
	  return NULL;

    client->sock = sock;
    client->precedent = client->suivant = NULL;

    return client;
}

Client* lc_ajouter_en_tete(Clients* liste, int sock)
{
    Client* client;

    if ((client = lc_creer(sock)) == NULL)
	   return NULL;

    if (*liste == NULL)
	   *liste = client;
    else
    {
	     client->suivant = *liste;
	     client->suivant->precedent = client;
	     *liste = client;
    }

    return client;
}

Client* lc_extraire(Client* client)
{
    if (client == NULL)
	return NULL;

    if (client->suivant != NULL)
	   client->suivant->precedent = client->precedent;
     client->suivant = NULL;
    if (client->precedent != NULL)
	   client->precedent->suivant = client->suivant;
     client->precedent = NULL;

    return client;
}

void lc_supprimer(Client* client)
{
    if (client != NULL)
	free(client);
}

void lc_supprimer_tous(Clients* liste)
{
    Client* tmp;

    if (*liste == NULL)
	return;

    while (*liste != NULL)
    {
	     tmp = *liste;
	     *liste = (*liste)->suivant;
	     free(tmp);
    }
}

int lc_maximum_socket(Clients liste)
{
    int max;

    if (liste == NULL)
	   return -1;

    max = liste->sock;
    while (liste != NULL)
    {
	     if (liste->sock > max)
	      max = liste->sock;
	      liste = liste->suivant;
    }
    return max;
}

void lc_ecrire(Clients liste)
{
    if (liste == NULL)
	   printf("Liste vide !\n");

    while (liste != NULL)
    {
	     printf("%d\n", liste->sock);
	     liste = liste->suivant;
    }
}
