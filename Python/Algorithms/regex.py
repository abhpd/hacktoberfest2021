# Python program to accept string starting with a vowel

# import re module

# re module provides support
# for regular expressions
import re

# Make a regular expression
# to accept string starting with vowel
regex = '^[aeiouAEIOU][A-Za-z0-9_]*'
	
# Define a function for
# accepting string start with vowel
def check(string):

	# pass the regular expression
	# and the string in search() method
	if(re.search(regex, string)):
		print("Valid")
		
	else:
		print("Invalid")
	

# Driver Code
if __name__ == '__main__' :
	
	# Enter the string
	string = "ankit"
	
	# calling run function
	check(string)

	string = "geeks"
	check(string)

	string = "sandeep"
	check(string)
