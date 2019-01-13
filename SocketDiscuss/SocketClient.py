# -*- coding: cp1252 -*-
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print "Socket OK"
p = input("Port du serveur :\n")
i = raw_input("Adresse IP du serveur :\n")
s.connect((i, p))
msgServeur = s.recv(1024)
while 1:
    print "Administrateur>", msgServeur
    if msgServeur.upper() == "FIN" or msgServeur == "":
        break
    msgClient = raw_input("Vous> ")
    s.send(msgClient)
    msgServeur = s.recv(1024)

s.close()
