from tkinter import *
from tkinter import font, filedialog

def saveDoc():
    global textarea
    text=textarea.get("1.0","end-1c")
    location=filedialog.asksaveasfilename()
    file=open(location,"w+")
    file.write(text)
    file.close()

def Algerian():
    global textarea
    textarea.config(font="Algerian")  

def Arial():
    global textarea
    textarea.config(font="Arial")  

def Courier():
    global textarea
    textarea.config(font="Courier")  

def Cambria():
    global textarea
    textarea.config(font="Cambria")

def boldDoc():
    global textarea
    textarea.config(font=('arial',14,'bold'))

root=Tk()
root.title("ProjectGurukul Text Editor Python")

savebtn=Button(root,command=saveDoc,text="Save")
savebtn.grid(row=1,column=0)
savebtn.config(font=('arial',20,'bold'),bg="DodgerBlue2",fg="white")

fontbtn=Menubutton(root,text="Font")
fontbtn.config(font=('arial',20,'bold'),bg="DodgerBlue2",fg="white")
fontbtn.grid(row=1,column=1)
fontbtn.menu=Menu(fontbtn,tearoff=0)
fontbtn["menu"]=fontbtn.menu

fontbtn.menu.add_checkbutton(label="Arial",
command=Arial)

fontbtn.menu.add_checkbutton(label="Algerian", 
command=Algerian)

fontbtn.menu.add_checkbutton(label="Cambria", 
command=Cambria)

fontbtn.menu.add_checkbutton(label="Courier",
command=Courier)

boldbtn=Button(root,command=boldDoc,text="Bold")
boldbtn.grid(row=1,column=2)
boldbtn.config(font=('arial',20,'bold'),bg="DodgerBlue2",fg="white")

textarea=Text(root)
textarea.grid(row=2,columnspan=5)

# To know or add more font options
# fonts=list(font.families())
# fonts.sort() 

mainloop()

