from tkinter import *
import math
# ---------------------------- CONSTANTS ------------------------------- #
PINK = "#e2979c"
RED = "#e7305b"
GREEN = "#9bdeac"
YELLOW = "#f7f5dd"
DARK_RED = "#DA0037"
DARK_GREEN = "#3A6351"
FONT_NAME = "Courier"
WORK_MIN = 25
SHORT_BREAK_MIN = 5
LONG_BREAK_MIN = 20
REPS = 0
watch_timer = None

# ---------------------------- TIMER RESET ------------------------------- #
def reset():
    global watch_timer
    window.after_cancel(watch_timer)
    canvas.itemconfig(timer, text="00:00")
    timer_label.config(text="Timer")
    check_label.config(text="")
    global REPS
    REPS = 0

# ---------------------------- TIMER MECHANISM ------------------------------- #
def start_timer():
    global REPS
    REPS += 1
    work_sec = WORK_MIN * 60
    long_break_sec = LONG_BREAK_MIN * 60
    short_break_sec = SHORT_BREAK_MIN * 60

    if REPS % 8 == 0:
        count_down(long_break_sec)
        timer_label.config(text="BREAK", fg=DARK_RED)

    elif REPS % 2 == 0:
        count_down(short_break_sec)
        timer_label.config(text="BREAK", fg=DARK_RED)
    else:
        count_down(work_sec)
        timer_label.config(text="WORK", fg=DARK_GREEN)

# ---------------------------- COUNTDOWN MECHANISM -------------------------------
def count_down(count):
    global watch_timer
    count_min = math.floor(count/60)
    count_sec = count % 60

    if count_sec < 10:
        count_sec = f"0{count_sec}"
    canvas.itemconfig(timer, text=f"{count_min}:{count_sec}")

    if count > 0:
        watch_timer = window.after(1000, count_down, count-1)

    else :
        start_timer()
        marks = ""
        work_session = math.floor(REPS/2)
        for _ in range(work_session):
            marks += "✔"
        check_label.config(text=marks)

# ---------------------------- UI SETUP ------------------------------- #
window = Tk()
window.title("POMODORO")
window.config(padx=100, pady=70, bg=PINK)

canvas = Canvas(width=202, height=224, bg=PINK)
canvas.config(highlightthickness=0)
timer = canvas.create_text(101, 120, text="00:00", font=(FONT_NAME, 35, "bold"), fill="white")
canvas.grid(column=2, row=1)

timer_label = Label(text="Timer", font=(FONT_NAME, 30, "bold"), bg=PINK, fg=GREEN)
timer_label.grid(column=2, row=0)

start = Button(text="Start", command=start_timer, bg=YELLOW)
start.config(highlightthickness=0)
start.grid(column=0, row=4)

reset = Button(text="Reset", bg=YELLOW, command=reset)
reset.config(highlightthickness=0)
reset.grid(column=3, row=4)

check_label = Label(fg=GREEN, bg=PINK, font=(25))
check_label.grid(column=2, row=6)

window.mainloop()