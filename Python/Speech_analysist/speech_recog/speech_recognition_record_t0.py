import speech_recognition as sr
r = sr.Recognizer()
with sr.Microphone() as source:                # use the default microphone as the audio source
    r.adjust_for_ambient_noise(source)  # here
    audio = r.listen(source, timeout = 3)                   # listen for the first phrase and extract it into audio data

try:
    # for testing purposes, we're just using the default API key
    # to use another API key, use `r.recognize_google(audio, key="GOOGLE_SPEECH_RECOGNITION_API_KEY")`
    # instead of `r.recognize_google(audio)`
    print(r.recognize_google(audio))
except sr.UnknownValueError:
    print("Google Speech Recognition could not understand audio")
except sr.RequestError as e:
    print("Could not request results from Google Speech Recognition service; {0}".format(e))