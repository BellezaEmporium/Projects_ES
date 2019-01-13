import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print "Socket OK"
port = 6969
print = "Adresse IP de la personne que vous souhaitez joindre"
i = input()
s.connect((i, port))
print s.recv(1024)
s.close()
