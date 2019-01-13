import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print "Socket OK"
port = 62541
s.connect(('192.168.175.128', port))
msgServeur = s.recv(1024)
while 1:
       print "Administrateur>", msgServeur
       if msgServeur.upper() == "FIN" or msgServeur =="":
        break
       msgClient = raw_input("Vous> ")
       s.send(msgClient)
       msgServeur = s.recv(1024)

s.close()
