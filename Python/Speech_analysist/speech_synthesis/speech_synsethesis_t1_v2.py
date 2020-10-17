from gtts import gTTS
import os
import time

with open('/home/cooking/Documents/Python/Speech_recog/speech_synsethesis_sample.txt') as speech_text:
	content = speech_text.readlines()
	speech_text.close()

def speech_synthesis(text, lang, remove):
	tts = gTTS(text = text, lang = lang, slow = False)
	tts.save("gtts0.mp3")
	os.system("mpg321 gtts0.mp3")
	if remove == True:
		os.remove("gtts0.mp3")

for line in content: # doc tung dong mot
	speech_synthesis(line, 'en', False)
	time.sleep(1) # dung 1 giay