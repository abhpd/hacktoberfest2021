'''users have options to tackle a situation and with each input provided by the user,
the game will continue to increase by putting more situations and more options.'''

import time

# function to ask play again or not
def play_again():
    print("Do you want to play again? (y or n)")

    # convert the player's input to lower_case
    answer = input(">").lower()

    if "y" in answer:
    # if player typed "yes" or "y" start the game from the beginning
        start()
    else:
    # if user types anything besides "yes" or "y", exit() the program
        exit()

        # game_over function accepts an argument called "reason"


def game_over(reason):

    # print the "reason" in a new line
    print("\n" + reason)
    print("Game Over!")
    # ask player to play again or not by activating play_again() function
    play_again()


# diamond room
def diamond_room():
    # some prompts
    print("You are now in a room filled with diamonds!")
    print("And there is a door too!")
    print("What would you do? (1 or 2)")
    print("1). Take some diamonds and go through the door.")
    print("2). Just go through the door.")

    # take input()
    answer = input(">")

    if answer == "1":
    # the player is dead, call game_over() function with the "reason"
        game_over("They were cursed diamonds! The moment you touched it, the building collapsed, and you die!")
    elif answer == "2":
    # the player won the game
        print("Nice, you're are an honest man! Congrats you win the game!")
    # activate play_again() function
        play_again()
    else:
    # call game_over() with "reason"
        game_over("Go and learn how to type a number.")


# monster room
def monster_room():


    # some prompts

    print("Now you entered the room of a monster!")
    print("The monster is sleeping. Behind the monster, there is another door.What would you do? (1 or 2)")
    print("1). Go through the door silently.")
    print("2). Kill the monster and show your courage!")

    # take input()
    answer = input(">")

    if answer == "1":
    # lead him to the diamond_room()
        diamond_room()
    elif answer == "2":
    # the player is dead, call game_over() with "reason"
        game_over("The monster was hungry, he/it ate you.")
    else:
    # game_over() with "reason"
        game_over("Go and learn how to type a number.")

# bear room
def bear_room():

    # give some prompts
    print("There is a bear here.")
    print("Behind the bear is another door.")
    print("The bear is eating tasty honey!")
    print("What would you do? (1 or 2)")
    print("1). Take the honey.")
    print("2). Taunt the bear.")

    # take input()
    answer = input(">")

    if answer == "1":
    # the player is dead!
        game_over("The bear killed you.")
    elif answer == "2":
    # lead him to the diamond_room()
        print("Your Good time, the bear moved from the door.You can go through it now!")
        diamond_room()
    else:
    # else call game_over() function with the "reason" argument
        game_over("Don't you know how to type a number?")


def start():
    # give some prompts.
    print("You are standing in a dark room.")
    print("There is a door to your left and right, which one do you take? (l or r)")

    # convert the player's input() to lower_case
    answer = input(">").lower()

    if "l" in answer:
    # if player typed "left" or "l" lead him to bear_room()
        bear_room()
    elif "r" in answer:
    # else if player typed "right" or "r" lead him to monster_room()
        monster_room()
    else:
    # else call game_over() function with the "reason" argument
        game_over("Don't you know how to type something properly?")

name = str(input('Enter Your Name: '))
print(f"{name} here's a situation for you :-")
time.sleep(1)

# start the game
start()