RABIN KARP ALGORITHM CODE

d = 256
def search(pat, txt, q):
    M = len(pat)
    N = len(txt)
    i = 0
    j = 0
    p = 0    # hash value for pattern
    t = 0    # hash value for txt
    h = 1

#calculating value of h which is d^(M-1)

    for i in range(M-1):
        h = (h*d)%q
 
#calculating hash value of pattern and text resp.

    for i in range(M):
        p = (d*p + ord(pat[i])#ascii value)%q
        t = (d*t + ord(txt[i])#ascii value)%q

#checking if hash values are equal or not.


    for i in range(N-M+1):

        if p==t:

#check for pattern is same.

            for j in range(M):
                if txt[i + j] != pat[j]:
                    break
                else: 
				  j+=1
				
#if j = len(pattern) it means pattern found.


            if j == M:
                print("Pattern found at index " + str(i))

#calculating hash value for t after char is not found and shifting by 1 character.


        if i < (N-M):
            t = (d*(t - ord(txt[i])*h) + ord(txt[I + M]))%q

#if t is negative then add q to it to make positive.

            if t < 0:
                t = t + q
  
# Driver Code
txt = "ABDCB"
pat = "DC"
  
# A prime number
q = 11 
  
# Function Call
search(pat, txt ,q)
