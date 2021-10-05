from score import Score
from car import Car
from player import Player
from turtle import Screen, textinput
import time
screen = Screen()
def play():    
    screen.clearscreen()
    screen.setup(width=600, height=600)
    screen.title("CROSS_THE_ROAD...")
    screen.bgcolor("black")
    screen.tracer(0)


    player = Player()
    car = Car()
    car.make_road()
    score = Score()

    screen.listen()
    screen.onkey(player.move, "Up")
    playing = True

    while playing:
        screen.update()
        time.sleep(0.1)

        car.create_cars()

        car.move()

        for cars in car.all_cars:
            if cars.distance(player) < 23:
                score.loose()
                playing = False
                ask()

        if player.ycor() >= 270:
            score.win()
            playing = False
            ask()

    screen.exitonclick()
def ask():
    user = textinput(title="let's play!!", prompt="you wanna play 'y' or 'n' : ").lower()
    if user == "y":
        play()
    elif user == "n":
        print("alright! see you soon.")
        screen.bye()
        
    else:
        print("please enter a valid input.")
        screen.bye()

ask()
