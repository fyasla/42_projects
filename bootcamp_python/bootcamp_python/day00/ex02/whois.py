import sys

def whois():
	if (len(sys.argv) != 2):
		return("ERROR")
	try :
		n = int(sys.argv[1])
	except ValueError :
		return("ERROR")
	if (n == 0):
		return ("I'm Zero.")
	elif (n % 2 == 0):
		return ("I'm Even.")
	else:
		return ("I'm Odd.")

print(whois())