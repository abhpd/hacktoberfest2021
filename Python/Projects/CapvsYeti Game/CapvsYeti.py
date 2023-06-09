import pygame
import random
import math
import time
from pygame import mixer

# Initialize pygame
pygame.init()

# create the screen
screen = pygame.display.set_mode((800,600))

# Background
background = pygame.image.load('background.jpg')


#background sound
mixer.music.load('background.mp3')
mixer.music.play(-1)
# Title and Icon
pygame.display.set_caption("Cap vs Yeti")
icon = pygame.image.load('title.png')
pygame.display.set_icon(icon)

#Player
playerImg = pygame.image.load('superhero.png')
playerX = 120
playerY = 480
playerX_change = 0
playerY_change = 20
#Enemy
enemyImg = []
enemyX = []
enemyY = []
enemyX_change = []
enemyY_change = []
num_of_enemies = 6
for i in range(num_of_enemies):
    enemyImg.append(pygame.image.load('yeti.png'))
    enemyX.append(random.randint(0,736))
    enemyY.append(random.randint(20,120))
    enemyX_change.append(0.5)
    enemyY_change.append(40)

#Bullet
# Ready - You cant see the bullet on the screen
# Fire - The bullet is currently moving
bulletImg = pygame.image.load('shield.png')
bulletX = 0
bulletY = 480
bulletX_change = 0
bulletY_change = 1.5
bullet_state = "ready"

# Score

score_value = 0
font = pygame.font.Font('ScarletJosephine.ttf',42)

textX = 15
textY = 15
def explosion(x,y):
    explosion_Img = pygame.image.load('blast.png')
    screen.blit(explosion_Img,(x,y))
    pygame.display.update()
    time.sleep(0.03)
def show_score(x,y):
    score = font.render("Score : " + str(score_value),True, (255,255,255))
    screen.blit(score, (x,y))

def player(x,y):
    screen.blit(playerImg,(x,y))

def enemy(x,y,i):
    screen.blit(enemyImg[i],(x,y))    

def fire_bullet(x,y):
    global bullet_state
    bullet_state = "fire"
    screen.blit(bulletImg,(x+16,y+10))


def isCollision(enemyX,enemyY,bulletX,bulletY):
    distance = math.sqrt((math.pow(enemyX-bulletX,2)) +(math.pow(enemyY-bulletY,2)))
    if distance <= 27:
        return True
    else:
        return False
# Game Loop
running = True
while running:
    screen.fill((0,0,50))
    #Background Image
    screen.blit(background,(0,0))
    for events in pygame.event.get():
        if events.type == pygame.QUIT:
            running = False
        if events.type == pygame.KEYDOWN:
            if events.key == pygame.K_LEFT:
                playerX_change = -0.75
            if events.key == pygame.K_RIGHT:
                playerX_change = 0.75
            if events.key == pygame.K_SPACE:
                if bullet_state is "ready":
                    bullet_sound = mixer.Sound('laser.wav')
                    bullet_sound.play()
                    bulletX = playerX
                    bulletY = playerY
                    fire_bullet(bulletX,bulletY)
        if events.type == pygame.KEYUP:
            if events.key == pygame.K_LEFT or events.key == pygame.K_RIGHT:
                playerX_change = 0     
    playerX += playerX_change   
    if playerX <= 0:
        playerX = 0
    elif playerX >= 736:
        playerX = 736  
    # Enemy Movement
    for i in range(num_of_enemies):
        enemyX[i] += enemyX_change[i]  
        if enemyX[i] <= 0:
            enemyX_change[i] = 0.5
            enemyY[i] += enemyY_change[i]
        elif enemyX[i] >= 736:
            enemyX_change[i] = -0.5
            enemyY[i] += enemyY_change[i]
        # Collision
        collision = isCollision(enemyX[i],enemyY[i],bulletX,bulletY)
        if collision:
            bulletY = 480
            bullet_state = "ready"
            score_value += 1
            explosion(enemyX[i],enemyY[i])
            enemyX[i] = random.randint(0,736)
            enemyY[i] = random.randint(50,150)
            explosion_sound = mixer.Sound('explosion.wav')
            explosion_sound.play()
        #   playerY -= playerY_change
        #   enemyX_change += 0.05
        enemy(enemyX[i],enemyY[i],i)
    # Bullet movement
    if bulletY <= 0:
        bulletY = playerY
        bullet_state = "ready"
    if bullet_state is "fire":
        fire_bullet(bulletX,bulletY)
        bulletY -= bulletY_change
    player(playerX,playerY)
    show_score(textX,textY)
    pygame.display.update()        

