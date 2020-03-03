#include<LiquidCrystal.h>

int sensorValue;

LiquidCrystal led(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  
  led.begin(16, 2);
  led.print("CAN BUS Test");
}

void loop()
{
  int buttonState = digitalRead(8);
  Serial.println(buttonState);
  delay(1000);
  
  digitalWrite(8, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(8, LOW);
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1000);
  
}