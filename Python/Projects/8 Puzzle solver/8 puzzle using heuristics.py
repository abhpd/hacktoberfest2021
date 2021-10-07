import copy
import numpy as np
import random

#Global declaration
x,y,prev_x,prev_y = 0,0,0,0
A = np.array([[1,3,2],[4,6,5],[7,8,0]])
prev_key = 'null'
open_list = []
path = []
count=0

def evaluation(a):#to check whether its solvable or not
    t=[x[i]for x in a for i in range(3)]
    count=0
    for i in range(8):
        for j in range(i + 1, 9):
            if t[j] and t[i] and t[i] > t[j]:
                count += 1
    print(count%2==0)

def find_zero_position(current_state):
    for i in range(3):
        for j in range(3):
            if(current_state[i][j]==0):
                return i,j#finds zero 's position
    
def swap(loc_x,loc_y):
    global A,prev_x,prev_y,open_list
    temp_x = prev_x
    temp_y = prev_y
    loc_array = copy.deepcopy(A)
    loc_array[temp_x,temp_y] = loc_array[loc_x,loc_y]
    loc_array[loc_x,loc_y] = 0
    open_list.append(loc_array)

def checkit(array):#checks whether its equal or not
    for i in range(len(path)):
        if_equal = path[i] == array
        compare = if_equal.all()
        if compare:
            return False
    return True

def manhattan_distance(array):
    goal_state = np.array([[1,2,3],[4,5,6],[7,8,0]])
    increment = 0
    for i in range(0,3):
        for j in range(0,3):
            if array[i,j] != 0:
                if array[i,j] != goal_state[i,j]:
                    increment += 1
    return increment

def astar():
    global open_list,A,count,path
    min_count = 10000000
    index = 0
    for i in range(0,len(open_list)):
        h = manhattan_distance(open_list[i])
        cndtn = checkit(open_list[i])
        if ((h < min_count) and (cndtn)):
            min_count = h
            index = i
    A = open_list[index]
    path.append(open_list[index])
    return index

def check(key):
    global A,x,y,prev_x,prev_y,prev_key,open_list


    for i in range(0,len(key)):
        loc_x = x
        loc_y = y
        if key[i] == 1:
            loc_x -= 1
        if key[i] == 2:
            loc_x += 1
        if key[i] == 4:
            loc_y -= 1
        if key[i] == 3:
            loc_y += 1
        swap(loc_x,loc_y)               

    index = astar()
    loc_key = key[index]
    if loc_key == 1:
        prev_key = 2
    if loc_key == 2:
        prev_key = 1
    if loc_key == 4:
        prev_key = 3
    if loc_key == 3:
        prev_key = 4
    open_list = []
    return index

def solve(current_state):
    global intial,x,y,prev_x,prev_y,prev_key,A
    print("1-up, 2- down , 3- right, 4-left")
    key1 = [3,2]#possible moves for 0 in each state ( if 0 is 1 s position possible moves are right or down)
    key2 = [4,3,2]
    key3 = [4,2]
    key4 = [1,3,2]
    key5 = [1,2,3,4]
    key6 = [1,4,2]
    key7 = [1,3]
    key8 = [4,3,1]
    key9 = [1,4]

    keys = [key1,key2,key3,key4,key5,key6,key7,key8,key9]
    x,y=find_zero_position(current_state)
    prev_x=x
    prev_y=y
    key = keys[(x*3)+(y*1)]#to choose the apt key movement refered from stackoverflow
   
    count = 0   
    run=True

    while run:
       index = check(key)
       x,y=find_zero_position(A)
       prev_x=x
       prev_y=y
       key= copy.deepcopy(keys[(x*3)+(y*1)])
       key.remove(prev_key)#removes duplicate iterations
       print(A,'\n')
       puzzle_equal=A==goal_state
       comp=puzzle_equal.all()#to check all instances in numpy(.all()) refered from net
       if comp:
           print('count:',count)
           run=False
       else:
            print('\n')
       count+=1
       
def main():
    global goal_state,A
    A = np.array([[0,0,0],[0,0,0],[0,0,0]])
    goal_state=[[1,2,3],[4,5,6],[7,8,0]]
    print("Enter your desired puzzle:")                
    for i in range(0,3):
        for j in range(0,3):
            print("Enter the element at ",i+1," ",j+1,": ")
            A[i,j] = input()
    evaluation(A)
    if(evaluation==False):
        print("its difficult to solve!!")
        exit()
    else:
        print("yes its solvable")
    #number_of_misplaced_pieces(intial)
        solve(A)
main()
