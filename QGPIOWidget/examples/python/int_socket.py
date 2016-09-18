import socket
import os, os.path
import struct

print "Connecting..."
if os.path.exists( "/tmp/robot:IntChannel0" ):
	client = socket.socket( socket.AF_UNIX)
	client.connect( "/tmp/robot:IntChannel0" )
	print "Ready."
	print "Ctrl-C to quit."
	print "Sending 'DONE' shuts down the server and quits."
	while True:
		try:
			x = raw_input( "> " )
			if "" != x:
				print "SEND:", x
				#client.send(''.join([chr((int(x)>>(8*i))&0xff) for i in range(0,4)]))
				client.send(str(bytearray(struct.pack("i", int(x)))))
				# client.send(x)
				if "DONE" == x:
					print "Shutting down."
					break
		except KeyboardInterrupt, k:
			print "Shutting down."
			break
	client.close()
else:
	print "Couldn't Connect!"
print "Done"

