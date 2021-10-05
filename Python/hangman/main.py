import random
from art import stages, logo

def hangman():
    lives = len(stages) -1

    word= ["viroopaksh", "utrayak", "github", "opensource", "mahakali", "mahakal", "radhakrishna", "aadhya"]
    rand= random.choice(word)
    
    display = []

    for i in range(len(rand)):
        display += "_"

    play = True

    while play:
        user_input= input("guess a word: ")
        if user_input in display:
            print("already guessed")

        elif user_input not in rand:
            print(stages[lives])
            lives -=1
            if lives == 1:
                print(rand[0])
            if lives == -1 :
                play = False
                print("you loose")

        elif user_input in rand:
            for i in range(len(rand)):
                if user_input == rand[i]:
                    display[i] = user_input
            print(f"{' '.join(display)}")
            
        if "_" not in display:
            print("u win")
            play_again= input("play again: ").lower()
            if play_again == "yes":
                hangman()
            elif play_again=="okay":
                hangman()
            elif play_again== "sure":
                hangman()
            elif play_again== "of course":
                hangman()
            elif play_again== "absolutely":
                hangman()
            elif play_again== "ofcourse":
                hangman()
            else:
                play = False

hangman()
