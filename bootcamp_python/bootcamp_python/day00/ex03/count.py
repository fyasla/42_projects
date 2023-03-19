import string
import sys

def text_analyzer(text = str(raw_input("What is the text to analyse?\n"))):
	"""
	This function counts the number of upper characters, lower characters,
    punctuation and spaces in a given text.
	"""
	c,u,l,p,s = len(text),0,0,0,0
	for i in range(len(text)):
		if text[i].isupper():
			u+=1
		if text[i].islower():
			l+=1
		if text[i] in string.punctuation:
			p+=1
		if text[i].isspace():
			s+=1
	print("The text contains " + str(c) + " characters:\n"
		"- " + str(u) + " upper letters\n"
	+ "- " + str(l) + " lower letters\n"
	+ "- " + str(p) + " punctuation marks\n"
	+ "- " + str(s) + " spaces")

print(text_analyzer.__doc__)
text_analyzer()