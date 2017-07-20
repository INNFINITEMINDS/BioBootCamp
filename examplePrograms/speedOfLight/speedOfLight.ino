/* Speed of Light Game
speedOfLigt.ino
created 19 July 2017
by Samuel Bechara, PhD
This is an arduino game that flashes 5 external LED lights. The goal is to
press a physical button when the light is in the middle LED. You get less
points if the light isn't there. If you want to make it more difficult or
easier, change the timeLag variable. That will automatically change the delay
between light changes.
*/

// Define all variables up here so they are easy to change

// These are the hardware connections. The LEDs have to be in sequential order!
const int LED1 = 8;
const int LED2 = 9;
const int LED3 = 10;
const int LED4 = 11;
const int LED5 = 12;
const int firstLED = LED1; // these two variables make the code easier to read
const int lastLED = LED5;
const int buttonPin = 13;
int buttonState;

// These are the "game" variables. If timeLag is smaller, the game is harder...
bool direction; // we will call one direction true and the other false
int lives = 5; // the player starts with however many lives you want
int timeLag = 50; // this is the number of ms before the LED switches.
int currentLED; // store the current LED that is lit
int score = 0; // player starts with a score of zero

// This function only runs once when the arduino is started
void setup()
{
  // Start the serial connection so we can talk to the player
  Serial.begin(9600);

  // Set all the pins to be inputs or outputs as appropriate
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(buttonPin, INPUT);

  // Start with the first LED on and the direction as "true"
  currentLED = LED1;
  digitalWrite(currentLED, HIGH);
  direction = true;

  // give the user a little message about where they are in the game!
  Serial.print("You start with ");
  Serial.print(lives);
  Serial.println(" lives");

  delay(timeLag); // needed even though the game "starts" at the loop
}

void loop()
{
  // the button state variable tracks if the button is pushed or not
  buttonState = digitalRead(buttonPin);

  // First, check if they have enough lives left, or else we don't have to worry about them playing!
  if (lives > 0)
  {
    // If the button isn't pushed AND the direction true (we can think of that as "forward")
    // then we need to switch the LED by INCREMENTING
    if (buttonState == LOW && direction == true)
    {
      // we need to check if we are at the end of the row!
      if (currentLED == lastLED)
      {
        // if it IS at the end of the row, change direction and decrement currnetLED
        direction = false;
        digitalWrite(currentLED, LOW);
        currentLED--;
        digitalWrite(currentLED, HIGH);
      }
      else
      {
        digitalWrite(currentLED, LOW);
        currentLED++;
        digitalWrite(currentLED, HIGH);
      }
    }

    // If the button isn't pushed AND the direction is false (aka "backwards")
    // then we need to switch the LED by DECREMENTING
    else if (buttonState == LOW && direction == false)
    {
      // we need to check if we are at the beginning of the row!
      if (currentLED == firstLED)
      {
        // if it IS at the beginning of the row, change direction and increment currnetLED
        direction = true;
        digitalWrite(currentLED, LOW);
        currentLED++;
        digitalWrite(currentLED, HIGH);
      }
      else
      {
        digitalWrite(currentLED, LOW);
        currentLED--;
        digitalWrite(currentLED, HIGH);
      }
    }

    // the only remaining possibility is if the buttonState is HIGH (aka someone pressed it!)
    else
    {
      // remove a life
      lives--;

      // Figure out what score they get and add it to their total score
      if (currentLED == firstLED || currentLED == lastLED)
      {
        score = score + 100;
      }
      else if (currentLED == firstLED + 1 || currentLED == lastLED - 1)
      {
        score = score + 250;
      }
      else
      {
        score = score + 500;
      }

      // give the user a little message about where they are in the game!
      Serial.print("You have ");
      Serial.print(lives);
      Serial.println(" lives left");

      Serial.print("Your current score is: ");
      Serial.println(score);

      Serial.println("Please take your finger off the button and wait for the LEDs to start flashing...");
      delay(5000); // wait 5 seconds before starting again...

    }

    // WHOA! Thats a lot of stuff, now we need to wait before changing the LED again!
    delay(timeLag);
  }

  // this is what happens when we run out of lives!
  else
  {
    // if the user is out of lives, this is an infinite loop, it will encourage the user to restart the arudino!
    while (1)
    {
      Serial.print("Your final score was: ");
      Serial.print(score);
      Serial.println(" nice job!");
      Serial.println("Thanks for playing, please press the restart button on the Arduino to play again!");
      delay(10000);
    }
  }
}
