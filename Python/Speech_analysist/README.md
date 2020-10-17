# Speech-Analysist
Intro:
Hello from Vietnam  
We are a small team interested in speech-controlling, specificly in robotics.  
Make it simply, from an audio, you can get command(s), which is formated like this:  
  Modules.Function(Parameters)  
  
Currently, we are using Speech-Recognition and gtts libraries to get text from audio and revert.  
For understanding, we use Text-Razor API for building dependency-tree to seperate phrase from   
the whole text. Then use AIML to detect parameters from text.  
  
For security, after getting the commands from AIML, will check in the dictionary if there exists one.  
  
Coding:  
 AIML is just as it is, nothing special here. You can set variables inside AIML and get them in python  
 To seperate phrase, we use a simple recursive code: whenever go into a "xcomp" or "conj" or "advcl" node,   
 we cut it out.  
 Reference for dependency-tree: https://nlp.stanford.edu/software/dependencies_manual.pdf  
  
Usage:  
Import your commands to commands.csv in dictionary:  
&nbsp;&nbsp;Module_name, Function_name, Parameter  
For example:  
&nbsp;&nbsp;Bluetooth, connect, device  
&nbsp;&nbsp;SMS, send, "receiver, text"  
  
Then add a category for it in alexa_ref/alexa_fake.aiml  
For example:
```python
 <category>
  <pattern>ALEXA BLUETOOTH CONNECT *</pattern>
  <template>
    OK Master, now connect <star/>
    <think>
      <set name="alexa_device">bluetooth</set>
			<set name="alexa_command">connect</set>
			<set name="alexa_parameters"> | device = <star/> | </set>
			<set name="alexa_flag">queued</set>
		</think>
   </template>
 </category>
```
We seperate the parameter by "|", and the flag indicates ending of a command (there is case you want to ask user multiple questions)  
  
After that Delete brain_bot file  
And in the same directory, run ```$ python3 bibo_t1_test```. Have fun testing !


