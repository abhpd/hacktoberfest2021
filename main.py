from forex_python.converter import CurrencyRates,CurrencyCodes
from tkinter import *
FONT=("Arial",15,"bold")
from currency import options,opt2
c= CurrencyRates() #create obj of Currencyrates 
cc=CurrencyCodes()
def getamt():
    amount=float(val_entry.get())
    fr=menu.get()
    to=menu2.get()
    con=c.convert(fr,to,amount)
    con=round(con,2)
    ans.config(text=str(con))
def getdesc():
    symb=symbol.get().upper()
    desc.config(text=cc.get_currency_name(symb))



############## Creation of tkinter window ###################
window = Tk()
window_title = window.title("currency_exchange")
window.minsize(1000,400)
window.config(padx=10,pady=10,background="#8236CB")
############### ************************** ################## 

  
canvas=Canvas(height=180,width=300,background="#8236CB",highlightthickness=0)
logo = PhotoImage(file=r"tkinter\currency_exchange\dollar.png")# logo($ sign)
canvas.create_image(100,100,image=logo)
canvas.grid(row=0,column=0)
canvas.create_line(300,0,300,300,width=5)


menu=StringVar()# dropdown menu
menu.set("from$")

menu2=StringVar()
menu2.set("to$")

value=Label(window,text="Enter amount.. ")
value.grid(row=1,column=0)
value.config(background="#8236CB",font=FONT)

val_entry=Entry(window,width=10)
val_entry.grid(row=1,column=1,pady=50)

dropfrom=OptionMenu(window,menu,*options)
dropfrom.grid(row=1,column=2)

fromc= Label(window,text="FROM",font=FONT,background="#92e651")
fromc.grid(row=1,column=3)

dropto=OptionMenu(window,menu2,*opt2)
dropto.grid(row=2,column=2)

to=Label(window,text="TO",font=FONT,background="#da9ffb")
to.grid(row=2,column=3)

ans= Label(window,text="0000$",font=FONT)
ans.grid(row=2,column=1)

symbol=Entry(width=10)
symbol.grid(row=0,column=1,padx=50)

desc=Label(text=" <--- check symbols here",font=FONT,background="#77c5ec")
desc.grid(row=0,column=3)

show=Button(text="show",command=getdesc)
show.grid(row=0,column=2)





btn=Button(text="convert",command=getamt,font=FONT,background="#1eaa32")
btn.grid(row=3,column=1,pady=50)



window.mainloop()












