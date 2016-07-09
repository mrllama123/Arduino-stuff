int pinOut = 8; // turns relay on and off
void setup() {
  pinMode(pinOut, OUTPUT);

}

void loop() {
  //basic funtion that turns relay on and off every 3 seconds 
  digitalWrite(pinOut, LOW);
  delay(3000);
  digitalWrite(pinOut, HIGH);
  delay(3000);

}
