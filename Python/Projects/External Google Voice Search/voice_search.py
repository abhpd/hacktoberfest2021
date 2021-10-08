import speech_recognition as sr
import pyttsx3 
i=1
r = sr.Recognizer() 

def SpeakText(command):
      
    
    engine = pyttsx3.init()
    engine.say(command) 
    engine.runAndWait()
  
while(i==1):    
  
    try:
        
        with sr.Microphone() as source2:
           
            r.adjust_for_ambient_noise(source2, duration=0.2)
            print("GOOGLE VOICE SEARCH")
            print("Speak Now")
            audio2 = r.listen(source2)
         
            MyText = r.recognize_google(audio2)
            MyText = MyText.lower()
  
            print(MyText)
            SpeakText(MyText)
            i=2  
    except sr.RequestError as e:
        print("Could not request results; {0}".format(e))
          
    except sr.UnknownValueError:
        print("unknown error occured")
        
from selenium import webdriver
import time
from selenium.webdriver.common.keys import Keys

driver = webdriver.Chrome(executable_path=r"C:\Users\VIGNESH\Downloads\Chromedriver\chromedriver")
driver.set_page_load_timeout("10")
driver.get("https://www.google.com/")
driver.maximize_window()
que = driver.find_element_by_name("q")
que.send_keys(MyText)
time.sleep(3)
que.send_keys(Keys.ARROW_DOWN)
que.send_keys(Keys.RETURN)
