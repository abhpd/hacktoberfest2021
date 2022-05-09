# Sudoku

## A sudoku board generator with game-ish mechanics

Made with <a href="https://www.pygame.org/">Pygame</a> and <a href="https://github.com/MyreMylar/pygame_gui">Pygame GUI</a> modules, this project consists in a Sudoku game, that can be played in different difficulties.

### The Solver

The algorithm to solve a given board was inspired by <a href="https://www.youtube.com/watch?v=G_UYXzGuqvM">this Computerphille</a> video, but since I wanted to return a solved board and the algorithm uses recursion and backingtrack, I decided to make some structure changes, and used nested functions.

### The Board Generator

To generate boards, I had two rules:

-   Each board must be solvable
-   Each board must have only one possible solution

For the difficulties level, I decided to simply lower the number of pre-filled cells in harder games.

#### The algorithm was:

-   Choose a random number and put it in a random location
-   Check if the location is possible
    -   If it is possible, commit the change to the new board
    -   Otherwise, choose other location and number
-   After all cells filled, check if the game is possible and has only one solution
    -   If it is, return the board
    -   Otherwise, create a new board

Although this algorithm can perform relatively well, its time complexity is O(infinity), and sometimes will be stuck in a board for a really long time. But in general it can perform well, and for my game, I generated 30 boards in something near half an hour with a pretty poor processor, so larger quantities should be fine, just more slower.

### The Game UI and Mechanics

The game was made with pygame, and was relatively simple if compared to the board solver and generator. The game has:

-   A restart button
-   A menu with three option of difficulty (easy, normal and hard)
-   An info bar that shows how many numbers are left to finish the board
-   A feature that highlights the numbers that are equal to the one in the selected cell

### How to Play

-   To select a cell, simply click in the cell you want to select, or move the selected cell with the keyboard arrows.
-   To input a number, simply press the corresponding key.
-   To delete a number, press 0 or Backspace.
-   To mark a cell with a pencil, hold Shift while pressing the number.
