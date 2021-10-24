import random
number = random.randint(1,10)
tries = 0
uname = input("Enter your name: ")
uname=uname.strip()
print("Hello! "+uname)
print("Would you like to play a game?")
print("1) Yes")
print("2) No")
option = input("Select your option: ")
option = int(option)
if option==2:
    print("Oh..Okay")
elif option==1:
    print("I\'m thinking a number between 1 and 10")
    print("You have to guess a number in three tries")
    guess = input("Guess a number: ")
    guess = int(guess)
    tries+=1
    if guess>number:
        print("Guess Lower...")
    if guess<number:
        print("Guess Higher...")
    while guess!=number and tries<3:
        guess = input("Try again: ")
        guess = int(guess)
        tries+=1
        if guess>number:
            print("Guess Lower...")
        if guess<number:
            print("Guess Higher...")
    if guess==number:
        print("You won!!")
        print(f"Number of tries: {tries}")
    else:
        print("You lost")
else:
    print("Invalid Option")
