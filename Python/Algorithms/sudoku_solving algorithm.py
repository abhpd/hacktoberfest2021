def valid(grid,num,pos):
    #check row
    for i in range(len(grid[0])):
        if grid[pos[0]][i]==num and pos[1]!=i:
            return False
    #check column
    for i in range(len(grid)):
        if grid[i][pos[1]]==num and pos[0]!=i:
            return False
    #check box
    x=pos[0]//3
    y=pos[1]//3
    for i in range(x*3,(x+1)*3):
        for j in range(y*3,(y+1)*3):
            if grid[i][j]==num and (i,j)!=pos:
                return False
    return True
    
    

def empty(grid):
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j]==0:
                return (i,j)
    return None

def solve_grid(grid):

   # print("-----------------------------------")
    find=empty(grid)
    if not find:
        return True
    else:
        row,col=find
    for i in range(1,10):           #iterate through 1 to 9 
        if valid(grid,i,(row,col)):
            grid[row][col]=i
            
            if solve_grid(grid):     #recursive call 
                return True
            grid[row][col]=0   #backtracking  if false 
            
    return False
            

l=list(map(int,input().split()))
#input()=[5 3 0 0 7 0 0 0 0 6 0 0 1 9 5 0 0 0 0 9 8 0 0 0 0 6 0 8 0 0 0 6 0 0 0 3 4 0 0 8 0 3 0 0 1 7 0 0 0 2 0 0 0 6 0 6 0 0 0 0 2 8 0 0 0 0 4 1 9 0 0 5 0 0 0 0 8 0 0 7 9]

grid=[]
for i in range(9):
    grid.append(l[9*i:9*(i+1)])

for i in range(9):
    print(*grid[i])
print("------------------------------")
if solve_grid(grid):
    for i in range(9):
        print(*grid[i])
else:
    print("No solution")
    
    
