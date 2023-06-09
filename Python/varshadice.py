import random
while True:
    print("=================================================")
    print("*****************ROLLING THE DICE*****************")
    print("=================================================")
    num=random.randint(1,6)
    if num==6:
        print("hey---you got",num,"congragulations!!")
    elif num==1:
        print("well tried you got ",num,"next time !!")
    else:
        print("you got ",num)
    ch=input("roll again?(y/n)")
    if ch in 'Nn':
        break
print("thanks for playing!!!!!!!!!!!!")
