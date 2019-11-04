import sys

languages = {
    'Python': 'Guido van Rossum',
    'Ruby': 'Yukihiro Matsumoto',
    'PHP': 'Rasmus Lerdorf',
    }

def printdico(dic):
	for key in dic:
		sys.stdout.write(key + " was created by ")
		sys.stdout.write(dic[key] + "\n")

printdico(languages)