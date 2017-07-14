/* Blink Built-in LED

blinkBuiltinLED.ino
created 10 July 2017
by Samuel Bechara, PhD

This program blinks the builtin LED on an arduino UNO board.

*/

// the setup function runs once when the arduino is turned on
void setup()
{
  // set the builtin led so that it is a digital output
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs continuously as long as the arduino is powered.
void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
