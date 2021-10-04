// Depth-first search
// Recursive backtracker
// https://en.wikipedia.org/wiki/Maze_generation_algorithm


/*
Main Idea
1. Choose the initial cell, mark it as visited and push it to the stack
2. While the stack is not empty
   1. Pop a cell from the stack and make it a current cell
   2. If the current cell has any neighbours which have not been visited
      1. Push the current cell to the stack
      2. Choose one of the unvisited neighbours
      3. Remove the wall between the current cell and the chosen cell
      4. Mark the chosen cell as visited and push it to the stack
*/

let rows,cols 
let box_size = 50
//create an array
let grid = []

//currrent cell
let current

//create stack
let stack = []

function setup(){
  createCanvas(400,400)
  frameRate(5)
  
  //number of each column and row 
  //width of canvas by box size 
  rows = floor(width/box_size)
  cols = floor(width/box_size)
  
  
  //create table
  for(let i = 0;i< rows;i++){
    for(let j =0;j<cols;j++){
      let cell = new Cell(i,j)
      grid.push(cell)
    }
  }
  //current cell initially is first cell
  current = grid[0]
}

function draw(){
  background(50);
  
  for(let i=0;i<grid.length;i++){
    grid[i].show()
  }
  
  current.visited = true
  current.highlight()
  
  //return value of any neighbors
  let nextBox = current.checkNeighbor()
  
  if(nextBox){
    
    //if nextBox is chosen then its visited
    //so set its value to True
    nextBox.visited = true
    
    
    //push current box to stack
    stack.push(current)
    
    //remove walls between neighbor box call
    
    removeWall(current,nextBox)
    //set current box value as nextBox value looping
    current = nextBox
  }
  //when stuck backtrack
  else if (stack.length > 0 ){
    //pop the cell and make it current cell 
    // then we apply back tracking
    current = stack.pop()
    
  }
}


//function to calculate postion of neighbor
function indexNeighbor(col_num,row_num){
  
  //if we get out of bound index numbers or invalid index numbers
  if(col_num < 0 || row_num < 0 || col_num > cols -1 || row_num > rows-1){
    return -1
  }
  // column number + row number multiply by columns
  return col_num + row_num * cols
}


//constructor for cell object
function Cell(row_num,column_num){
  this.row = row_num
  this.column = column_num
  
  //boolean array whether walls exist or not
  this.walls = [true,true,true,true]
  //start as cell not visited
  this.visited = false
  
  //function that checks for neighbor
  /* top , right , bottom , left */
  this.checkNeighbor = function (){
    
    //list of neighbors to current box
    let neighborList = []
    
    let topBox = grid[indexNeighbor(this.column,this.row - 1)]
    
    let rightBox = grid[indexNeighbor(this.column + 1,this.row )]
    
    let bottomBox = grid[indexNeighbor(this.column,this.row + 1)]
    
    let leftBox = grid[indexNeighbor(this.column - 1,this.row)]
    
    
    //if topBox is valid index and not visited
    if (topBox && !topBox.visited){
      neighborList.push(topBox)
    }
    
    //if rightBox is valid index and not visited
    if (rightBox && !rightBox.visited){
      neighborList.push(rightBox)
    }
    
    //if bottomBox is valid index and not visited
    if (bottomBox && !bottomBox.visited){
      neighborList.push(bottomBox)
    }
    
    //if leftBox is valid index and not visited
    if (leftBox && !leftBox.visited){
      neighborList.push(leftBox)
    }
    
    //if neighborList has some value pick a random value
    if(neighborList.length > 0){
      let randomNeighbor = floor(random(0,neighborList.length))
      //return random neighbor
      return neighborList[randomNeighbor]
    }
    
    else{
      return undefined
    }
  }
  
  //highlight function visual aid
  this.highlight = function (){
    let x_coord = this.column * box_size
    let y_coord = this.row * box_size
    noStroke()
    fill(255,0,255,100)
    rect(x_coord,y_coord,box_size,box_size)
  }
  
  
  this.show = function(){
    let x_coord = this.column * box_size
    let y_coord = this.row * box_size
    
    
    
    stroke(255)
    if(this.walls[0]){
      line(x_coord,y_coord,x_coord+box_size, y_coord)
    }
    if(this.walls[1]){
       line(x_coord+box_size, y_coord,x_coord+box_size,y_coord+box_size)
    }
    if(this.walls[2]){
       line(x_coord+box_size, y_coord+box_size,x_coord,y_coord+box_size)
    }
    
    if(this.walls[3]){
       line(x_coord,y_coord+box_size,x_coord,  y_coord)
    }
    
    
   
   
    if (this.visited == true){
      //so when visited remove wall
      noStroke()
      fill(0,0,255,80)
      rect(x_coord,y_coord,box_size,box_size)
    }
   
  }
}


function removeWall(boxA,boxB){
  
  //store difference between box columns
  let removeCol = boxA.column - boxB.column
  /* box walls index
    top   - 0
    right - 1
    bottom- 2
    left  - 3
    */
  
  //if differnce is 1 then they are neighbors
  if (removeCol === 1){
    
    //remove left wall of boxA and right wall of boxB
    //to remove set to false
    boxA.walls[3] = false
    boxB.walls[1] = false
  }
  
  else if (removeCol === -1){
    
    //remove right wall of boxA and left wall of boxB
    //to remove set to false
    /*
    |A |B |
    |__|__|
    */
    boxA.walls[1] = false
    boxB.walls[3] = false
  }
  
    //store difference between box columns
  let removeRow = boxA.row - boxB.row
  /* box walls index
    top   - 0
    right - 1
    bottom- 2
    left  - 3
    */
  
  //if differnce is 1 then they are neighbors
  if (removeRow === 1){
    
    //remove top wall of boxA and bottom wall of boxB
    //to remove set to false
    boxA.walls[0] = false
    boxB.walls[2] = false
  }
  
  else if (removeRow === -1){
    
    //remove bottom wall of boxA and top wall of boxB
    //to remove set to false
    /*
    |A |
    |__|
    |B |
    |__|
    */
    boxA.walls[1] = false
    boxB.walls[3] = false
  }
  
  
}
