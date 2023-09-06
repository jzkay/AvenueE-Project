// AvenueE HW #1 ELEGOO Lesson 4
// Author: Jacob Marinas
// Date: 5 September 2023

// This is a modification to the sample code provided by ELEGOO, for my learning
// File: RGB_LED.ino
// Date: 8 December 2016
// Version: 1.0
// Available: elegoo.com

void setup() {
  // put your setup code here, to run once:
  // First, define the pins we are using; PWM pins to control the electrical output
  #define BLUE 3
  #define GREEN 5
  #define RED 6

  // Set the mode of the pins to allow electrical output
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Maximum possible value for analogWrite
  int max = 255;

  // Delay time in cycling through different colors, in ms
  int delayTime = 100;
  
  // Value to increment RGB values by through each iteration in cycle
  int increment = 10;

  // For setting the electrical output of PWM, we use analogWrite(pin, value), where value ranges from 0 - 255
  analogWrite(RED, 255);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
  
  delay(1000);

  // Nested for loops that cycle through all the combinations of RGB values
  // Although, the color mixing isn't great and just looks like it goes through different shades of green and yellow
  // for (int i = 0; i < max; i += increment) {
  //   for (int j = 0; j < max; j += increment) {
  //     for (int k = 0; k < max; k += increment) {
  //       setRGB(i, j, k);
  //       delay(delayTime);
  //     }
  //   }
  // }

  delay(1000);
  
  // This attempts to cycle through the color values in a more balanced way from red -> green -> blue
  // The idea is that as one value increases, another value decreases all in relation to the max value
  // 1. Cycle through balanced values of red and green
  // 2. Cycle through balanced values of green and blue
  // 3. Cycle through balanced values of blue and red
  
  for (int state = 0; state < 3; state++) {
    for (int i = 0; i < max; i += increment) {
        switch (state) {
          case 0:
            setRGB(max - i, i, 0);
            break;
          case 1:
            setRGB(0, max - i, i);
            break;
          case 2:
            setRGB(i, 0, max - i);
            break;
          default:
            setRGB(0, 0, 0);
        }
        delay(delayTime);
      }
    }

  delay(1000); 

}

// Helper function that sets the RGB values for the RGB led
void setRGB(int r, int g, int b) {
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}
