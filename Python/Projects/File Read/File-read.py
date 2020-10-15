f=open("Test.txt","a+")
while(str!=0):
    str=input()
    if(str!=0):
        f.write(str)
f.seek(0,0)
print("File contents are:")
str=f.read()
print(str)
