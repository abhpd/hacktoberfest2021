# Algorithm
# First generate a random number 
# Then Limit it From 1 to 100
# If number is less than 33 Give it 'S'
# If number is equal to more than 33 and less than 66 Give it 'W'
# If number is equal to more than 66 and less than 100 Give it 'G'
# Input Your choice 'S', 'W', 'G'
# WRITE A FUNCTION WHICH DEMONSTRATES THAT 
# SNAKE KILLS WATER 
# WATER KILLS GUN
# GUN KILLS SNAKE
# State the Winner

def snakeWaterGun(you,comp):
    if(you==comp): #Draw Condition
        return 0
    elif((you=='S' and comp =='W') or (you=='W' and comp =='G') or 
    (you=='G' and comp =='S') ):
        return 1
    else:
        return -1




name = input("Enter Your Name : ")
points = 0
matches = 0
playAgain = 'Y'
while playAgain!='N':
    import random
    n = random.randint(1,100)
    if(n<33):
        comp = 'S'
    elif(n>=33 and n<66):
        comp = 'W'
    else:
        comp = 'G'
    you = input(f"Hello {name}!!,Enter Your Choice : ('S':Snake 'W':Water 'G':Gun) : ")

    result = snakeWaterGun(you,comp)
    print(f"{name}, you have selected {you} and comp has selected {comp}")

    if(result==0):
        print("The Result of this game is Draw")
    elif(result==1):
        print(f"Congratulations {name}!!,You have WON ")
        points=points+1
    else:
        print("You have Lost!,Better Luck Next Time")
    matches = matches+1            
    playAgain=input("DO You Want To Play Again (Type 'Y':Yes 'N':No) : ")
print(f"You Have Won {points} matches in {matches}")
print("Thank You For Playing")