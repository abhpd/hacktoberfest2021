import random

import pygame
from pygame import mixer

pygame.init()
# Set the Height and Width of Your Game Window and Playing Area
w_width = 800
w_height = 700
play_width = 300  
play_height = 600 
#Box Size is the size of each box in the playing grid
block_size = 30
score = 0
top_left_x = (w_width - play_width) // 2
top_left_y = w_height - play_height
mixer.music.load("Circles.mp3")
print("Made with ❤ and ☕ by Achal Jhawar")
print("The Instructions are as folows:")
print("1. You can use the ⬅️⬆️➡️⬇ arrow keys to rotate the peices.")
print("2. You have to complete the lines of the grid to get points.")
print("3. If you cannnot fit the pieces in the grid you lose.")
print("4. For every line you complete you get 10 points")
# SHAPE FORMATS

S = [['.....',
     '.....',
     '..00.',
     '.00..',
     '.....'],
    ['.....',
     '..0..',
     '..00.',
     '...0.',
     '.....']]

Z = [['.....',
     '.....',
     '.00..',
     '..00.',
     '.....'],
    ['.....',
     '..0..',
     '.00..',
     '.0...',
     '.....']]

I = [['..0..',
     '..0..',
     '..0..',
     '..0..',
     '.....'],
    ['.....',
     '0000.',
     '.....',
     '.....',
     '.....']]

O = [['.....',
     '.....',
     '.00..',
     '.00..',
     '.....']]

J = [['.....',
     '.0...',
     '.000.',
     '.....',
     '.....'],
    ['.....',
     '..00.',
     '..0..',
     '..0..',
     '.....'],
    ['.....',
     '.....',
     '.000.',
     '...0.',
     '.....'],
    ['.....',
     '..0..',
     '..0..',
     '.00..',
     '.....']]

L = [['.....',
     '...0.',
     '.000.',
     '.....',
     '.....'],
    ['.....',
     '..0..',
     '..0..',
     '..00.',
     '.....'],
    ['.....',
     '.....',
     '.000.',
     '.0...',
     '.....'],
    ['.....',
     '.00..',
     '..0..',
     '..0..',
     '.....']]

T = [['.....',
     '..0..',
     '.000.',
     '.....',
     '.....'],
    ['.....',
     '..0..',
     '..00.',
     '..0..',
     '.....'],
    ['.....',
     '.....',
     '.000.',
     '..0..',
     '.....'],
    ['.....',
     '..0..',
     '.00..',
     '..0..',
     '.....']]

shapes = [S, Z, I, O, J, L, T]
shape_colors = [(0, 255, 0), (255, 0, 0), (0, 255, 255), (255, 255, 0), (255, 165, 0), (0, 0, 255), (128, 0, 128)]
bg = pygame.image.load("image.jpg")
class Piece:
	# Number of columns
	x = 10
	# Number of rows
	y = 20
	# Shape of piece
	shape = 0
	# Color of shape
	color = ()
	# Rotation of shape
	rotation = 0

	# This is a constructor
	def __init__(self, column, row, shape):
		# The values in parameters are assigned to the new object of type 'Piece'
		self.x = column
		self.y = row
		self.shape = shape
		self.color = shape_colors[shapes.index(shape)]
		self.rotation = 0

def draw_text_middle(text, size, color, surface):
	# Which font do you want to use?
	font = pygame.font.SysFont('comicsans', size, bold=True)
	# Render the Text using font
	label = font.render(text, 1, color)
	# Print the Text using label
	surface.blit(label, (top_left_x + play_width/2 - (label.get_width() / 2), top_left_y + play_height/2 - label.get_height()/2))

def create_grid(locked_positions={}):
	# Create a 10*20 matrix initialized with (0,0,0)
	grid = [[ (0,0,0) for x in range(10)] for y in range(20) ]
	# Color the grid where the blocks are occupied already
	for i in range(len(grid)):
		for j in range(len(grid[i])):
			if (j,i) in locked_positions:
				c = locked_positions[(j,i)]
				grid[i][j] = c
	return grid

def check_lost(positions):
	# Traverse through the locked positions
	for pos in positions:
		x, y = pos
		# If block crosses the above boundary of grid
		if y < 1:
			return True
	return False

def get_shape():
	# Make a new object of type Piece
	newPiece = Piece(5, 0, random.choice(shapes))
	return newPiece

def convert_shape_format(piece):
	positions = []
	format = piece.shape[piece.rotation % len(piece.shape)]

	i = 0
	for line in format:
		row = list(line)

		j = 0
		for column in row:
			if column=='0':
				positions.append((piece.x + j, piece.y + i))
			j+=1
		i+=1
	return positions

def valid_space(piece, grid):
	# Matrix of all positions which are not currently occupied
	accepted_positions = [[(j, i) for j in range(10) if grid[i][j] == (0,0,0)] for i in range(20)]
	# Narrow down the matrix for easier handling
	accepted_positions = [j for sub in accepted_positions for j in sub]
	# convert_shape_format returns a list of strings of the current shape in its correct orientation
	formatted = convert_shape_format(piece)

	for pos in formatted:
		if pos not in accepted_positions:
			if pos[1] > -1:
				return False
	return True

def update_score(surface):
	# Same as draw_text_middle, except that we decide the position to print
	text = "Score : " + str(score)
	font = pygame.font.SysFont('comicsans', 40)
	label = font.render(text, 1, (255,255,255))

	sx = top_left_x + play_width + 40
	sy = top_left_y + play_height/2 - 100

	surface.blit(label, (sx + 10, sy+ 150))


def draw_next_shape(piece, surface):
	# Decide the font and render it, print it
	font = pygame.font.SysFont('comicsans', 30)
	label = font.render('Next Shape', 1, (255,255,255))
	# Where to display the next piece? These are the coordinates
	sx = top_left_x + play_width + 50
	sy = top_left_y + play_height/2 - 100
	# List of strings depicting the orientation of piece
	format = piece.shape[piece.rotation % len(piece.shape)]
	# Traverse through the list
	i = 0
	for line in format:
		row = list(line)
		j = 0
		# Traverse through each string
		for column in row:
			if column == '0':
				# Draw the next_piece
				pygame.draw.rect(surface, piece.color, (sx + j*30, sy + i*30, 30, 30), 0)
			j+=1
		i+=1
	surface.blit(label, (sx + 10, sy- 30))
	update_score(surface)

def draw_grid(surface, row, col):
	sx = top_left_x
	sy = top_left_y

	for i in range(row):
		# Draw Horizontal Lines
		pygame.draw.line(surface, (128, 128, 128), (sx, sy+i*30), (sx + play_width, sy + i*30))

		for j in range(col):
			# Draw Vertical Lines
			pygame.draw.line(surface, (128, 128, 128), (sx + j*30, sy), (sx +j*30, sy + play_height))


def draw_window(surface):
	surface.fill((0, 0, 0))
	window.blit(bg,(0,0))
	font = pygame.font.SysFont('comicsans', 60)
	label = font.render('TETRIS', 1 , (255, 255, 255))
	surface.blit(label, (top_left_x + play_width / 2 - (label.get_width() / 2), 30))

	for i in range( len(grid) ):
		for j in range( len(grid[i] )):
			pygame.draw.rect(surface, grid[i][j], (top_left_x + j*30, top_left_y + i*30, block_size, block_size), 0) 

	draw_grid(surface, 20, 10)
	pygame.draw.rect(surface, (255, 0, 0), (top_left_x, top_left_y, play_width, play_height), 5)

def clear_rows(grid, locked):
	# We store the number of rows to shift down in inc
	inc = 0
	global score
	# Traverse the grid in reverse direction
	for i in range(len(grid)-1, -1, -1):
		row = grid[i]
		# Check if there is any empty position(block) in this row
		if (0, 0, 0) not in row:
			inc +=1
			# Clear this row, save the index into ind
			ind = i
			for j in range(len(row)):
				try:
					del locked[ (j, i) ]
				except:
					continue
	#Shift the remaining rows downward by inc number of rows
	if inc>0:
		# Sort the locked position, store into temp
		temp = sorted(list(locked), key=lambda x: x[1])
		# Traverse temp in reverse direction
		for key in temp[::-1]:
			x, y = key
			# If the y coordinate of this position is less than ind
			if y < ind:
				# Update the y coordinate
				newKey = (x, y+inc)
				# Remove the previous locked position from the list
				locked[newKey] = locked.pop(key)

		score += inc*10


def play():
	# A global variable grid
	global grid
	# The positions already occupied with blocks
	locked_positions = {}
	# Create the Grid
	grid = create_grid(locked_positions)

	# change_piece turns true when the next piece is to be released
	change_piece = False
	# run remains True unless the user decides to quit
	run = True
	# current_piece holds the current piece falling in the grid
	current_piece = get_shape()
	# next_piece holds the piece that would fall once the current one sets down
	next_piece = get_shape()
	# clock is used to keep a track of time for the falling piece
	clock = pygame.time.Clock()
	# This keeps a track of the time to automatically move
	# current_piece one position down in vertical direction
	fall_time = 0
	mixer.music.play()


	while run:
		# Decide the falling speed
		fall_speed = 0.27
		# An updated grid is created each time 
		grid = create_grid(locked_positions)
		# update the fall_time
		fall_time += clock.get_rawtime()
		# Move the clock ahead
		clock.tick()
		# This block decides when to move the piece down
		# vertically by one position
		if fall_time/1000 >= fall_speed:
			fall_time = 0
			current_piece.y += 1
			# Check if the piece touches the ground oe existing stack
			if not (valid_space(current_piece, grid)) and current_piece.y > 0:
				current_piece.y -= 1
				change_piece = True

		for event in pygame.event.get():
			# Check if user clicks on CROSS button to QUIT
			if event.type == pygame.QUIT:
				run = False
				# Simply quit the game window
				pygame.display.quit()
				# Exit the game now
				quit()

			# Check if any key is pressed
			if event.type == pygame.KEYDOWN:
				# Check if the key is left arrow key
				if event.key == pygame.K_LEFT:
					# Update coordinate
					current_piece.x -= 1
					# If lies outside valid space
					if not valid_space(current_piece, grid):
						# Revert the changes to coordinate
						current_piece.x += 1
				# Check if the key is right arrow key
				elif event.key == pygame.K_RIGHT:
					# Update coordinate
					current_piece.x += 1
					# If lies outside valid space
					if not valid_space(current_piece, grid):
						# Revert the changes to coordinate
						current_piece.x-= 1
				# Check if the key is down arrow key
				elif event.key == pygame.K_DOWN:
					# Update coordinate
					current_piece.y += 1
					# If lies outside valid space
					if not valid_space(current_piece, grid):
						# Revert the changes to coordinate
						current_piece.y -= 1
				# Check if the key is up arrow key
				elif event.key == pygame.K_UP:
					# Update the rotation
					current_piece.rotation = current_piece.rotation + 1 % len(current_piece.shape)
					# If lies outside valid space after rotation
					if not valid_space(current_piece, grid):
						# Revert the changes to the rotation
						current_piece.rotation = current_piece.rotation - 1 % len(current_piece.shape)

		# Get the piece coordinates according to position in grid and rotation
		shape_pos = convert_shape_format(current_piece)

		# Color the grid with new piece
		for i in range( len(shape_pos) ):
			x, y = shape_pos[i]
			if y > -1:
				grid[y][x] = current_piece.color

		# Change piece if previous one hits the ground
		if change_piece:
			for pos in shape_pos:
				p = (pos[0], pos[1])
				locked_positions[p] = current_piece.color

			current_piece = next_piece
			next_piece = get_shape()
			change_piece = False

			clear_rows( grid, locked_positions )

		# Draw the window and grid
		draw_window(window)
		# Draw the shape
		draw_next_shape(next_piece, window)
		# Update the screen
		pygame.display.update()
		# Check if no space on grid
		if check_lost(locked_positions):
			run = False

	# You will reach here only if user loses. i.e. run = False
	# Write the text in middle
	window.fill((0,0,0))
	draw_text_middle("You Lost", 80, (255,255,255), window)
	# Update the screen
	pygame.display.update()
	pygame.time.delay(2000)




def game():
	run = True
	# Our game runs until 'run' is made 'False'
	while run:
		# Fill the window with Black Colour (RGB Value)
		window.fill((0,0,0))
		window.blit(bg,(0,0))
		# Display this text in the middle of the window
		draw_text_middle("Press any key to begin!", 60, (255, 255, 255), window)
		# Update the screen
		pygame.display.update()
		# Track every event while the game is running
		for event in pygame.event.get():
			# If user clicks on the 'cross' to quit, make run = False
			if event.type == pygame.QUIT:
				run = False

			if event.type == pygame.KEYDOWN:
				play()

	pygame.quit()

# Make the Window with pygame.display
# Set its height and width to w_height and w_width using set_mode
window = pygame.display.set_mode((w_width, w_height))
# Change the title of the window using set_caption
pygame.display.set_caption("Tetris")

# Start the game
game()
