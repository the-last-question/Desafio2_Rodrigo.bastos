// code arduino2

#include<string.h>
#include<SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
String distancia;

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available())
  { 	
    delay(100);
    distancia = Serial.readString();
    Serial.flush();
    lcd.print(distancia); 
    delay(4000);
    lcd.clear();
  }    
}
