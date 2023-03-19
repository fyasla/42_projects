t = (0, 4, 132.42222, 10000, 12345.67)

def printkata04(tup):
	print("day_" + str(t[0] / 10) + str(t[0] % 10) + ", " +
	"ex_" + str(t[1] / 10) + str(t[1] % 10) + " : " +
	str(round(t[2], 2)) + ", %.2e"%t[3] + ", %.2e"%t[4])
	
printkata04(t)