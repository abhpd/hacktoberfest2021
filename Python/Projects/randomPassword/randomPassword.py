#!/usr/bin/env python3
#RamSalado | BeeHackers

import random
# This library it´s necesary

k="abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ#@!][}{?¿%&"
# Characters that the password will include 

len = 12
# Password length 

p="".join(random.sample(k,len))

print(p)
