Python Program to Count Vowels in a String
# Python Program to Count Vowels in a String

str1 = input("Please Enter Your Own String : ")
vowels = 0
 
for i in str1:
    if(i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u' or i == 'A'
       or i == 'E' or i == 'I' or i == 'O' or i == 'U'):
        vowels = vowels + 1
 
print("Total Number of Vowels in this String = ", vowels)
  Python Program to Count Vowels Example 2
  # Python Program to Count Vowels in a String

str1 = input("Please Enter Your Own String : ")

vowels = 0
str1.lower()

for i in str1:
    if(i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u'):
        vowels = vowels + 1
 
print("Total Number of Vowels in this String = ", vowels)
Python Count Vowels in a String output

Please Enter Your Own String : Hello World
Total Number of Vowels in this String =  3
>>> 
Please Enter Your Own String : Tutorial Gateway
Total Number of Vowels in this String =  7
Program to Count Total Number of Vowels in a String Example 3
This python program uses ASCII values to count vowels. I suggest you to refer ASCII table article to understand ASCII values.

# Python Program to Count Vowels in a String

str1 = input("Please Enter Your Own String : ")
vowels = 0

for i in str1:
    if(ord(i) == 65 or ord(i) == 69 or ord(i) == 73
       or ord(i) == 79 or ord(i) == 85
       or ord(i) == 97 or ord(i) == 101 or ord(i) == 105
       or ord(i) == 111 or ord(i) == 117):
        vowels = vowels + 1
 
print("Total Number of Vowels in this String = ", vowels)
Python Count Vowels in a String output


Please Enter Your Own String : Python Tutorial
Total Number of Vowels in this String =  5
>>> 
Please Enter Your Own String : Tutorial Gateway
Total Number of Vowels in this String =  7
