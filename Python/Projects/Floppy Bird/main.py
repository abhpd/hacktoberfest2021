import time
import pygame
import random
import os

pygame.init()
pygame.mixer.init()

# Required Game Variables
FPS = 35
FPS_CLOCK = pygame.time.Clock()
SCREEN_WIDTH = 289
SCREEN_HEIGHT = 511
SCREEN = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

# Game Specific Variables
SPRITES = {}
AUDIO = {}
with open("high_score.txt") as scores:
    HIGH_SCORE = int(scores.read())


def init_resources():
    # initializing SPRITES
    numbers = [
        pygame.image.load("gallery/sprites/0.png").convert_alpha(),
        pygame.image.load("gallery/sprites/1.png").convert_alpha(),
        pygame.image.load("gallery/sprites/2.png").convert_alpha(),
        pygame.image.load("gallery/sprites/3.png").convert_alpha(),
        pygame.image.load("gallery/sprites/4.png").convert_alpha(),
        pygame.image.load("gallery/sprites/5.png").convert_alpha(),
        pygame.image.load("gallery/sprites/6.png").convert_alpha(),
        pygame.image.load("gallery/sprites/7.png").convert_alpha(),
        pygame.image.load("gallery/sprites/8.png").convert_alpha(),
        pygame.image.load("gallery/sprites/9.png").convert_alpha()
    ]
    SPRITES['numbers'] = numbers

    SPRITES['background'] = pygame.image.load("gallery/sprites/background.png")
    SPRITES['ground'] = pygame.image.load("gallery/sprites/base.png")
    SPRITES['bird'] = pygame.image.load("gallery/sprites/bird.png")
    SPRITES['message'] = pygame.image.load("gallery/sprites/message.png")

    pipe = pygame.image.load("gallery/sprites/pipe.png").convert_alpha()
    SPRITES['pipe_inverted'] = pygame.transform.rotate(pipe, 180)
    SPRITES['pipe_erect'] = pipe

    # initializing AUDIO
    AUDIO['die'] = pygame.mixer.Sound('gallery/audio/die.wav')
    AUDIO['hit'] = pygame.mixer.Sound('gallery/audio/hit.wav')
    AUDIO['point'] = pygame.mixer.Sound('gallery/audio/point.wav')
    AUDIO['swoosh'] = pygame.mixer.Sound('gallery/audio/swoosh.wav')
    AUDIO['wing'] = pygame.mixer.Sound('gallery/audio/wing.wav')


    if not os.path.exists("high_score.txt"):
        with open("high_score.txt", "w") as scores:
            scores.write("0")


def welcomeScreen():
    """
    Displays the welcome screen till the user presses space bar
    """
    messageX = (SCREEN_WIDTH - SPRITES['message'].get_width()) / 2
    messageY = SCREEN_HEIGHT * 0.08
    birdX = SCREEN_WIDTH * 0.2
    birdY = (SCREEN_HEIGHT - SPRITES['bird'].get_height()) / 2
    groundX = 0
    groundY = SCREEN_HEIGHT - SPRITES['ground'].get_height()

    while 1:
        SCREEN.blit(SPRITES['background'], (0, 0))
        SCREEN.blit(SPRITES['message'], (messageX, messageY))
        SCREEN.blit(SPRITES['bird'], (birdX, birdY))
        SCREEN.blit(SPRITES['ground'], (groundX, groundY))
        blitScore(HIGH_SCORE, Y=SCREEN_HEIGHT * 0.2)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                exit()
            elif event.type == pygame.KEYDOWN:
                mainGame()
        pygame.display.update()
        FPS_CLOCK.tick(FPS)


# Main game logic begins here
def get2RandomPipeY():
    """
    Generates Y coordinate of 2 random pipes
    (1 inverted and 1 erect)
    :return: list of y coordinates
    """
    gap = minPipeLen = int(SCREEN_HEIGHT * 0.3)
    pipe_invertedY = minPipeLen + random.randint(0, SPRITES['pipe_inverted'].get_height() - minPipeLen)
    pipe_erectY = (SPRITES['pipe_inverted'].get_height() - pipe_invertedY) + gap

    pipes = [-pipe_invertedY, pipe_erectY]
    return pipes


def isCollided(birdX, birdY, upper_pipes, lower_pipes, groundY):
    """
    Checks if the bird has collided with either of the pipes or has touched the top or the ground
    :param birdX: current x coordinate of the bird
    :param birdY: current y coordinate of the bird
    :param upper_pipes: 2 upper pipe coordinates(list of dict)
    :param lower_pipes: 2 lower pipe coordinates(list of dict)
    :param groundY: Y coordinate of the ground base image
    :return: True if the bird has collided otherwise false
    """
    birdHeight = SPRITES['bird'].get_height()
    # Getting the lower left coordinate instead of upper left coordinate
    if birdY + birdHeight > groundY or birdY < 0:  # if the player touches the top of the screen or falls on the ground
        return True

    for u_pipe, l_pipe in zip(upper_pipes, lower_pipes):
        # Both pipes have same dimensions
        pipeHeight = SPRITES['pipe_inverted'].get_height()
        pipeWidth = SPRITES['pipe_inverted'].get_width()

        if (birdY < u_pipe['y'] + pipeHeight) and (abs(birdX - u_pipe['x']) < pipeWidth):
            return True

        # As the birdY is measure from top left corner
        if (birdY + SPRITES['bird'].get_height() > l_pipe['y']) and (abs(birdX - l_pipe['x']) < pipeWidth):
            return True

    return False


def maintainScore(currentScore):
    """
    Maintains all the scoring after comparison with the high-score
    :param currentScore: current score of the player
    """
    global HIGH_SCORE
    if currentScore > HIGH_SCORE:
        with open("high_score.txt", "w") as score:
            score.write(str(currentScore))
            HIGH_SCORE = currentScore


def blitScore(num, Y):
    """
    Blits the score in the center of screen
    :param Y: y coordinate of the score to blit
    :param num: the number to blit on the screen
    :return:
    """
    # getting the width of the whole score
    score_width = 0
    score_digits = [int(i) for i in str(num)]
    for digit in score_digits:
        digitSprite = SPRITES['numbers'][digit]
        score_width += digitSprite.get_width()

    digitX = (SCREEN_WIDTH - score_width) / 2  # in the center
    for digit in score_digits:
        spriteToBlit = SPRITES['numbers'][digit]
        SCREEN.blit(spriteToBlit, (digitX, Y))
        digitX += spriteToBlit.get_width()


def mainGame():
    score = 0
    birdX = SCREEN_WIDTH / 5
    birdY = SCREEN_HEIGHT / 2
    groundX = 0
    groundY = SCREEN_HEIGHT - SPRITES['ground'].get_height()

    # All bird movements along y axis only
    birdVelY = -9
    birdMaxVelY = 10
    birdMinVelY = -8
    birdAccY = 1  # to make it fall downwards continuously

    birdFlappedVelY = -8
    birdFlapped = False

    # All pipe velocities along x axis only
    pipeVelX = -4
    randPipe1 = get2RandomPipeY()
    randPipe2 = get2RandomPipeY()
    upper_pipes = [
        {'x': SCREEN_WIDTH + 200, 'y': randPipe1[0]},
        {'x': SCREEN_WIDTH + 200 + (SCREEN_WIDTH / 2), 'y': randPipe2[0]}
    ]
    lower_pipes = [
        {'x': SCREEN_WIDTH + 200, 'y': randPipe1[1]},
        {'x': SCREEN_WIDTH + 200 + (SCREEN_WIDTH / 2), 'y': randPipe2[1]}
    ]

    while 1:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    if birdY > 0:
                        birdVelY = birdFlappedVelY
                        birdFlapped = True
                        AUDIO['wing'].play()

        crashTest = isCollided(birdX, birdY, upper_pipes, lower_pipes, groundY)

        if crashTest:
            AUDIO['hit'].play()
            time.sleep(0.25)
            welcomeScreen()  # end the game because player has collided

        # Calculating the score:

        birdMidPos = (birdX + SPRITES['bird'].get_width()) / 2
        # Mid positions are along the X-axis only
        for pipe in upper_pipes:
            pipeMidPos = (pipe['x'] + SPRITES['pipe_inverted'].get_width()) / 2
            # if the mid pos of player passes the mid pos of any of the pipe, then he gets a score The score might be
            # blitted multiple times if the bird hasn't crossed the upper limit and loop was fast enough to once
            # again execute the score incrementation
            if pipeMidPos <= birdMidPos < pipeMidPos + 2:  # approximation
                score += 1
                maintainScore(score)
                AUDIO['point'].play()

        # Now moving the bird:
        if birdVelY < birdMaxVelY and not birdFlapped:  # in case no flapping is there so push the bird down
            birdVelY += birdAccY

        if birdFlapped:
            birdFlapped = False
        # Don't decrease bird velocity if it is already on the ground
        if (birdY + SPRITES['bird'].get_height()) < groundY:
            birdY += birdVelY

        # Moving pipes to the left:

        # both upper_pipe and lower_pipe is a dictionary
        for upper_pipe, lower_pipe in zip(upper_pipes, lower_pipes):
            upper_pipe['x'] += pipeVelX
            lower_pipe['x'] += pipeVelX

        # Adding a new pipe when the first pipe is about to cross the left:
        if 0 < upper_pipes[0]['x'] < 5:
            newPipe = get2RandomPipeY()
            upper_pipes.append({'x': SCREEN_WIDTH, 'y': newPipe[0]})
            lower_pipes.append({'x': SCREEN_WIDTH, 'y': newPipe[1]})

        # If the pipe goes out of the screen, remove it:
        if upper_pipes[0]['x'] < -SPRITES['pipe_inverted'].get_width():
            upper_pipes.pop(0)
            lower_pipes.pop(0)

        # BLITTING EVERYTHING:
        SCREEN.blit(SPRITES['background'], (0, 0))
        for upper_pipe, lower_pipe in zip(upper_pipes, lower_pipes):
            SCREEN.blit(SPRITES['pipe_inverted'], (upper_pipe['x'], upper_pipe['y']))
            SCREEN.blit(SPRITES['pipe_erect'], (lower_pipe['x'], lower_pipe['y']))
        SCREEN.blit(SPRITES['ground'], (groundX, groundY))
        SCREEN.blit(SPRITES['bird'], (birdX, birdY))
        blitScore(score, Y = SCREEN_HEIGHT * 0.1)
        pygame.display.update()
        FPS_CLOCK.tick(FPS)


if __name__ == '__main__':
    init_resources()
    welcomeScreen()
