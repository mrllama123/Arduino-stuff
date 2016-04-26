#include <LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);
void setup() {
  // initalise lcd 
  lcd.begin(16,2);
  lcd.print("llama pi");
}

void loop() {
  // put your main code here, to run repeatedly:

}
