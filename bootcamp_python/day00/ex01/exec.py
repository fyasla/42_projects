import sys

def joinArgs(tab):
	return(" ".join(tab[1:]))

def revAlpha(str):
	rev=str[::-1]
	revAl=""
	for i in range (len(rev)):
		if (rev[i] != rev[i].upper()):
			revAl+=rev[i].upper()
		else :
			revAl+=rev[i].lower()
	return (revAl)

print (revAlpha(joinArgs(sys.argv)))
