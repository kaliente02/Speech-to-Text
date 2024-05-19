# Project X Speech-to-Text Recognition
# Group Members:
# Kims Cyra Rayel M. Moring | Crystle Wyne Piodos | Kyla Angelica P. Ramas
#05-19-2024 

import serial  # Import the serial library for communication with Arduino
import speech_recognition as sr  # Import the speech recognition library
import time  # Import the time library for delays

# Initialize the speech recognizer
recognizer = sr.Recognizer()

# Establish serial connection with Arduino
arduino = serial.Serial('COM4', 9600)  #COM may vary. You must upload the Arduino code first before running Thonny. 

# Function to listen to microphone input and recognize speech
def listen_and_recognize():
    with sr.Microphone() as source:
        print("Listening....")
        audio = recognizer.listen(source)  # Record audio from the microphone
        try:
            print("Recognizing....")
            text = recognizer.recognize_google(audio)  # Use Google's speech recognition to convert audio to text
            print(f"Recognized Text: {text}")  # Print the recognized text
            return text
        except sr.UnknownValueError:
            print("Project X Speech to Text Recognition could not understand audio")  # Handle unrecognized audio
        except sr.RequestError as e:
            print(f"Could not request results from Project X Speech to Text Recognition service; {e}")  # Handle API request errors
        return ""  # Return an empty string if recognition fails

# Main loop
while True:
    text = listen_and_recognize()  # Listen for speech and recognize it
    if text:
        arduino.write(text.encode())  # Send the recognized text to Arduino via serial communication
        time.sleep(2)  # Wait for 2 seconds before listening again
