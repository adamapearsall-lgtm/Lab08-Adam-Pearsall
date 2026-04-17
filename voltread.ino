#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


int voltage = A0;


void setup() {
  Serial.begin(9600);
  pinMode(voltage, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}
void loop() {
  int voltageRead = analogRead(voltage);
  Serial.println(voltageRead);
  float voltageCalc = (5.0/1023) * voltageRead;
  Serial.println(voltageCalc);
  lcd.print("Voltage:");
  lcd.print(voltageCalc);
  
  delay(500);
  lcd.clear();


}
