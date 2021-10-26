from gtts import gTTS
import os

# The text that you want to convert to audio
mytext = input("Please type the text you want to convert to audio: ")

# Language in which you want to convert
language = input("Language: ")

# Passing the text and language to the engine
myobj = gTTS(text=mytext, lang=language, slow=False)

# Saving the converted audio in a mp3 file
myobj.save("welcome.mp3")

# Playing the converted file
os.system("welcome.mp3")