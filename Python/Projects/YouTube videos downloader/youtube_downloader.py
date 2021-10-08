from tkinter import *
from pytube import YouTube

rt = Tk()
rt.geometry('600x400')
rt.resizable(0,0)
rt.title("Vishakha's Youtube Downloader. Here you can download any of the youtube videos")

Label(rt,text = "Youtube Videos Downloader", font="arial 23 bold").pack()

link = StringVar()

Label(rt,text ="Please paste the link here:",font="arial 15 bold").place(x=160,y=60)
enter_link=Entry(rt,width=90,textvariable=link).place(x=32,y=90)

def Downloader():
    url=YouTube(str(link.get()))
    video=url.streams.first()
    video.download()
    Label(rt,text="Your video is downloaded, thank you!!",font="arial 16 bold").place(x=180,y=210)
	
Button(rt,text="Download Now",font="arial 16 bold",bg="dark turquoise",padx=2,command=Downloader).place(x=180,y=150)

rt.mainloop()
