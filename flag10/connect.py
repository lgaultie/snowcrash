# import socket               # Import socket module

# s = socket.socket()         # Create a socket object
# host = socket.gethostname() # Get local machine name
# port = 12345                # Reserve a port for your service.
# s.bind((host, port))        # Bind to the port

# s.listen(5)                 # Now wait for client connection.
# while True:
#    c, addr = s.accept()     # Establish connection with client.
#    data = c.recv(1024)
#    print data
#    print 'Got connection from', addr
#    c.send('Thank you for connecting')
#    c.close()                # Close the connection


import socket	#for sockets
import sys	#for exit

#create an INET, STREAMing socket
try:
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
except socket.error:
	print 'Failed to create socket'
	sys.exit()
print 'Socket Created'

host = '10.11.200.134'
port = 6969

try:
	remote_ip = socket.gethostbyname(host)
except socket.gaierror:
	#could not resolve
	print 'Hostname could not be resolved. Exiting'
	sys.exit()

#Connect to remote server
s.connect((remote_ip, port))
print 'Socket Connected to ' + host + ' on ip ' + remote_ip

# https://docs.python.org/3/howto/sockets.html

#Send some data to remote server
message = "GET / HTTP/1.1\r\n\r\n"
try :
	#Set the whole string
	s.sendall(message)
except socket.error:
	#Send failed
	print 'Send failed'
	sys.exit()
print 'Message send successfully'

#Now receive data
reply = s.recv(4096)
print reply