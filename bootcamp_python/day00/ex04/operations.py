import sys

def printop(a, b) :
	s, d, p = a + b, a - b, a * b
	if (b == 0) :
		q, r = "ERROR (div by zero)", "ERROR (modulo by zero)"
	else :
		q, r = a / b, a % b
	return("Sum : " + str(s) +
	"\nDifference : " + str(d) +
	"\nProduct : " + str(p) +
	"\nQuotient :" + str(q) +
	"\nRemainder : " + str(r))

def operations() :
	if (len(sys.argv) > 3) :
		return("InputError: too many arguments")
	if (len(sys.argv) != 3) :
		return("Example :\n	python operations.py 10 3")
	try:
		a = int(sys.argv[1])
		b = int(sys.argv[2])
	except ValueError:
		return("InputError : only numbers")
	return(printop(a, b))

print(operations())