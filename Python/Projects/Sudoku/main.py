import numpy as np
import pygame
import pygame_gui
from board import Board


class Main:

    def __init__(self):
        pygame.init()

        # WINDOW DIMENSIONS
        self.WIDTH = 450
        self.HEIGHT = 550

        # PYGAME GUI ELEMENTS
        self.manager = pygame_gui.UIManager((self.WIDTH, self.HEIGHT))

        menuButtonWidth = 60
        menuButtonHeight = 30

        self.menuButton = pygame_gui.elements.UIButton(
            relative_rect=pygame.Rect(
                int(self.WIDTH / 2 - menuButtonWidth - 5), 517, menuButtonWidth, menuButtonHeight),
            text="Menu",
            manager=self.manager,
            starting_height=30)

        self.restartButton = pygame_gui.elements.UIButton(
            relative_rect=pygame.Rect(
                int(self.WIDTH / 2 + 5), 517, menuButtonWidth + 10, menuButtonHeight),
            text="Restart",
            manager=self.manager,
            starting_height=30
        )

        self.drawMenu()

        # BOARD DIMENSIONS
        self.BOARD_HEIGHT = 450
        self.BOARD_WIDTH = 450

        pygame.display.set_caption("Sudoku!")
        self.screen = pygame.display.set_mode((self.WIDTH, self.HEIGHT))
        self.screen.fill(pygame.Color("#A7B3A1"))

        self.backgound = pygame.Surface((self.WIDTH, self.BOARD_HEIGHT))
        self.backgound.fill(pygame.Color("#ffffff"))

        # FONTS
        self.numbersFont = pygame.font.SysFont('arial', 35)

        # start game
        self.startGame(1, True)

        self.running = True
        self.clock = pygame.time.Clock()

    def drawGrid(self):
        """
        Draw the 9x9 grid.
        """
        resY = int(self.BOARD_HEIGHT / 9)
        resX = int(self.BOARD_WIDTH / 9)

        # border lines
        pygame.draw.line(self.backgound, (0, 0, 0),
                         (0, 0), (self.BOARD_WIDTH, 0))
        pygame.draw.line(self.screen, (0, 0, 0),
                         (0, self.BOARD_HEIGHT), (self.BOARD_WIDTH, self.BOARD_HEIGHT), 3)
        pygame.draw.line(self.backgound, (0, 0, 0),
                         (0, 0), (0, self.BOARD_HEIGHT))
        pygame.draw.line(self.backgound, (0, 0, 0),
                         (self.BOARD_WIDTH, 0), (self.BOARD_WIDTH, self.BOARD_HEIGHT))

        # 8 because I want to draw the border lines out of the loop
        for i in range(8):
            # horizontal lines
            y = i * resY + resY
            # vertical lines
            x = i * resX + resX
            if (i + 1) % 3 == 0:
                # horizontal bold
                pygame.draw.line(self.screen, (0, 0, 0),
                                 (0, y),
                                 (self.BOARD_WIDTH, y), 3)
                # vertical bold
                pygame.draw.line(self.screen, (0, 0, 0),
                                 (x, 0),
                                 (x, self.BOARD_HEIGHT), 3)
            else:
                # horizontal
                pygame.draw.line(self.screen, (0, 0, 0),
                                 (0, y),
                                 (self.BOARD_WIDTH, y))
                # vertical
                pygame.draw.line(self.screen, (0, 0, 0),
                                 (x, 0),
                                 (x, self.BOARD_HEIGHT))

            pygame.draw.line(self.screen, (0, 0, 0),
                             (x, 0),
                             (x, self.BOARD_HEIGHT))

    def drawNumbers(self):
        """
        Draw the number on the grid.
        """

        resY = int(self.BOARD_HEIGHT / 9)
        resX = int(self.BOARD_WIDTH / 9)

        for i in range(9):
            for j in range(9):

                # the main board
                if self.game.board[i][j] != 0:
                    # the current number
                    text = str(self.game.board[i][j])
                    if self.originalBoard[i][j] != 0:
                        n = self.numbersFont.render(
                            text, True, pygame.Color("#B32D32"))
                    else:
                        n = self.numbersFont.render(
                            text, True, pygame.Color("#000000"))

                    # to center the number
                    x, y = self.numbersFont.size(text)

                    yPos = int((i * resY + resY / 2) - y / 2)
                    xPos = int((j * resX + resX / 2) - x / 2)

                    self.screen.blit(n, (xPos, yPos))

                # the pencil board
                if self.pencilBoard[i][j] != 0:
                    # the current number
                    text = str(self.pencilBoard[i][j])
                    n = self.numbersFont.render(
                        text, True, pygame.Color("#8C8C8C"))

                    # to center the number
                    x, y = self.numbersFont.size(text)

                    yPos = int((i * resY + resY / 2) - y / 2)
                    xPos = int((j * resX + resX / 2) - x / 2)

                    self.screen.blit(n, (xPos, yPos))

    def selectCell(self, mouse_pos):
        """
        Select a cell from the grid. If the cell is already selected, deselect it.

        Args:
            mouse_pos (tuple of integers): The x and y positions of the mouse. e.g. selectCell(pygame.mouse.get_pos())
        """

        mouseX, mouseY = mouse_pos

        resY = int(self.BOARD_HEIGHT / 9)
        resX = int(self.BOARD_WIDTH / 9)

        # a number between 0 and 8 to indicate the position in the outter array
        cellY = mouseY // resY
        # a number between 0 and 8 to indicate the position in the inner array
        cellX = mouseX // resX

        if (cellX, cellY) == self.currentSelected:
            self.currentSelected = None
        else:
            self.currentSelected = (cellX, cellY)

    def moveSelected(self, direction):
        """
        Move the selected cell in the grid.

        Args:
            direction (str): The direction to move. Can be: "up", "down", "right", or "left".
        """

        x, y = self.currentSelected

        canMove = False
        offset = 1

        if direction == "up":
            if y != 0:
                self.currentSelected = (x, y - offset)

        elif direction == "down":
            if y != 8:
                self.currentSelected = (x, y + offset)

        elif direction == "right":
            if x != 8:
                self.currentSelected = (x + offset, y)
        elif direction == "left":
            if x != 0:
                self.currentSelected = (x - offset, y)

    def highlightCell(self, pos, color):
        """
        Highlight a cell in a given postion with a given color

        Args:
            pos (int): A tuple containing x and y coordinates in the array. e.g. (3, 2)
            color (Pygame Color Object / tuple of three int): The color to highlight the cell. Can be either a Pygame Color Object or a tuple, like (255, 255, 255)
        """

        resY = int(self.BOARD_HEIGHT / 9)
        resX = int(self.BOARD_WIDTH / 9)

        x, y = pos

        xRec = x * resX
        yRec = y * resY

        pygame.draw.rect(self.screen, color,
                         pygame.Rect(xRec, yRec, resX, resY))

    def drawSelected(self):
        """
        Highlight the selected cell
        """

        resY = int(self.BOARD_HEIGHT / 9)
        resX = int(self.BOARD_WIDTH / 9)

        if self.currentSelected is not None:
            self.highlightCell(self.currentSelected, pygame.Color(
                "#64DE84"))

    def drawAllEqual(self):
        """
        Highlight the cells that contain the same number in the selected cell.
        """

        if self.currentSelected is not None:
            x, y = self.currentSelected
            curr = self.game.board[y][x]

            if curr != 0:
                for i in range(9):
                    for j in range(9):
                        if self.game.board[i][j] == curr:
                            self.highlightCell((j, i), pygame.Color("#AEFFAB"))

    def setNumber(self, num):
        """
        Receive a number and set the current selected cell to this number.

        Args:
            num (int): The number to be set
        """

        x, y = self.currentSelected
        if self.originalBoard[y][x] == 0:
            if self.pencilBoard[y][x] != 0:
                self.pencilBoard[y][x] = 0
            self.game.board[y][x] = num

    def pencilNumber(self, num):
        """
        Receive a number and set it to temporary number. Mark the number as a "pencil".

        Args:
            num (int): The number to be set
        """

        x, y = self.currentSelected
        if self.originalBoard[y][x] == 0:
            if self.game.board[y][x] != 0:
                self.game.board[y][x] = 0
            self.pencilBoard[y][x] = num

    def startGame(self, difficulty, isStart=False):
        """
        Set everything up to the game begin.

        Args:
            difficulty (int): Number between 1 and 3 (inclusive) to determine the difficulty of the game.
        """

        # create game instance with given difficulty
        dif = [
            "easy-boards.json",
            "medium-boards.json",
            "hard-boards.json"
        ]

        if isStart:
            # initialize the self.game variable if is the start of the game
            self.game = Board(board_path=f"./boards/{dif[difficulty - 1]}")
        else:
            # temporary var to grant that the game is a new one
            temp = Board(board_path=f"./boards/{dif[difficulty - 1]}")

            while (temp.board == self.game.board):
                temp = Board(board_path=f"./boards/{dif[difficulty - 1]}")
            self.game = temp

        self.solvedBoard = self.game.solveBoard()

        # copy the board to a new array to keep track of things
        self.originalBoard = np.zeros((9, 9), dtype=int).tolist()
        for i in range(9):
            for j in range(9):
                self.originalBoard[i][j] = self.game.board[i][j]

        # the board to keep track of the pencil numbers
        self.pencilBoard = np.zeros((9, 9), dtype=int).tolist()

        self.currentSelected = None

    def restartGame(self):
        """
        Restart the current game.
        """
        self.game.board = self.originalBoard

    def validateBoard(self):
        """
        Validates the current board.

        Returns:
            boolean: True if the game is valid, False if invalid.
        """

        filled = True
        # check if there are any spot still available
        for i in range(9):
            for j in range(9):
                if self.game.board[i][j] == 0:
                    filled = False

        if filled:
            for i in range(9):
                for j in range(9):
                    # if any of the game board's numbers is different from the solved board, return False
                    if self.solvedBoard[i][j] != self.game.board[i][j]:
                        return False
            # if didn't returned False, return True
            return True
        else:
            return None

    # INFO BOARD
    def drawNumsLeft(self):
        """
        Show to the player how many numbers are left to complete the board.

        Params:
            width (int): The width of the board for position.
        """

        resX = self.WIDTH / 9

        # to loop for every number from 1 to 9
        for i in range(1, 10):
            # to keep track of how many numbers currently exist in the board
            existing = 0
            for k in range(9):
                for j in range(9):
                    if self.game.board[k][j] == i:
                        existing += 1
            left = 9 - existing

            # texts
            numText = str(i)
            leftText = str(left)

            # background for each number
            circleX = int(resX / 2 + resX * (i - 1))
            circleY = 490

            if left == 0:
                pygame.draw.circle(
                    self.screen, pygame.Color("#30332E"), (circleX, circleY), 24)
            else:
                pygame.draw.circle(
                    self.screen, pygame.Color("#6B7367"), (circleX, circleY), 24)

            # CURRENT NUMBER
            # font
            numberFont = pygame.font.SysFont('arial', 26)
            x, y = numberFont.size(numText)

            number = numberFont.render(numText, True, pygame.Color("#EEFFE6"))

            xPos = int(((i - 1) * resX + resX / 2) - x / 2)
            yPos = circleY - 24

            self.screen.blit(number, (xPos, yPos))

            # LEFT NUMBER
            leftFont = pygame.font.SysFont('arial', 17)

            if left < 0:
                leftText = str(left * -1)
                x, y = leftFont.size(leftText)
                leftNumber = leftFont.render(
                    leftText, True, pygame.Color("#B33A34"))
            else:
                x, y = leftFont.size(leftText)
                leftNumber = leftFont.render(
                    leftText, True, pygame.Color("#B3BFAC"))

            xPos = int(((i - 1) * resX + resX / 2) - x / 2)
            yPos = circleY + 1

            self.screen.blit(leftNumber, (xPos, yPos))

    def refreshInfoBar(self):
        """
        Refresh info bar to draw the appropriate content.
        """
        pygame.draw.rect(self.screen, pygame.Color("#A7B3A1"), pygame.Rect(
            0, self.BOARD_HEIGHT, self.WIDTH, self.HEIGHT - self.BOARD_HEIGHT))

    def drawMenu(self):
        """
        Draw the difficulty menu.
        """

        # SET DIFFICULTIES
        buttonWidth = 60
        buttonHeight = 30

        chunk = int(self.WIDTH / 3)
        # easy button
        pos = (int((chunk / 2) * 1 - (buttonWidth / 2)), 470)
        self.easyButton = pygame_gui.elements.UIButton(relative_rect=pygame.Rect(pos, (buttonWidth, buttonHeight)),
                                                       text="Easy",
                                                       manager=self.manager,
                                                       starting_height=30)

        # normal button
        pos = (int((chunk / 2) * 3 - (buttonWidth / 2)), 470)
        self.normalButton = pygame_gui.elements.UIButton(relative_rect=pygame.Rect(pos, (buttonWidth, buttonHeight)),
                                                         text="Normal",
                                                         manager=self.manager,
                                                         starting_height=30)

        # hard button
        pos = (int((chunk / 2) * 5 - (buttonWidth / 2)), 470)
        self.hardButton = pygame_gui.elements.UIButton(relative_rect=pygame.Rect(pos, (buttonWidth, buttonHeight)),
                                                       text="Hard",
                                                       manager=self.manager,
                                                       starting_height=30)

    def killMenu(self):
        """
        Kill the difficulty menu.
        """

        self.easyButton.kill()
        self.easyButton.set_position((0, 1000))

        self.normalButton.kill()
        self.normalButton.set_position((0, 1000))

        self.hardButton.kill()
        self.hardButton.set_position((0, 1000))

    def run(self):
        menuIsActive = False

        while self.running:
            dt = self.clock.tick(30)/1000

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.running = False

                # handle mouse clicked
                if event.type == pygame.MOUSEBUTTONDOWN:
                    pos = pygame.mouse.get_pos()
                    x, y = pos
                    if x < self.BOARD_WIDTH and y < self.BOARD_HEIGHT:
                        self.selectCell(pos)

                # handle keys pressed
                if event.type == pygame.KEYDOWN:
                    if self.currentSelected is not None:
                        if event.key == pygame.K_BACKSPACE:
                            self.setNumber(0)
                        elif event.key == pygame.K_UP:
                            self.moveSelected("up")
                        elif event.key == pygame.K_DOWN:
                            self.moveSelected("down")
                        elif event.key == pygame.K_RIGHT:
                            self.moveSelected("right")
                        elif event.key == pygame.K_LEFT:
                            self.moveSelected("left")
                        else:
                            try:
                                if event.mod == pygame.KMOD_NONE:
                                    # set the number pressed
                                    self.setNumber(
                                        int(pygame.key.name(event.key)))
                                else:
                                    if event.mod & pygame.KMOD_LSHIFT:
                                        # set the number as drawn with a pencil
                                        self.pencilNumber(
                                            int(pygame.key.name(event.key)))
                            except Exception:
                                pass
                    else:
                        self.currentSelected = (0, 0)

                # handle UI elements
                if event.type == pygame.USEREVENT:
                    if event.user_type == pygame_gui.UI_BUTTON_PRESSED:
                        # MENU BUTTON
                        if event.ui_element == self.menuButton:
                            menuIsActive = not menuIsActive
                            self.killMenu()
                            self.refreshInfoBar()

                        # RESTART BUTTON
                        if event.ui_element == self.restartButton:
                            self.restartGame()

                        # EASY BUTTON
                        if event.ui_element == self.easyButton:
                            self.startGame(1)
                            self.killMenu()
                            self.refreshInfoBar()
                            menuIsActive = False
                        # NORMAL BUTTON
                        if event.ui_element == self.normalButton:
                            self.startGame(2)
                            self.killMenu()
                            self.refreshInfoBar()
                            menuIsActive = False
                        # HARD BUTTON
                        if event.ui_element == self.hardButton:
                            self.startGame(3)
                            self.killMenu()
                            self.refreshInfoBar()
                            menuIsActive = False

                self.manager.process_events(event)

            self.screen.blit(self.backgound, (0, 0))
            self.manager.draw_ui(self.screen)

            # GAME LOGIC
            isWon = self.validateBoard()
            if isWon is not None and isWon == True:
                # what happens when you win the game?
                print("WON!")

            # HIGHLIGHTS
            self.drawAllEqual()
            self.drawSelected()

            # GAME UI
            self.drawGrid()
            self.drawNumbers()

            # info bar
            if menuIsActive != True:
                self.menuButton.set_text("Menu")
                self.killMenu()

                self.drawNumsLeft()

                # temporary boolean to execute the drawMenu function just once
                tempBool = True
            else:
                if tempBool:
                    self.drawMenu()
                    tempBool = False

                    self.menuButton.set_text("Return")

            pygame.display.update()
            self.manager.update(dt)


if __name__ == "__main__":
    main = Main()
    main.run()
