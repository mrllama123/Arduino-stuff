
//
#include <Wire.h>


int ledcolor = 0;
int a = 1000; //this sets how long the stays one color for
int red = 11; //this sets the red led pin
int green = 12; //this sets the green led pin
int blue = 13; //this sets the blue led pin


void setup() { 
  //

  
  
  //this sets the output pins
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
}

void loop() {
  
  setWhite();

}

void setWhite() {
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
 
}




//
