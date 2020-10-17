import time
import speech_recognition as sr

import aiml
import os, sys
import pandas as pd

# sys.stdout = open(os.devnull, 'w')

from gtts import gTTS

def speech_synthesis(text, lang , remove): # tao mot ham nhan 3 tham so
    tts = gTTS(text = text, lang = lang, slow = False) # goi lenh gtts 
    tts.save("gtts0.mp3") # luu vao file .mp3
    os.system("mpg321 gtts0.mp3") # chay file .mp3
    if remove == True: # xoa neu can thiet
        os.remove("gtts0.mp3")

def aiml_process(text):
	expected_output = kernel.respond(text)
	print(expected_output)

	# synthesis here
	output_text.append(expected_output)
	
	r_device = kernel.getPredicate("alexa_device").strip().lower()
	r_command = kernel.getPredicate("alexa_command").strip().lower()
	r_parameters = kernel.getPredicate("alexa_parameters").strip().split('|')
	r_flag = kernel.getPredicate("alexa_flag")
	if r_flag == "queued":
		# print("aiml to python ",r_device,"with command ", r_command, " with para", r_parameters)
		if (r_device, r_command) in commandDictionary :
			# print("pass phase 1, now para", commandDictionary[(r_device, r_command)])
			list_of_para = commandDictionary[(r_device, r_command)]
			# if (list_of_para == NaN && r_parameters.isnull() = 0) 
			checker = True
			for para in r_parameters :
				if para.strip():
					para = para.strip()
					print(ascii(para))
					para_keys = para[:para.find("=")].strip()
					print("keys =", para_keys)
					if list_of_para.find(para_keys) == -1:
						print("false here ", para_keys)
						checker = False
						break
				else:
					r_parameters.remove(para)
			# print("check ", checker)
			if (checker == True) :
				ourCommand = r_device + "." + r_command + "(" + ','.join(r_parameters) + ")"
				print(ourCommand)
		kernel.setPredicate("alexa_parameters", "")
	kernel.setPredicate("alexa_flag", "empty")
	
def callback(recognizer, audio):
    # received audio data, now we'll recognize it using Google Speech Recognition
    try:
        maybe_text = recognizer.recognize_google(audio)
        print("User: " + maybe_text)
        if maybe_text:
       		aiml_process(maybe_text)
    except sr.UnknownValueError:
        print("Could not understand audio")
    except sr.RequestError as e:
        print("Could not request results from Google Speech Recognition service; {0}".format(e))

r = sr.Recognizer()
m = sr.Microphone()
kernel = aiml.Kernel()

commandReader = pd.read_csv("dictionary/Commands.csv")
commandDictionary = {}
for (index, row) in commandReader.iterrows():
	if (pd.isnull(row['Devices']) == 0 and pd.isnull(row['Commands']) == 0):
		commandDictionary[(row['Devices'].lower(), row['Commands'].lower())] = row['Parameters']

if os.path.isfile("bot_brain.brn") :
	kernel.bootstrap(brainFile = "bot_brain.brn")
else :
	kernel.bootstrap(learnFiles = "aiml_ref/std-startup.xml", commands = "load all")
	kernel.saveBrain("bot_brain.brn")
	kernel.setPredicate("alexa_flag", "empty")

with m as source:
    r.adjust_for_ambient_noise(source)  # we only need to calibrate once, before we start listening

output_text = []
r.listen_in_background(m, callback)

while (1) :
	if (len(output_text)):
		speech_synthesis(text = output_text[0], lang = 'en', remove = False)
		output_text.pop(0)