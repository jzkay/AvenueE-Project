// AvenueE HW #1 ELEGOO Lesson 5 Digital Inputs
// Author: Jacob Marinas
// Date: 5 September 2023

// This is a modification to the sample code provided by ELEGOO, for my learning
// File: Digital_Inputs.ino
// Date: 8 December 2016
// Version: 1.0
// Available: elegoo.com

void setup() {
  // put your setup code here, to run once:

  // Define pin numbers
  #define ledPin 5
  #define buttonApin 9
  #define buttonBpin 8

  // Set the pin mode

  // Allow electrical output
  pinMode(ledPin, OUTPUT);

  // Use pins to get input, check electrical input
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  

}

void loop() {
  // put your main code here, to run repeatedly:

  // Obtain input through digitalRead(pin), which returns either HIGH or LOW
  // When the button is pressed, digitalRead(pin) returns LOW, so we will use this condition
  // Produce electrical output to the LED through digitalWrite(pin, value), where value is HIGH or LOW

  // Button A will turn on the LED
  if (digitalRead(buttonApin) == LOW) {
    digitalWrite(ledPin, HIGH);
  }

  // Button B will turn off the LED
  if (digitalRead(buttonBpin) == LOW) {
    digitalWrite(ledPin, LOW);
  }
}
