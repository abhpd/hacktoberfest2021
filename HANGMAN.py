import random
print("H A N G M A N")
while True:
    gameStart = input('Type "play" to play the game, "exit" to quit: ')
    if gameStart == "play":
        print("")
        wordList = ['python', 'java', 'kotlin', 'javascript','rainbow', 'computer', 'science', 'programming',  
         'python', 'mathematics','c++','php','Djnago', 'player', 'condition',  
         'reverse', 'water', 'board', 'geeks']
        guess = random.choice(wordList)
        dashStr = "-" * len(guess)
        print(dashStr)
        guessedList = []
        lives = 8
        while  lives > 0: 
            word = input("Input a letter:  ")
            if len(word) > 1 or len(word) == 0:
                print("You should input a single letter")
            elif  word.islower():
                pass
            else:
                print("It is not an ASCII lowercase letter")
        
            if word in guessedList:
                print("You already typed this letter")
                print("")
                print(dashStr)
                continue
            else:
                guessedList.append(word)
            if lives == 0:
                print("You are hanged!")
                print("")
                break
            if word in guess:
                for j in range(len(guess)):
                    if guess[j] == word:
                        dashStr = dashStr[:j] + word + dashStr[j+1:]
                if dashStr == guess:
                    pass
                else:
                    print("")
                    print(dashStr)
                if dashStr == guess:
                    print("You guessed the word " + dashStr + "!")
                    print("You survived!") 
                    print("")
                    break
            else:
                if len(word) > 1 or not word.islower():
                    pass
                elif word in guessedList and word in guess:
                    pass
                else:
                    lives -= 1
                    print("No such letter in the word ,please give appropriate word")
                if lives == 0:
                    pass
                else:
                    print("")
                    print(dashStr)
            if lives == 0:
                print("You are hanged!")
                print("")
                break
    else:
        break
