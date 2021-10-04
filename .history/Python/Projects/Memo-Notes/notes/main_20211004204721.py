import tkinter as tk


def cli():
    import time
    current_time = time.strftime("%H:%M")
    # gets the current time.
    print("Welcome to Noty.You can now create sticky notes, easily.")
    time.sleep(2)
    note_input = input("Type your notes here: ")
    note = ("*%s") % note_input
    time.sleep(1)
    # time.sleep prevents GUI from popping up before it receives input.
    root = tk.Tk()
    root.title("Noty")
    root.geometry("300x300")
    # changes the width and height of the GUI.
    tk.Label(root, text=current_time).pack()
    # prints the current time.
    tk.Label(root, text=note).pack()
    # prints the input.
    root.mainloop()
    # keeps showing the note, until the user closes it.
