/* Button

button.ino
created on 10 July 2017
by Samuel Bechara, PhD

This program uses a digital button as an input. When the button is pressed it switches the LED that is lit from green to red.

*/

// define hardware pins
int redLED = 11;
int greenLED = 12;
int buttonPin = 2;

// create a variable to track the state of the button
int buttonState = 0;

void setup()
{
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  // set the buttonState variable to be the value of the buttonPin (either HIGH or LOW)
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
  }
  else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }
      
}
