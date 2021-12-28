"""Anagram is a situation in which every charachter of a string1 should appears in string2"""
def AreAnagram(str1, str2):
    if len(str1)!=len(str2):
        print("String do not form Anagram")
    str1 = sorted(str1)
    str2 = sorted(str2)
    if (str1==str2):
        print("String form a Anagram")

# driver Code
str1 = input()
str2 = input() 
print("String 1 : ", str1) 
print("string 2 : ", str2)
AreAnagram(str1,str2)      