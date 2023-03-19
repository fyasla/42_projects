cookbook = {"sandwich": {"ingredients": '["ham", "bread", "cheese", "tomatoes"]', "meal": "lunch", "prep_time": 10},
"cake": {"ingredients": '["flour", "sugar", "eggs"]', "meal": "dessert", "prep_time": 60},
"salad": {"ingredients": '["avocado", "arugula", "tomatoes", "spinach"]', "meal": "lunch", "prep_time": 15}
}

def printRecipe(recipe):
	print("Recipe for cake:")
	print("Ingredients list:" + cookbook[recipe]["ingredients"])
	print("To be eaten for " + cookbook[recipe]["meal"] + '.')
	print("Takes " + str(cookbook[recipe]["prep_time"]) + ' minutes of cooking.\n')

def delRecipe(recipe):
	del cookbook[recipe]

def addRecipe(name, ingredients, meal, prep_time):
	cookbook[name] = {}
	cookbook[name]["ingredients"] = ingredients 
	cookbook[name]["meal"] = meal
	cookbook[name]["prep_time"] = prep_time

def printAllRecipesName():
	print("Recipes :")
	for name in cookbook :
		print name

def myCookbook():
	inp = 0
	while inp != 5 :
		inp = input ("Please select an option by typing the corresponding number:\n1: Add a recipe\n2: Delete a recipe\n3: Print a recipe\n4: Print the cookbook\n5: Quit\n")
		if inp == 1:
			name = input("Name of recipe: ")
			meal = input("Type of meal: ")
			ingredients = input("List of ingredients : ")
			prep_time = input("Preparation time: ")
			addRecipe(name, ingredients, meal, prep_time)
		if inp == 2:
			name = input("Name of recipe: ")
			delRecipe(name)
		if inp == 3:
			name = input("Name of recipe: ")
			printRecipe(name)
		if inp == 4:
			printAllRecipesName()


#printAllRecipesName(cookbook)
#delRecipe("sandwich")
#printAllRecipesName(cookbook)
#addRecipe("sandwich", '["ham", "bread", "cheese", "tomatoes"]', "lunch", 10)
#printRecipe("sandwich")

myCookbook()