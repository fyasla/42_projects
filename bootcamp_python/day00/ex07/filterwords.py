import sys
import string

def split(str):
	cpy=""
	for i in range (len(str)):
		if str[i] in string.punctuation or str[i] in string.whitespace :
			cpy+= ' '
		else:
			cpy+= str[i]
	return(cpy.split(' '))

def filterwords():
	if len(sys.argv) != 3:
		return("ERROR : 2 arguments needed")
	try:
		stri = str(sys.argv[1])
		n = int(sys.argv[2])
	except ValueError:
		return("ERROR : 1 string and 1 int are needed")
	if stri.isdigit():
		return("ERROR")
	spl = split (stri)
	filtred=[]
	for i in range(len(spl)):
		if (len(spl[i]) > n):
			filtred.append(spl[i])
	return(filtred)

print(filterwords())