
# Import Required Modules
from tkinter import *

# Create Object
root = Tk()

# Set geometry
root.geometry('400x400')

# Add Label
Label(root, text="Youtube Playlist Downloader",
	font="italic 15 bold").pack(pady=10)
Label(root, text="Enter Playlist URL:-", font="italic 10").pack()

# Add Entry box
playlistId = Entry(root, width=60)
playlistId.pack(pady=5)

# Add Button
get_videos = Button(root, text="Get Videos")
get_videos.pack(pady=10)

# Add Scollbar
scrollbar = Scrollbar(root)
scrollbar.pack(side=RIGHT, fill=BOTH)
list_box = Listbox(root, selectmode="multiple")
list_box.pack(expand=YES, fill="both")
list_box.config(yscrollcommand=scrollbar.set)
scrollbar.config(command=list_box.yview)

download_start = Button(root, text="Download Start", state=DISABLED)
download_start.pack(pady=10)

# Execute Tkinter
root.mainloop()
