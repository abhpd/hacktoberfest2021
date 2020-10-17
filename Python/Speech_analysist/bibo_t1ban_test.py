import time
import speech_recognition as sr

import aiml
import os, sys
import pandas as pd

import textrazor
from nltk import Tree

# sys.stdout = open(os.devnull, 'w')

from gtts import gTTS

class DICTIONARY:
	commandReader = pd.read_csv("dictionary/Commands.csv")
	commandDictionary = {}
	for (index, row) in commandReader.iterrows():
		if (pd.isnull(row['Devices']) == 0 and pd.isnull(row['Commands']) == 0):
			commandDictionary[(row['Devices'].lower(), row['Commands'].lower())] = row['Parameters']


class SPEECH_SYNTHESIS:
	def speak_audio(self, text, lang , remove): # tao mot ham nhan 3 tham so
	    tts = gTTS(text = text, lang = lang, slow = False) # goi lenh gtts 
	    tts.save("gtts0.mp3") # luu vao file .mp3
	    os.system("mpg321 gtts0.mp3 >/dev/null 2>&1") # chay file .mp3
	    if remove == True: # xoa neu can thiet
	        os.remove("gtts0.mp3")

class AIML:
	def __init__(self, dictionary_instance):
		self.dictionary_instance = dictionary_instance
		self.kernel = aiml.Kernel()
		self.kernel.bootstrap(learnFiles = "aiml_ref/std-startup.xml", commands = "load alexa")
		self.kernel.setPredicate("alexa_flag", "empty")
		
	def aiml_process(self, text):
		print("input: ", text)
		expected_output = self.kernel.respond(text)
		print("output: ", expected_output)

		# synthesis here
		global output_text
		if (expected_output):
			output_text.append(expected_output)
		else:
			output_text.append("Sorry, Please say again")
			return
		
		r_device = self.kernel.getPredicate("alexa_device").strip().lower()
		r_command = self.kernel.getPredicate("alexa_command").strip().lower()
		r_parameters = self.kernel.getPredicate("alexa_parameters").strip().split('|')
		r_flag = self.kernel.getPredicate("alexa_flag")
		if r_flag == "queued":
			# print("aiml to python ",r_device,"with command ", r_command, " with para", r_parameters)
			if (r_device, r_command) in self.dictionary_instance.commandDictionary :
				# print("pass phase 1, now para", commandDictionary[(r_device, r_command)])
				list_of_para = self.dictionary_instance.commandDictionary[(r_device, r_command)]
				# if (list_of_para == NaN && r_parameters.isnull() = 0) 
				checker = True
				for para in r_parameters :
					if para.strip():
						para = para.strip()
						# print(ascii(para))
						para_keys = para[:para.find("=")].strip()
						# print("keys =", para_keys)
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
			self.kernel.setPredicate("alexa_parameters", "")
		self.kernel.setPredicate("alexa_flag", "empty")

class NLP:
	def __init__(self, aiml_instance):
		textrazor.api_key="d64cc7e640600e8e2305304d8e79e6b945b575825a72ce4b853da187"
		self.client = textrazor.TextRazor(extractors=["dependency-trees"])
		self.max_position = 0
		self.mark_array = []
		self.token_array = []
		self.phrase = []

		self.marker = ["xcomp", "advcl", "conj"]

		self.aiml_instance = aiml_instance


	def mark(self, node, marked_num):
	    self.mark_array[node.position] = marked_num
	    self.token_array[node.position] = node.token
	    self.max_position=max(self.max_position, node.position)
	    for child in node.children:
	        if (child.relation_to_parent == "punct"): continue
	        if (child.relation_to_parent == "cc"): continue
	        if (child.relation_to_parent in self.marker):
	            self.mark(child, marked_num + 1)        
	        else:
	            self.mark(child, marked_num)

	def to_phrase(self):
		for x in range(self.max_position + 1):
			if self.mark_array[x] == 0: continue
			self.phrase[self.mark_array[x] - 1] += str(" " + self.token_array[x])
	        # print(mark_array[x] - 1, token_array[x])

	def text_process(self, text):
		self.mark_array = [0] * 70
		self.token_array = ["" for i in range(70)]
		self.phrase = ["" for i in range(10)]
		self.max_position = 0

		alexa_flag = (text.split()[0] == "Alexa" or text.split()[0] == "alexa")
		if (alexa_flag): 
			text = text.replace("alexa", "", 1)
			text = text.replace("Alexa", "", 1)

		response = self.client.analyze(text)
		sent = response.sentences()
		
		self.mark(sent[0].root_word, 1)
		self.to_phrase()

		for x in self.phrase:
			if x: AIML.aiml_process(self.aiml_instance, str("alexa" + x) if alexa_flag else x)

class SPEECH_RECOGNITION():
	def __init__(self, nlp_pass, gtts_pass):
		# for supressing on Linux, smthing buggy here
		fd = os.open('/dev/null',os.O_WRONLY)
		savefd = os.dup(2)
		os.dup2(fd,2)

		self.r = sr.Recognizer()
		self.m = sr.Microphone()

		# restore
		os.dup2(savefd,2)

		self.nlp_pass = nlp_pass
		self.gtts_pass = gtts_pass
		with self.m as source:
			self.r.adjust_for_ambient_noise(source)  # we only need to calibrate once, before we start listening

	def callback(self, recognizer, audio):
	    # received audio data, now we'll recognize it using Google Speech Recognition
	    try:
	        maybe_text = recognizer.recognize_google(audio)
	        print("User: " + maybe_text)
	        if maybe_text:
	       		NLP.text_process(self.nlp_pass, maybe_text)
	    except sr.UnknownValueError:
	        print("Could not understand audio")
	    except sr.RequestError as e:
	        print("Could not request results from Google Speech Recognition service; {0}".format(e))

	def run_in_back_ground(self):
		self.r.listen_in_background(self.m, self.callback)
		global output_text
		while (1) :
			if (len(output_text)):
				SPEECH_SYNTHESIS.speak_audio(self.gtts_pass, text = output_text[0], lang = 'en', remove = False)
				output_text.pop(0)

output_text = []
dictionary_I = DICTIONARY()
synthesis_I = SPEECH_SYNTHESIS()
aiml_I = AIML(dictionary_I)
nlp_I = NLP(aiml_I)
sr_I = SPEECH_RECOGNITION(nlp_I, synthesis_I)

sr_I.run_in_back_ground()
