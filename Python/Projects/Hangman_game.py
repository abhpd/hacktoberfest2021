import random as r
file = open('words.txt','r')
lst = ['Javascript','People','Laptop','Developer','Programming','Coding','\
Ubuntu','Science','Nature','Apple','Youtube','Instagram','Whatsapp','Twitte\
r','Facebook','Github','Samsung','Redmi','Computer','Google','Music','Movies','Dance']
for each in file:
    print(each,end="")
    if(each!='\n'):
        lst.append(each)
print("Choose a word from the above words")
print("You have 6 chances")
f = 0
for i in range(6,-1,-1):
    r.shuffle(lst)
    ans = r.choice(lst)
    guess = input("Guess !! => ").capitalize()
    if guess == ans :
        print("You Won !! ,your guess is correct ")
        f = 1
    else:
        print("Wrong answer !the answer is => {} ".format(ans))
        print(i," chances left !!")
if f ==0:
    print("You lost the game !! ,Try again")
