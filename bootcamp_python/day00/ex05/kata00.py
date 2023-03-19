
import sys

t = (19,42,21,0, -98465, 56.5)

def printtuple(tup):
	sys.stdout.write("The " + str(len(t)) +" numbers are: " + str(tup[0]))
	for i in range (1, len(tup)):
		sys.stdout.write(", " + str(tup[i]))

printtuple(t)