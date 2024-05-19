//Project X is a Speech-to-Text Recognition for Digital Signals Processing

//Group Members are composed of 3rd year BSCpE Students
//Kims Cyra Rayel M. Moring | Crystle Wyne Piodos | Kyla Angelica P. Ramas
//05/19/2024

//Here's the code!!!

#include <Wire.h>  // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h>  // Include the LiquidCrystal_I2C library for interfacing with the LCD display

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Create an LCD object with I2C address 0x27 and dimensions 16x2

void setup() {
  Serial.begin(9600);  // Initialize serial communication at a baud rate of 9600
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  lcd.backlight();  // Turn on the backlight of the LCD
  lcd.setCursor(0, 0);  // Set the cursor position to the first column of the first row
  lcd.print("Listening...");  // Print "Listening..." on the LCD
}

void loop() {
  if (Serial.available() > 0) {  // Check if there is serial data available to read
    lcd.clear();  // Clear the LCD display
    String text = Serial.readString();  // Read the incoming string from the serial port
    lcd.setCursor(0, 0);  // Set the cursor position to the first column of the first row
    lcd.print(text.substring(0, 16));  // Display the first 16 characters of the string on the first line of the LCD
    if (text.length() > 16) {  // Check if the length of the string is greater than 16 characters
      lcd.setCursor(0, 1);  // Set the cursor position to the first column of the second row
      lcd.print(text.substring(16, 32));  // Display the next 16 characters of the string on the second line of the LCD
    }
  }
}
