import random

def guess():
	inp = 0
	cpt = 0
	to_guess=random.randint(1, 99)
	print("c'est plus facile : " + str(to_guess))

	print("This is an interactive guessing game!\nYou have to enter a number between 1 and 99 to find out the secret number.\nType 'exit' to end the game.\nGood luck!")
	while (inp != to_guess):
		cpt += 1
		inp = input("What's your guess between 1 and 99?")
		if (str(inp).lower() == "exit"):
			break
		try:
			inp = int(inp)
		except ValueError:
			print("Enter an integer")
		if inp < to_guess:
			print("Too low !")
		elif inp > to_guess:
			print("Too high !")
		elif inp == to_guess:
			print("Congratulations, you've got it!")
			print("You won in " + cpt + " attempts!")

guess()