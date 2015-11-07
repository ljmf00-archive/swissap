#!/usr/bin/python 
import socket
import sys

sckt = socket.socket() 
if sys.argv[1] == '--this':
    host = socket.gethostname()
else:
    host = sys.argv[1]

port = sys.argv[2]
scktlen = sys.argv[3]

try:
    sckt.connect((host, int(port)))
except IOError:
    print("0E")
    exit(1)
else:
    print(sckt.recv(int(scktlen)).decode('UTF-8'))
    sckt.close