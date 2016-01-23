#!/usr/bin/python
import socket
import sys


sckt = socket.socket()
host = socket.gethostname()
port = sys.argv[1]
msg = sys.argv[2]

try:
    sckt.bind((host, int(port)))
except IOError:
    print("Can't create a socket server!")
sckt.listen(5)
while True:
   c, addr = sckt.accept()    
   print ('Got connection from', addr)
   c.send(bytes(msg, 'UTF-8'))
   c.close()