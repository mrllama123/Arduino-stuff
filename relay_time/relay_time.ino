//using:
//DS3231_Serial_Easy
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//a basic implementation of a program that turns an led on at a specific hour  

#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);



int relayPin = 8; 

int buttonPin = 2; 

int turnOnHour = 14;// the hour that the led is going to turn on

int isItmorning = 0;//is it in the morning or not 

int buttonPressed = 0;

void setup()
{
  // Setup Serial connection
  Serial.begin(115200);
  
  pinMode(buttonPin, INPUT);
  

  
  //setting up relay 
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  
  
  //digitalWrite(powerPinLed, LOW);//no sure if needed ?
  // Initialize the rtc object
  rtc.begin();
}

void loop()
{
  int buttonState = digitalRead(buttonPin);
  
  String currentTime = rtc.getTimeStr();
  String hourChar = currentTime.substring(0,2);
  String minuteChar = currentTime.substring(3,5);
  int minutes = minuteChar.toInt();
  int hour = hourChar.toInt();
  //every 30 min send temp info to computer via serial
  
  if(minutes == 30)
  {
     Serial.print(rtc.getTemp());
     delay(1000);
  }
  //Serial.println(rtc.getTemp());
  if(hour > 4 && hour < turnOnHour)
  {
    buttonPressed = 0;
    isItmorning = 1;
  }
  else if(buttonState == LOW)
  {
    buttonPressed = 1;
    digitalWrite(relayPin, LOW);
  }
   
  
  if(hour >= turnOnHour && isItmorning == 0 && buttonPressed == 0)
  {
    digitalWrite(relayPin, HIGH);
  }
  
  // Wait 1 second before repeating
  //delay (1800000);
  delay(4000);
}


