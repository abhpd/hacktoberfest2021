#The function that returns the length of the longest common subsequence in 2 strings
def lcs(X, Y): 
    #Finding the length of the 2 strings
	m = len(X)
	n = len(Y)

    #Declaring the table to store the values
	L = [[None]*(n + 1) for i in range(m + 1)]

    #Filling the table
	for i in range(m + 1):
		for j in range(n + 1):
			if i == 0 or j == 0 :
				L[i][j] = 0
			elif X[i-1] == Y[j-1]:
				L[i][j] = L[i-1][j-1]+1
			else:
				L[i][j] = max(L[i-1][j], L[i][j-1])
	return L[m][n]

#We use the strings X and Y to test the program
X = "ABCDEFGH"
Y = "CDEIUKM"
print("The length of LCS is: ", lcs(X, Y))

