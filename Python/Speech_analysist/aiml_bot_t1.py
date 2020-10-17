import aiml
import os

import pandas as pd

commandReader = pd.read_csv("dictionary/Commands.csv")
commandDictionary = {}

# print(len(commandReader.index))
for (index, row) in commandReader.iterrows():
	# print(row['Devices'], row['Commands'], row['Parameters'])
	if (pd.isnull(row['Devices']) == 0 and pd.isnull(row['Commands']) == 0):
		commandDictionary[(row['Devices'].lower(), row['Commands'].lower())] = row['Parameters']
#create the kernel
kernel = aiml.Kernel()

# if os.path.isfile("bot_brain.brn") :
# 	kernel.bootstrap(brainFile = "bot_brain.brn")
# else :
kernel.bootstrap(learnFiles = "aiml_ref/std-startup.xml", commands = "load alexa")
kernel.setPredicate("alexa_flag", "empty")
# kernel.bootstrap(learnFiles = "aiml_ref/std-startup.xml", commands = "load all")
# kernel.saveBrain("bot_brain.brn")

# ready
while True:
	expected_output = kernel.respond(input("text me >>"))
	print(expected_output)
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
		kernel.setPredicate("alexa_parameters", "")
	kernel.setPredicate("alexa_flag", "empty")
	