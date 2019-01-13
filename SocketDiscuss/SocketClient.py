# -*- coding: cp1252 -*-
import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print "Socket OK"
print "Quel est le port utilisé par le serveur"
p = input()
print "Adresse IP de la personne que vous souhaitez joindre"
i = input()
s.connect((i, p))
msgServeur = s.recv(1024)
while 1:
       print "Administrateur>", msgServeur
       if msgServeur.upper() == "FIN" or msgServeur =="":
        break
       msgClient = raw_input("Vous> ")
       s.send(msgClient)
       msgServeur = s.recv(1024)

s.close()
