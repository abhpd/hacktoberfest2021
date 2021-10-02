# In this game,
# You have to guess the number chosen randomlyny system in the given attempts.
# There are 2 difficulty level : 
#     1. 'easy' : here you get 10 attempts to make a right guess
#     2. 'hard' : here you get 5 attempts to make a right guess


import random
import os
import guessTheNumber_art

os.system('clear')
# Introductory part of the program
print(guessTheNumber_art.logo)
print("Welcome to the Number Guessing Game!\nI'm thinking of a number between 1 and 100.")
difficulty_level = input("Choose a difficulty. Type 'easy' or 'hard': ").lower()

# For setting the no of attempts according to the diffficulty level chosen
if difficulty_level == 'easy':
    attempts = 10
elif difficulty_level == 'hard':
    attempts = 5
else:
    print("Invalid input")
    
# For determining the number to be guessed
key = random.randint(1,100)
    
if difficulty_level == 'easy' or difficulty_level == 'hard':
    print(f"You have {attempts} attempts remaining to guess the number.")
    game_continue = True
    while(attempts > 0 and game_continue == True):
        guess = int(input("Make a guess: "))
        attempts -= 1
        
        #if the guess made is greater or less than the actual answer
        if guess != key:
            if guess > key:
                print("Too high.\nGuess again.")
            else:
                print("Too low.\nGuess again.")
            #To check whether you ran out of attempts
            if attempts == 0:
                print(f"You ran out of attempts! The answer was {key}.")
                print(guessTheNumber_art.you_lost)
                game_continue = False
            else:
                print(f"You have {attempts} attempts remaining to guess the number.")
        #if the guess is equal to the answer
        else:
            print(f"You got it! The answer is {guess}.")
            print(guessTheNumber_art.you_won)
            game_continue = False
            
        