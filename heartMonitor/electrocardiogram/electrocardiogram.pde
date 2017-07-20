/******************************************************************************
                          electrocardiogram.pde
                            PROCESSING CODE
*******************************************************************************

Written by: Samuel Bechara, PhD
Created: 10 November 2015
Last Edited: 8 July 2017

Description ------------------------------------------------------------------
This processing code is meant to be used for the Marquette University
Arduino outreach project. This code displays the data sent from an AD8232
heart monitor and displays an electrocardiogram.

This code relies heavily on libraries written by Sparkfun and Adafruit
employees so please support them and buy their stuff.

If you have any questions about the intended use of this code, please visit
www.github.com/sbechara

Copyright (c) 2017 Samuel Bechara
******************************************************************************/


import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
float inByte = 0;
float old_data = 0;

void setup () {
  // set the window size:
  size(1000, 400);

  // List all the available serial ports
  // if using Processing 2.1 or later, use Serial.printArray()
  println(Serial.list());

  // I know that the first port in the serial list on my pi-top
  // is always my  Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[1], 9600);

  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');

  // set inital background:
  background(0, 0, 0);
}
void draw () {
  // draw the line:
  stroke(255, 0, 0);
  strokeWeight(2);

  line(xPos-1, old_data, xPos, inByte);
  old_data = inByte;

  // at the edge of the screen, go back to the beginning:
  if (xPos >= width) {
    xPos = 0;
    background(0);
  } else {
    // increment the horizontal position:
    xPos++;
  }
}


void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);
    // convert to an int and map to the screen height:
    inByte = float(inString);
    //println(inByte);
    inByte = map(inByte, 0, 1023, 0, height);

  }
}
