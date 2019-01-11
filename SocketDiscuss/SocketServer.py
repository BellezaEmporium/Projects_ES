import socket                 
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)          
print "Socket OK"
port = 6969
s.bind(('', port))      
print "Le socket est en lien avec ce port-ci %s" %(port) 
s.listen(5)      
print "Le socket regarde la connexion..."            
while True: 
   c, addr = s.accept()      
   print 'Sire je pense avoir vu une personne a cette adresse', addr 
   c.send('Vous faites partie des notres sur ce serveur Bienvenue DJIGBO') 
   c.close() 
