'''

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

Input:
matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

Input:
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Step 1: Iterate through first column to check if it has 0 or not.

0	1	2	0
3			
1			
Step 2: Iterate through 2nd column. If any element is 0 in the matrix make the values at index 0 in first row and column.

0	1	2	0
3			
1			
Step 3: Traverse backwards and if the first row and column contains 0, set the value of arr[i][j] = 0.

0	1	2	0
3	4	5	2
1	3	1	5

'''


def setZeroes(arr):
    row = len(arr)
    col = len(arr[0])
    #Flag is to check wether the first column has 0 or not
    flag = True               

    for i in range(row):
        if(arr[i][0] == 0):
            flag = False

        for j in range(1, col): 
            if(arr[i][j] == 0):
                arr[i][0] = arr[0][j] = 0
    
    for i in range(row-1, -1, -1):
        for j in range(col-1, 0, -1):
            if(arr[i][0] == 0 or arr[0][j] == 0):
                arr[i][j] = 0
        if flag == False:
            arr[i][0] = 0

    return arr