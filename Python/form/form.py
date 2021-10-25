from tkinter import *
root = Tk()
root.geometry("500x500")

def getvals():
    print("We got ur info...THANKS!")

Label(root,text="FORM",font="ar 20").grid(row=0, column=3)

name=Label(root,text="Name")
phone=Label(root,text="Phone number")
reg_no=Label(root,text="Registration number")

name.grid(row=2,column=2)
phone.grid(row=3,column=2)
reg_no.grid(row=4,column=2)

namevalue = StringVar
phonevalue = StringVar
reg_novalue = StringVar
checkvalue = IntVar

nameentry = Entry(root, textvariable=namevalue)
phoneentry = Entry(root, textvariable=phonevalue)
reg_noentry = Entry(root, textvariable=reg_novalue)

nameentry.grid(row=2,column=3)
phoneentry.grid(row=3,column=3)
reg_noentry.grid(row=4,column=3)

button = Checkbutton(text="keep me logged in",variable=checkvalue)
button.grid(row=6,column=3)
Button(text="Submit",command=getvals).grid(row=7,column=3)

root.mainloop()
