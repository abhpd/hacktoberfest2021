import turtle
import random
import os
wn = turtle.Screen()
wn.title("Pong")
wn.bgpic('images/pong.png')
wn.setup(960, 720)
wn.tracer(0)

# blue color paddle
paddle_a = turtle.Turtle()
paddle_a.speed(0)
paddle_a.shape('square')
paddle_a.color('red')
paddle_a.shapesize(stretch_wid=5, stretch_len=1)
paddle_a.penup()
paddle_a.goto(435, 280)

# red color paddle
paddle_b = turtle.Turtle()
paddle_b.speed(0)
paddle_b.shape('square')
paddle_b.color('blue')
paddle_b.shapesize(stretch_wid=5, stretch_len=1)
paddle_b.penup()
paddle_b.goto(-437, -280)

# ball
ball = turtle.Turtle()
ball.speed(0)
ball.shape('circle')
ball.color('green')
ball.penup()
ball.goto(0, 0)
ball.dx = 0.2
ball.dy = 0.2


#scoreboard :-
pen = turtle.Turtle()
pen.speed(0)
pen.color('orange')
pen.penup()
pen.hideturtle()
pen.goto(0,320)
pen.write("Player A : 0    Player B : 0", align='center', font=("Arial Black", 20, 'normal'))


def paddle_a_move():
    y = paddle_a.ycor()
    paddle_a.sety(y + 20)


def paddle_a_moved():
    y = paddle_a.ycor()
    paddle_a.sety(y - 20)


def paddle_b_move():
    y = paddle_b.ycor()
    paddle_b.sety(y + 20)


def paddle_b_moved():
    y = paddle_b.ycor()
    paddle_b.sety(y - 20)


wn.listen()
wn.onkeypress(paddle_a_move, 'w')
wn.onkeypress(paddle_a_moved, 's')
wn.onkeypress(paddle_b_moved, 'Down')
wn.onkeypress(paddle_b_move, 'Up')
p1 = 0
p2 = 0
while True:
    wn.update()

    ball.setx(ball.xcor() + ball.dx)
    ball.sety(ball.ycor() + ball.dy)

    if ball.ycor() >= 320 or ball.ycor() <= -345:
        ball.dy = ball.dy * -1

    if (415 < ball.xcor() < 425) and (paddle_a.ycor() + 40 > ball.ycor() > paddle_a.ycor() - 40):
        ball.setx(415)
        os.system('audio/pong.wav')
        ball.color('blue')
        ball.dx = ball.dx * -1
        print(ball.xcor())

    if (-415 > ball.xcor() > -425) and (paddle_b.ycor() + 40 > ball.ycor() > paddle_b.ycor() - 40):
        ball.setx(-415)
        os.system('audio/pong.wav')
        ball.color('red')
        ball.dx = ball.dx * -1
        print(ball.xcor())

    if ball.xcor() > 440:
        p1 = p1 +1
        pen.clear()
        pen.write("Player A : {}    Player B : {}".format(p1,p2), align='center', font=("Arial Black", 20, 'normal'))
        ball.color('green')
        ball.goto(0, 0)
        ball.dx = ball.dx * random.choice([-1, 1])

    if ball.xcor() < -440:
        p2 = p2 + 1
        pen.clear()
        pen.write("Player A : {}    Player B : {}".format(p1, p2), align='center', font=("Arial Black", 20, 'normal'))
        ball.color('green')
        ball.goto(0, 0)
        ball.dx = ball.dx * random.choice([-1, 1])
