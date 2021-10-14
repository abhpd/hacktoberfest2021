#importing the time module
import time

# importing the random module
import random

#welcoming the user
name = input("What is your name -- ")
print('')


print ("Hello," ,name, " Time to play hangman!")
print('')

time.sleep(2)


a_list = ['dog','cat','elephant','lion','tiger','cow','camel','goat','bear','deer','horse','wolf','monkey','sheep','fox']

print(' ******* You have to guess the name of Animal ! *******')
print('+++++++++++++++++++++++++++++++++++++++++++++++++++++++++')
print('')
time.sleep(2)

print('---------ARE YOU READY !!!!!!-----------')
print('')
time.sleep(1)


while True:
    print('Press 1 to start the game else 0 to quit !!')
    print('')

    ch=int(input('Enter your choice : '))

    if(ch==1):
        print('')
        print(' &&----------------- Welcome to the game -----------------&&')
        print('')
    elif(ch==0):
        print('')
        # tell the user to play next time
        print('//////Hope to see you soon ..............///////')
        exit()
    else:
        print('')
        print('Invalid choice !! ')
        # exit from the game
        print('To play, Restart the game.')
        exit()

    # getting a random word from the above list
    word= random.choice(a_list)

    #creates an variable with an empty value
    guesses = ''

    #determine the number of lives
    lives=len(word)-1

    time.sleep(3)

    print("It's a {} letter word, so you will get {} chances !".format(len(word),lives))
    print('')
    print('')
    time.sleep(1)

    # Create a while loop

    #check if the lives are more than zero
    while lives > 0: 

        # ask the user go guess a character
        print('')
        guess = input("Guess a character :  ") 


        # set the players guess to guesses
        guesses += guess                    

        # if the guess is not found in the secret word
        if guess not in word:  
                    
            # print wrong
            print('')
            print (guess,"character is not in the word !!")
            print('')
            print('')

            # lives counter decreases with 1 (now 9)
            lives -= 1   

    
            # how many lives are left
            print ("Now, You have", lives, 'more guesses !!')
            print ('')
            print ('')
    
            # if the lives are equal to zero
            if lives == 0: 

                # print "You Lose"
                print ('')
                print ("--------------------------------You Lose------------------------------------") 
                print ('')
                print ('****---- The correct word is',word,'----****')
                print('')
            
                break       

        # make a counter that starts with zero
        failed = 0             

        # for every character in word   
        for char in word:      

            # see if the character is in the players guess
            if char in guesses:    
        
                # print then out the character
                print (char,end=' ')
            
            else:
        
                # if not found, print a dash
                print ("_",end=' ')     
        
                # and increase the failed counter with one
                failed += 1   
            
        
        # if failed is equal to zero
        # print You Won
        if failed == 0:   
            print ('')     
            print ("------------------Congrats {} !, You won the game with {} lives left !---------------------".format(name,lives)) 
            print ('')
            print ('')

            # exit the script
            break  
