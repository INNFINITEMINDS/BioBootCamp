/* Random Button

buttonRandom.ino
created 10 July 2017
by Samuel Bechara

This program flashes a random LED when a digital button is pressed. 
It is designed such that the random number can not be the same as 
the LED that was originally pressed. Every 5 presses, ALL LEDs are 
blinked and all LEDs are then turned off. For this program it is 
important that the LEDs are on sequential pins 
example(LEDS are on digital pins 4,5,6) 
so that the random number generator can work. It is possible to 
work around this but more complicated code is necessary.
*/

// create variables for all of the hardware pins. Since they aren't going to be changing, I made them constants just in case.
const int greenLED = 8;
const int blueLED = 9;
const int redLED = 10;
const int buttonPin = 13;

// create a variable to monitor if the button is pushed or not
int buttonState;

// create variables to store the pins that were lit up. You need this to be able to tell which LED was currently lit so your random number isn't the same as before. 
int newLED;
int oldLED;

// create a variable to count how many times the button is pressed.
int buttonCount = 0;

// in the setup function, define all buttons as either input or output and generate a random number 
void setup()
{
  Serial.begin(9600); // begin the serial connection
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  // turn on a random LED
  newLED = random(8, 11);
  digitalWrite(newLED, HIGH);
  oldLED = newLED;
}

// the loop runs continously as long as the arduino is turned on
void loop()
{
  // check to see if the button is being pushed
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) 
  {
    delay(200); // add a slight delay so that a single button push doesn't register as multiple pushes
    buttonCount++; // increment the buttonCount variable

    // checek to see if the button press is in a multiple of 5
    if (buttonCount % 5 == 0)
    {
      // if it is a multiple of 5, flash all LEDs
      digitalWrite(redLED, HIGH);
      digitalWrite(blueLED, HIGH);
      digitalWrite(greenLED, HIGH);
      delay(200);
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(greenLED, LOW);
      delay(200);
      digitalWrite(redLED, HIGH);
      digitalWrite(blueLED, HIGH);
      digitalWrite(greenLED, HIGH);
      delay(200);
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(greenLED, LOW);
    }
    else
    {
      // if it isn't, then switch to a random LED
      digitalWrite(oldLED, LOW);
      while (newLED == oldLED)
      {
	// this while loop checks to make sure that a different LED is lit up each press
        newLED = random(8,11);
      }      
      digitalWrite(newLED, HIGH);
      oldLED = newLED;
    }
    Serial.println(buttonCount); // print the number of times the button is pressed to the serial port.
  }   
}
