/* Traffic Light

trafficLight.ino
created on 10 July 2017
by Samuel Bechara, PhD

This program alternates 3 LED lights attached to the digital pins of the arduino like a traffic light.

*/

// define pin variables
int blueLED=10;
int redLED = 11;
int greenLED = 12;

void setup()
{
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  digitalWrite(greenLED, LOW);
  delay(500);
  digitalWrite(redLED, HIGH);
  digitalWrite(blueLED,LOW);
  delay(700);
}
