import sys
import telnetlib
HOST = "192.168.1.254"
user = "meo"
password = "meo"
port = "23"
print(b"R\n")
telnet = telnetlib.Telnet(HOST,port)
print(b"1\n")
telnet.open(HOST,port)
print(b"2\n")
telnet.read_until(b"Username: ")
print(b"3\n")
telnet.read_all()
print(b"4\n")
telnet.write(user.encode('ascii') + b"\n")
print(b"5\n")
telnet.read_until(b"Password: ")
print(b"6\n")
telnet.write(password.encode('ascii') + b"\n")
print(b"S\n")
telnet.write(b"exit\n")
print(b"E\n")
