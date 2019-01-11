#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/times.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "clients_socket.h"
#include "liste_clients.h"

int socket_creer(void)
{
    int sock;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	   return -1;

    return sock;
}

int socket_configurer(int sock, int port)
{
    struct sockaddr_in serveur;
    size_t taille = sizeof(struct sockaddr_in);

    serveur.sin_family = AF_INET;
    serveur.sin_port = htons(port);
    serveur.sin_addr.s_addr = INADDR_ANY;
    bzero(&(serveur.sin_zero), 8);

    if (bind(sock, (struct sockaddr*) &serveur, taille) == -1)
	   return -1;

    return 1;
}

int socket_ecouter(int sock, int clients)
{
    if (listen(sock, clients) == -1)
	   return -1;

    return 1;
}

void fdset_initialiser(fd_set* rfds, int sock, Clients clients)
{
    FD_ZERO(rfds);

    FD_SET(sock, rfds);
    while (clients != NULL)
    {
	     FD_SET(clients->sock, rfds);
	     clients = clients->suivant;
    }
}

int client_ajouter(Clients* clients, int sock)
{
    int sock_client;
    struct sockaddr_in client;
    socklen_t taille_client = sizeof(struct sockaddr);

    sock_client = accept(sock, (struct sockaddr*) &client, &taille_client);
    if (sock_client == -1)
	   return -1;

    lc_ajouter_en_tete(clients, sock_client);

    return sock_client;
}

void client_deconnecter(Client* client)
{
    if (client == NULL)
	   return;

    close(client->sock);
    lc_supprimer(lc_extraire(client));
    printf("Déconnexion réussie !\n");
}

void traiter(Clients* liste, Client* client, int sock, char* tampon, int taille)
{
    tampon[taille - 1] = '\0';

    if (strcmp("/quitter", tampon) == 0)
    {
	     client_deconnecter(client);
    }
    else
    {
	client = *liste;
	while (client != NULL)
	{
	    send(client->sock, tampon, strlen(tampon), 0);
	    client = client->suivant;
	}
    }
}

int application(int sock)
{
    int continuer = 1;
    int taille;
    int max = sock;
    int erreur;
    Clients clients = NULL;
    Clients index;
    char tampon[TAILLE_TAMPON];
    fd_set rfds;

    while (continuer)
    {
	     fdset_initialiser(&rfds, sock, clients);
	     select(max + 1, &rfds, NULL, NULL, NULL);
	     if (FD_ISSET(sock, &rfds))
	{
	    if ((erreur = client_ajouter(&clients, sock)) == -1)
		    return -1;
	    printf("Connexion réussie\n");
	    max = lc_maximum_socket(clients);
	}
	else
	{
	    index = clients;
	    while (index != NULL)
	    {
		if (FD_ISSET(index->sock, &rfds))
		{
		    if ((taille = recv(index->sock, tampon, TAILLE_TAMPON - 1, 0)) == -1)
			     return -1;
		    traiter(&clients, index, index->sock, tampon, taille);
		    max = lc_maximum_socket(clients);
		}
		index = index->suivant;
	    }
	}
    }
    return 1;
}

int main(void)
{
    int sock;

    if ((sock = socket_creer()) == -1)
	   return -1;

    if (socket_configurer(sock, PORT) == -1)
	   return -1;

    if (socket_ecouter(sock, NB_CLIENTS) == -1)

     return -1;

    application(sock);
    close(sock);

    return 0;
}
