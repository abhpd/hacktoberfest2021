import numpy as np
from random import choice
import sys
import json


class Board:
    """
    Board object. Stores a board, as well the methods to solve this board, serialize it, or load other boards.
    If no arguments are passed, the object will create a new board with difficulty 1.

    Args:
        board (array): [OPTIONAL default=None] A 2 dimensional array (9, 9) representing the board. Empty spaces are represented with zeros. 

        difficulty (int): [OPTIONAL default=1] A number between 1 and 3 (inclusive) to determine difficulty, where 1 is easier, and 3 is harder.

        board_path (str): [OPTIONAL default=None] The path to JSON file that stores an array of boards previously saved by the saveBoards() method.
    """

    def __init__(self, board=None, difficulty=1, board_path=None):

        self.board = []

        if difficulty > 3 or 0 >= difficulty:
            raise Exception(
                "The difficulty must be an integer between 1 and 3")
        if board_path is None:
            self.board = self.createBoard(
                difficulty) if board is None else board
        else:
            self.loadBoard(board_path)

    def isPossible(self, board, y, x, n):
        """
        Checks if a given number in given positions on a given board is possible

        Args:
            board (array): A 2 dimensional array that contains the board
            y (int): The line position
            x (inte): The column postion
            n (int): The number from 1 to 9 that check against the board in the postion

        Returns:
            boolean: True if it is possible, otherwise returns False
        """

        # check in line
        for i in board[y]:
            if i == n:
                return False

        # check in column
        for i in range(9):
            if board[i][x] == n:
                return False

        # check in square
        # number between 0 and 2 to indicate the x square
        squareX = (x // 3) * 3
        # same for y square
        squareY = (y // 3) * 3

        for i in range(squareY, squareY+3):
            for j in range(squareX, squareX+3):
                if board[i][j] == n:
                    return False

        return True

    def solveBoard(self):
        """
        Nested function that solves a given sudoku board.  

        Returns:
            array: A solved board.
        """

        # stores the board in a local varibale, so it can be used by nonlocal
        b = self.board.copy()
        new = []
        counter = 0

        def solve():
            """
            Recursively solves the board. 
            """
            nonlocal b, new, counter

            for i in range(9):
                for j in range(9):
                    if b[i][j] == 0:

                        for k in range(1, 10):
                            if self.isPossible(b, i, j, k):

                                b[i][j] = k
                                solve()
                                b[i][j] = 0

                        return

            # keep track of how many solutions exists
            counter += 1
            # transform it in a numpy array because numpy arrays are immutable
            new = np.array(b)

        # call the function to solve board b
        solve()
        # return the solved board if olny one solution exists
        if counter == 1:
            return new.tolist()
        else:
            raise AttributeError()

    def createBoard(self, difficulty):
        """
        Creates a possible board with given number of cells filled.

        Args:
            difficulty (int): The difficulty of the board based on how many cells are filled.

        Returns:
            array: A board to be solved.
        """

        board = []

        dif = {
            "1": 35,
            "2": 27,
            "3": 26
        }

        def create():
            new = np.zeros((9, 9), dtype=int).tolist()

            for i in range(dif[str(difficulty)]):
                # pick random row, collumn and number to fill a cell
                row = np.random.randint(0, 9)
                col = np.random.randint(0, 9)
                num = np.random.randint(1, 10)

                # while the current spot is not avilable, keep picking
                while (not self.isPossible(new, row, col, num) or new[row][col] != 0):
                    row = np.random.randint(0, 9)
                    col = np.random.randint(0, 9)
                    num = np.random.randint(1, 10)

                # assign the number to the cell
                new[row][col] = num
            return new

        # check if game is possible and if not, redo the process
        possible = False
        t = 0
        while (not possible):
            try:
                self.board = create()
                board = self.board[:]
                self.solveBoard()
                possible = True
            except AttributeError:
                t += 1
                # print(f"Boards tested: {t}", end="\r")
                possible = False
            except KeyboardInterrupt:
                print(board)
                sys.exit()

        return board

    def saveBoards(self, file_path, amount, difficulty=None):
        """
        Serialize a board in JSON format in a given file

        Args:
            file_path (str): The path to the file that will contain the data.
            amount (int): The amount of boards that will be stored.
            difficulty (int): NUmber between 1 and 3 to define difficulty of the board.
        """
        created = 0

        data = []
        dif = [1, 2, 3]
        for i in range(amount):
            n = choice(dif) if difficulty is None else difficulty
            print(f"Boards created: {created}", end="\r")
            data.append(self.createBoard(difficulty=n))
            created += 1

        with open(file_path, "w") as file:
            json.dump(data, file)

    def loadBoard(self, file_path):
        """
        Load a board that was previously saved in a JSON file

        Args:
            file_path (str): The path to the file that contain the data.
        """
        boards = []
        with open(file_path) as file:
            boards = json.load(file)

        self.board = choice(boards)


if __name__ == "__main__":
    grid = [[4, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 9, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 7, 8, 5],
            [0, 0, 7, 0, 4, 8, 0, 5, 0],
            [0, 0, 1, 3, 0, 0, 0, 0, 0],
            [0, 0, 6, 0, 7, 0, 0, 0, 0],
            [8, 6, 0, 0, 0, 0, 9, 0, 3],
            [7, 0, 0, 0, 0, 5, 0, 6, 2],
            [0, 0, 3, 7, 0, 0, 0, 0, 0]]

    game = Board(grid)

    game.saveBoards("./boards/easy-boards.json", 10, difficulty=1)
    game.saveBoards("./boards/medium-boards.json", 10, difficulty=2)
    game.saveBoards("./boards/hard-boards.json", 10, difficulty=3)
