# To get an idea about this game, check this: http://www.higherlowergame.com/

import random
import os
from higherLower_data import data
import higherLower_art

final_score = 0
A = random.choice(data)
B = random.choice(data)
game_continue = True

while game_continue:
    os.system('clear')
    print(higherLower_art.logo)
    print(f"Your current score: {final_score}")
    print(f"Compare A: {A['name']}, a {A['description']}, from {A['country']}.")
    print(higherLower_art.vs)
    print(f"Compare B: {B['name']}, a {B['description']}, from {B['country']}.")
    choice = input("Who has more followers? Type 'A' or 'B': ").upper()
    
    if choice == 'A':
        if A['follower_count'] > B['follower_count']:
            final_score += 1
        else:
            os.system('clear')
            print(higherLower_art.logo)
            print(f"Sorry, that's wrong. Final score: {final_score}")
            game_continue = False
    else:
        if B['follower_count'] > A['follower_count']:
            final_score += 1
        else:
            os.system('clear')
            print(higherLower_art.logo)
            print(f"Sorry, that's wrong. Final score: {final_score}")
            game_continue = False
            
    A = B
    B = random.choice(data)