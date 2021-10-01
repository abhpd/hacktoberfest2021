
print('Guess the Word Game')

print('You have 5 times to guess the word')

target = input()
guess = input()

count = 1

while count < 5:

    if guess == target:
        print('Congratulation, You win.')
        break
    else:
        print('please guess again you have {} times.'.format(5-count))
        guess = input()
        count += 1
    
if count == 5:
    print('You lose')
    