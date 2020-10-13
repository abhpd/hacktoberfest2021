import random
import string

from os import system, name

def clear():
    if name == 'nt': 
        system('cls') 
  
    # for mac and linux 
    else: 
        system('clear') 


print('Please choose the type of password you want to generate:')
print("1. 6 character password")
print("2. 8 character password")
print("3. 12 character password")

length_choice = input()

if length_choice == "1":
    clear()
    print("1. Simple")
    print("2. Complex")
    print("3. Sophisticated")

    type_choice = input()

    if type_choice == "1":
        clear()
        letters = string.ascii_lowercase
        result_str = ''.join(random.choice(letters) for i in range(6))
        print(result_str)
    elif type_choice == "2":
        clear()
        letters = string.ascii_letters + string.digits
        result_str = ''.join(random.choice(letters) for i in range(6))
        print(result_str)
    elif type_choice == "3":
        clear()
        letters = string.ascii_letters + string.digits + string.punctuation
        result_str = ''.join(random.choice(letters) for i in range(6))
        print(result_str)

elif length_choice =="2":
    clear()
    print("1. Simple")
    print("2. Complex")
    print("3. Sophisticated")

    type_choice = input()

    if type_choice == "1":
        clear()
        letters = string.ascii_lowercase
        result_str = ''.join(random.choice(letters) for i in range(8))
        print(result_str)
    elif type_choice == "2":
        clear()
        letters = string.ascii_letters + string.digits
        result_str = ''.join(random.choice(letters) for i in range(8))
        print(result_str)
    elif type_choice == "3":
        clear()
        letters = string.ascii_letters + string.digits + string.punctuation
        result_str = ''.join(random.choice(letters) for i in range(8))
        print(result_str)

elif length_choice =="3":
    clear()
    print("1. Simple")
    print("2. Complex")
    print("3. Sophisticated")

    type_choice = input()

    if type_choice == "1":
        clear()
        letters = string.ascii_lowercase
        result_str = ''.join(random.choice(letters) for i in range(12))
        print(result_str)
    elif type_choice == "2":
        clear()
        letters = string.ascii_letters + string.digits
        result_str = ''.join(random.choice(letters) for i in range(12))
        print(result_str)
    elif type_choice == "3":
        clear()
        letters = string.ascii_letters + string.digits + string.punctuation
        result_str = ''.join(random.choice(letters) for i in range(12))
        print(result_str)