# Importing all the necessary libraries to form the alarm clock:
from tkinter import *
import datetime
import time
import winsound


# Create a while loop
def alarm(set_alarm_timer):
    while True:
        time.sleep(1)
        current_time = datetime.datetime.now()
        now = current_time.strftime("%H:%M:%S")
        date = current_time.strftime("%d/%m/%Y")
        print("The Set Date is:", date)
        print(now)
        if now == set_alarm_timer:
            print("Time to Wake up")
            winsound.PlaySound("sound.wav", winsound.SND_ASYNC)
            break


def actual_time():
    set_alarm_timer = f"{hour.get()}:{mini.get()}:{sec.get()}"
    alarm(set_alarm_timer)


# Creating GUI using tkinter
clock = Tk()

clock.title("Yashita's Alarm Clock")
clock.geometry("300x200")
time_format = Label(clock, text="Enter time in 24 hour format!", fg="red", bg="black", font="Arial").place(x=50, y=120)
addTime = Label(clock, text=" Hour   Min     Sec", font=("Times New Roman", 10, "bold")).place(x=110)
setYourAlarm = Label(clock, text="When to wake you up", fg="black", relief="solid", font=("Helevetica", 7, "bold")).place(x=1, y=29)

# The Variables we require to set the alarm(initialization):
hour = StringVar()
mini = StringVar()
sec = StringVar()

# Time required to set the alarm clock:
hourTime = Entry(clock, textvariable=hour, bg="blue", fg="white", width=4, font=("Courier New", 8, "bold")).place(x=110, y=30)
minTime = Entry(clock, textvariable=mini, bg="blue", fg="white", width=4, font=("Courier New", 8, "bold")).place(x=150, y=30)
secTime = Entry(clock, textvariable=sec, bg="blue", fg="white", width=4, font=("Courier New", 8, "bold")).place(x=190, y=30)

# To take the time input by user:
submit = Button(clock, text="Set Alarm", fg="red", width=10, command=actual_time).place(x=110, y=70)

# Execution of the window
clock.mainloop()
