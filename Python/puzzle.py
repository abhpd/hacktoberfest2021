import random
name=input("What is your name?")
print("Good Luck!",name)
words=['rainbow','computer','python','computer','trust','honest',
       'book','mathematics','programming','reverse']
word=random.choice(words)
print("guess the characters....")
guesses=''
turns=10
while turns>0:
    failed=0
    for char in word:
        if char in guesses:
            print(char,end=' ')
        else:
            print("__",end=' ')
            failed+=1
    if failed==0:
        print("\ncongragulations!!!you won..")
        print("the word is :",word)
        break
    guess=input("\n\nGuess a character:")
    guesses+=guess
    if guess not in word:
        turns-=1
        print("wrong,,")
        print("you have ",turns,'more guesses(s)')
    if turns==0:
        print("better luck next time...")
        print("you lose the game!!!")
        print("*"*30)
