import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia as wp
import webbrowser
import os
from random import randint
import wikipedia
import playsound

engine = pyttsx3.init("sapi5")
voices=engine.getProperty("voices")
engine.setProperty("voice",voices[1].id)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()
    
def wishMe():
    hour=int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good Morning")
    elif hour>=12 and hour <18:
        speak("Good Afternoon")
    else:
        speak("Good Evening")
    
    speak("Hello I am Scaler... How can I help U?")

def takeCommand():
    r=sr.Recognizer()
    with sr.Microphone() as source:
        print("Input in pogress.....")
        r.pause_threshold=1
        #r.energy_threshold=200
        audio=r.listen(source)

    try:
        print("\nRecognising....\n")
        query=r.recognize_google(audio,language="en-in")
        print(f"User Said {query}")
    except Exception as e:
        print(f"{e}")
        print("\nSay that again please\n")
        return "None"
    return query

def writermode():
    r=sr.Recognizer()
    with sr.Microphone() as source:
        print("Writing")
        r.pause_threshold=1
        #r.energy_threshold=200
        audio=r.listen(source)

    try:
        print("\nTrying to write \n")
        query=r.recognize_google(audio,language="en-in")
        print(f"User Said {query}")
    except Exception as e:
        print(f"{e}")
        print("\nSay that again please\n")
        return "None"
    return query

if __name__=="__main__":
    wishMe()
    
    while True:
        query=takeCommand().lower()
        playsound.playsound("mixkit-bell-notification-933.wav")

        if "wikipedia" in query:
            speak("Searching wikipedia....")
            query=query.replace("wikipedia","")
            results=wp.summary(query, sentences=2)
            speak("Wikipedia says ")
            print(results)
            speak(results)

        elif "open youtube" in query:
            webbrowser.open("Youtube.com")
        elif "open google" in query:
            webbrowser.open("google.com")        
        elif "play music" in query:
            musicdir= "E:\\pendrive\\Coding Sessions\\python\\Independent Projects\\Voice assistant\\Evolve - Imagine Dragons - Zeromusicracks\\Evolve - Imagine Dragons - Zeromusicracks"
            songs=os.listdir(musicdir)
            print(songs)
            random=randint(0,10)
            os.startfile(os.path.join(musicdir,songs[random]))
        elif "time" in query:
            srtime=datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"The time is {srtime}")
            print(f"The time is {srtime}")
        elif "exit" in query:
            speak("Thank You Sir... Have a nice day")
            print("Putting Scaler to Sleep....\nBye")
            break
        
        elif "write mode" in query:
            speak("Speak Sir")
            while True:
                myfile=open("Writingfile.txt","a")
                if "over and out" in query:
                    speak("Exiting write mode")
                    break
                else:
                    speaking=writermode()
                    myfile.write(speaking+" ")
                query=speaking