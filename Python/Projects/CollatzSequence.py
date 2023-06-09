#collatz sequence
def collatz_sequence(n):
    collatz_list=list() #list to store the values of sequence
    
    while (n!=1) :
        collatz_list.append(n) 
        #if n is even
        if (n%2==0) :
            n=n//2
        else:
          #if n is odd
            n=(3*n)+1
    collatz_list.append(1)  #print 1 in the end   
    l=len(collatz_list)

    print("The length of collatz sequence is", l)
    print("The sequence is :")
    for i in range(0,l):
      print(collatz_list[i])
collatz_sequence(11)
#sajal gururani