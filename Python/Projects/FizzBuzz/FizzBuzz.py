# Fizz and Buzz refer to any number that is a multiple of 3 and 5.
# If the integer (x) is divisible by 3, the output must be replaced by “Fizz”.
# If the integer (x) is divisible by 5, the output must be replaced by “Buzz”.
# If the integer (x) is divisible by 3 and 5, the output should be replaced by “FizzBuzz”.

range_num = int(input("Enter range from 1 till: "))
for i in range (1, range_num):
    if i % 3 == 0 and i % 5 == 0:
        print("FizzBuzz")
    elif i % 3 == 0:
        print("Fizz")
    elif i % 5 == 0:
        print("Buzz")
    else:
        print(i)
