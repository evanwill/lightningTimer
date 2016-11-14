/*
 * Timer Countdown Arduino
 * Five LEDS , each LED blinks representing one minute 
 * Buzzer buzzes at the end of five minutes, with LED blinking
 * by Laila D. Engineer for UIdaho GIS Day Lightning Talks 2016
 */


// delay between each interval LED of pomodoro (in seconds)
// note: For 5 mins enter 60 for  Interval, the equation to enter the correct number is:
// Number of minutess wanted multiply by 12, Ex: for 5 minutes: 5*12= 60

int Interval = 60;
int BlinkTime = 1;// delay between blink (in seconds)
int reset=13 ; 
int buzz = 12;// pin that controls the buzzer
int LED[] = {3, 4, 5, 6, 7}; //The pins the LED connected to

// Start buzz
int startTune[] = {2637,2637,2637};
int startTuneSize = 3;
int startTuneTempo = 12;

// End buzz 
int endTune[] = {1568, 1568, 1568, 1568, 1568, 2637};
int endTuneSize = 6;
int endTuneTempo = 3;
int i;

// sets the LED and buzzer as outputs
void setup()
{
  
  for(i = 0; i <= 5; i++) // five LEDS
  {
    pinMode(LED[i], OUTPUT);
  }
  pinMode(buzz, OUTPUT);
}

// LED blinking loop with the starting buzz and end buzz
void loop()
{

  playtheTunefunction(startTune, startTuneSize, startTuneTempo);  // the starting buzz

  // For five LEDs the for loop will blink each LED in order 
  
  for(i = 0; i < 5; i++)
  {
    blinkLight(LED[i], BlinkTime, Interval);
    digitalWrite(LED[i], HIGH);
  }
  playtheTunefunction(endTune, endTuneSize, endTuneTempo);
  
// Blinking pattern 
  digitalWrite(LED[0], LOW);
  delay(80);
  digitalWrite(LED[1], LOW);
  delay(80);
  digitalWrite(LED[2], LOW);
  delay(80);
  digitalWrite(LED[3], LOW);
  delay(80);
  digitalWrite(LED[4], LOW);
  delay(80);
  digitalWrite(LED[0], HIGH);
  delay(100);
  digitalWrite(LED[1], HIGH);
  delay(100);
  digitalWrite(LED[2], HIGH);
  delay(100);
  digitalWrite(LED[3], HIGH);
  delay(100);
  digitalWrite(LED[4], HIGH);
  delay(100);
  digitalWrite(LED[4], LOW);
  delay(80);
  digitalWrite(LED[3], LOW);
  delay(80);
  digitalWrite(LED[2], LOW);
  delay(80);
  digitalWrite(LED[1], LOW);
  delay(80);
  digitalWrite(LED[0], LOW);
  delay(80);
  digitalWrite(LED[4], HIGH);
  delay(100);
  digitalWrite(LED[3], HIGH);
  delay(100);
  digitalWrite(LED[2], HIGH);
  delay(100);
  digitalWrite(LED[1], HIGH);
  delay(100);
  digitalWrite(LED[0], HIGH);
  delay(100);
  digitalWrite(LED[0], LOW);
  delay(80);
  digitalWrite(LED[1], LOW);
  delay(80);
  digitalWrite(LED[2], LOW);
  delay(80);
  digitalWrite(LED[3], LOW);
  delay(80);
  digitalWrite(LED[4], LOW);
  delay(80);
  digitalWrite(LED[4], HIGH);
  delay(100);
  digitalWrite(LED[3], HIGH);
  delay(100);
  digitalWrite(LED[2], HIGH);
  delay(100);
  digitalWrite(LED[1], HIGH);
  delay(100);
  digitalWrite(LED[0], HIGH);
  delay(100);
  digitalWrite(LED[0], LOW);
  delay(80);
  digitalWrite(LED[1], LOW);
  delay(80);
  digitalWrite(LED[2], LOW);
  delay(80);
  digitalWrite(LED[3], LOW);
  delay(80);
  digitalWrite(LED[4], LOW);
  delay(80);
  digitalWrite(LED[4], HIGH);
  delay(100);
  digitalWrite(LED[3], HIGH);
  delay(100);
  digitalWrite(LED[2], HIGH);
  delay(100);
  digitalWrite(LED[1], HIGH);
  delay(100);
  digitalWrite(LED[0], HIGH);
  delay(100);
  digitalWrite(LED[0], LOW);
  delay(80);
  digitalWrite(LED[1], LOW);
  delay(80);
  digitalWrite(LED[2], LOW);
  delay(80);
  digitalWrite(LED[3], LOW);
  delay(80);
  digitalWrite(LED[4], LOW);
  delay(80);
  digitalWrite(LED[0], HIGH);
  delay(100);
  digitalWrite(LED[1], HIGH);
  delay(100);
  digitalWrite(LED[2], HIGH);
  delay(100);
  digitalWrite(LED[3], HIGH);
  delay(100);
  digitalWrite(LED[4], HIGH);
  delay(100);
  
  while(digitalRead(reset) != LOW) {} 


}

//Play the tune function
void playtheTunefunction(int tune[], int length, int tempo)
{
  int tunePosition;
  int tuneDuration = 1000 / tempo;

  for (
    tunePosition = 0;
    tunePosition < length;
    tunePosition++
  )
  {
    tone(buzz, tune[tunePosition], tuneDuration);
    delay(tuneDuration);
    delay(tuneDuration * .6);
  }
}


// Blinking LEDs function
void blinkLight(int pin, int blinkLength, int totalBlinkLength) {
  int blinkingtime;
  for (
    blinkingtime = 0;
    blinkingtime < totalBlinkLength;
    blinkingtime += (blinkLength * 2)
  )
  {
    digitalWrite(pin, HIGH);
    delay(blinkLength * 1000);
    digitalWrite(pin, LOW);
    delay(blinkLength * 1000);
  }
}


