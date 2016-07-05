//using:
//DS3231_Serial_Easy
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//a basic implementation of a program that turns an led on at a specific hour  

#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

int red = 11; //this sets the red led pin
int green = 10; //this sets the green led pin
int blue = 9; //this sets the blue led pin
int powerPinLed = 6;//pin for turning led on or off

const int buttonPin = 2; 

int turnOnHour = 14;// the hour that the led is going to turn on

int isItmorning = 0;//is it in the morning or not 

int buttonPressed = 0;

void setup()
{
  // Setup Serial connection
  Serial.begin(115200);
  
  pinMode(buttonPin, INPUT);
  
  //setting up rgb led
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  //pinMode(powerPinLed, INPUT);
  //digitalWrite(powerPinLed, LOW);//no sure if needed ?
  // Initialize the rtc object
  rtc.begin();
}

void loop()
{
  int buttonState = digitalRead(buttonPin);
  int ledPowerState =  digitalRead(powerPinLed);
  
  String currentTime = rtc.getTimeStr();
  String hourChar = currentTime.substring(0,2);
  int hour = hourChar.toInt();
  if(hour > 4 && hour < turnOnHour)
  {
    buttonPressed = 0;
    isItmorning = 1;
  }
  else if(buttonState == LOW)
  {
    buttonPressed = 1;
    turnOff();
  }
   
  
  if(hour >= turnOnHour && ledPowerState == LOW && isItmorning == 0 && buttonPressed == 0)
  {
    setWhite();
  }
  
  // Wait 30 min before repeating
  delay (1000);
}
// turns led on and show an white color 
void setWhite()
{
  //digitalWrite(powerPinLed, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);

}
void turnOff()
{
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue,255);
}

