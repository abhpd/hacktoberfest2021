import pyttsx3
engine = pyttsx3.init()
voices = engine.getProperty('voices')
# for voice in voices:
#     print(voice, voice.id)
#     engine.setProperty('voice', voice.id)
#     engine.say("Hello World!")
#     engine.runAndWait()
#     engine.stop()

for voice in voices:
    print(voice)
    if voice.languages[0] == u'en_US':
        engine.setProperty('voice', voice.id)
        break

import pyttsx3

engine = pyttsx3.init()
voices = engine.getProperty('voices')
for voice in voices:
    if voice.languages[0] == u'en_US':
        engine.setProperty('voice', voice.id)
        break

engine.say('Hello World')
engine.runAndWait()