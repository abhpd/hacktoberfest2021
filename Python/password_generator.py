import string
import random

a=random.randint(10000,99999)
a=str(a)
for i in range(1,5):
	a=a+random.choice(string.ascii_letters)

for i in range(1,3):
	a=a+random.choice(string.punctuation)
a=list(a)
random.shuffle(a)
a=''.join(a)
print(a)