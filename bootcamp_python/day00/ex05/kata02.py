t = (3,30,2019,9,25)

def printhour(smhaMd):
	print(str(t[3] / 10) + str(t[3] % 10) + '/'
	+ str(t[4] / 10) + str(t[4] % 10) + '/'
	+ str(t[2]) + ' '
	+str(t[0] / 10) + str(t[0] % 10) + ':'
	+ str(t[1] / 10) + str(t[1] % 10))

printhour(t)