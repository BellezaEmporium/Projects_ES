# -*- coding: utf-8 -*-
import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print "Socket OK"
print "Quel port souhaitez vous utiliser"
p = input()
s.bind(('', p))
print "Le socket est en lien avec ce port-ci %s" % (p)
s.listen(5)
print "Le socket regarde la connexion..."
c, addr = s.accept()
while True:
    print 'Sire je pense avoir vu une personne a cette adresse', addr
    c.send('Vous faites partie des notres sur ce serveur')
    msgServeur = raw_input("Vous> ")
    c.send(msgServeur)
    msgClient = c.recv(1024)
    print msgClient
    if msgServeur.upper() == "FIN" or msgServeur == "" or msgClient.upper() == "FIN" or msgClient == "":
       s.close()
       break
