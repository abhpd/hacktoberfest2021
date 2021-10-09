m1=input("Enter first name:")
m2=input("Enter Second name:")
f=list('FLAMES')
print(f)

l1=list(m1)
l2=list(m2)

def diff(l1,l2):
    li_f = [i for i in l1 +l2 if i not in l1 or i not in l2]
    return li_f
li3=diff(l1,l2)
print(li3)

fl_le=len(li3)
print(fl_le)
index=0
while len(f) > 1:
    for i in range(fl_le):
        index += 1
        if index > len(f):
            index = 1
            f.remove(f[index-1])
        index -= 1
print(f)
    
