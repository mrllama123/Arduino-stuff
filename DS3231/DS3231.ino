//using:
//DS3231_Serial_Easy
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//a basic implementation of a program that turns an led on at a specific hour  

#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

int red = 11; //this sets the red led pin
int green = 12; //this sets the green led pin
int blue = 13; //this sets the blue led pin

int turnOnHour = 14;// the hour that the led is going to turn on

void setup()
{
  // Setup Serial connection
  Serial.begin(115200);
  //setting up rgb led
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  // Initialize the rtc object
  rtc.begin();
}

void loop()
{
  String currentTime = rtc.getTimeStr();
  String hourChar = currentTime.substring(0,2);
  int hour = hourChar.toInt();
  if(hour >= turnOnHour)
  {
    setWhite();
  }
  // Wait 30 min before repeating
  delay (60000);
}
// turns led on and show an white color 
void setWhite()
{
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);

}

