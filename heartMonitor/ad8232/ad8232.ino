/******************************************************************************
                             ad8232.ino
                            ARDUINO CODE
*******************************************************************************

Written by: Samuel Bechara, PhD
Created: 10 November 2015
Last Edited: 20 July 2017

Description ------------------------------------------------------------------
This arduino code is meant to be used for the Marquette University
Arduino outreach project. Specifically to interface a sparkfun redboard with a
sparkfun heart monitor (part#: ADB232).

This code relies heavily on libraries written by Sparkfun and Adafruit
employees so please support them and buy their stuff.

If you have any questions about the intended use of this code, please visit
www.github.com/sbechara

Copyright (c) 2017 Samuel Bechara
******************************************************************************/

// Declare pin variables. You will have to change them to match your hardware configuration
int lo_minus = 6;
int lo_plus = 5;

/* The setup() function is called when a sketch starts. The setup function will
only run once, after each powerup or reset of the Arduino board. */
void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(lo_minus, INPUT); // Setup for leads off detection LO +
  pinMode(lo_plus, INPUT); // Setup for leads off detection LO -
}

/* The loop() function does precisely what its name suggests, and loops
consecutively. */
void loop()
{
  // checks if the user is not connected
  if((digitalRead(lo_minus) == HIGH)||(digitalRead(lo_plus) == HIGH))
  {
    // if they aren't connected, print ! to the serial port
    Serial.println('!');
  }
  else
  {
    // Or else they ARE connected.
    // So this line sends the value from the heart monitor to the A0 port
      Serial.println(analogRead(A0));
  }
  //Wait for a bit to keep serial data from saturating
  delay(1);
}
