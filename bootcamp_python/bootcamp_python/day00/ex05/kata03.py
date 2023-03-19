import sys

phrase = "The right format"

def print42(str):
	ajust = ""
	if len(str) > 42 :
		sys.stdout.write(str)
	else :
		for i in range (42 - len(str)):
			ajust+='-'
	sys.stdout.write(ajust + str)

print42(phrase)