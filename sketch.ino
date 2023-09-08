#include <Arduino.h>


const int ledPins[] = {13,12,14,27,26,25,33,32,18,19,23};
const int numLeds = 11;


const int swLeftPin = 4; 
const int swRightPin = 2;

int currentLed = 0;
int leftButton = 0;
int rightButton = 0;

int size = sizeof(ledPins)/sizeof(ledPins[0]);
void setup() 
{
  pinMode(swLeftPin, INPUT_PULLUP);
  pinMode(swRightPin, INPUT_PULLUP);

  for(currentLed = 0; currentLed < size; currentLed++)
  {
    pinMode(ledPins[currentLed], OUTPUT);
  }
  currentLed = -1;
}

void loop() 
{
  
  leftButton = digitalRead(swLeftPin);
  rightButton = digitalRead(swRightPin);
  
  if(rightButton == LOW)
  {
    digitalWrite(ledPins[currentLed++ % size], LOW);
    delay(100);
    digitalWrite(ledPins[currentLed % size], HIGH);
    delay(100);
  }

  if(leftButton == LOW)
  {
    digitalWrite(ledPins[currentLed-- % size], LOW);
    delay(100);
    if(currentLed<0)
      currentLed = size - 1;
    digitalWrite(ledPins[currentLed % size], HIGH);
    delay(100);
  }
  
}
