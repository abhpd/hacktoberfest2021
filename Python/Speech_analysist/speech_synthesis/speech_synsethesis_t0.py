import pyttsx3

with open('/home/cooking/Documents/Python/Speech_recog/speech_synsethesis_sample.txt') as speech_text:
	content = speech_text.read()
	speech_text.close()

def say(text):
	engine = pyttsx3.init()
	voices = engine.getProperty('voices')
	engine.setProperty('voice', "english")        
	engine.say(text)
	engine.runAndWait()

def say2(text):
	engine2 = pyttsx3.init()
	engine2.say(text)
	engine2.runAndWait()

say(content)