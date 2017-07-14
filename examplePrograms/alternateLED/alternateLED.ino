/* Alternate LEDs

alternateLED.ino
created on 10 July 2017
by Samuel Bechara, PhD

This program blinks an LED attached to a digital pin with the arduino's built in LED.

*/

// create a variable to store a number that cooresponds to the pin that the LED is connected to
int blueLED=10;

void setup()
{
  pinMode(blueLED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(blueLED, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN,HIGH);
  digitalWrite(blueLED,LOW);
  delay(1000);
}
