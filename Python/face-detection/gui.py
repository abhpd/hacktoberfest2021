from tkinter import *


window=Tk()

window.wm_title("FaceDetection")

l1=Label(window,text="Add the image")

from tkinter.filedialog import askopenfilename

Tk().withdraw() # we don't want a full GUI, so keep the root window from appearing
filename = askopenfilename() # show an "Open" dialog box and return the path to the selected file
print(filename)