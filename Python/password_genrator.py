import random

passlen = int(input("Enter the length of your password: "))
# converts user input to integer
random_char = "abcdefghijklmnopqrstuvwxyz01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()?"
data = " "
password = data.join(random.sample(random_char,passlen))
# sample(sample_data,length of sample)
print(password)
