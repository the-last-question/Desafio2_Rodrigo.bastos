// C++ code

// vsom = 340,29 m/s
// D = v . t
// trigger = pin output
// echo = pin input
//HIGH = 5v & LOW = 0v

#include <SoftwareSerial.h>

const int trigger = 12;
const int echo = 13;

int verde = 5;
int azul = 6;
int vermelho = 7;

float distance;

void verdeLed()
{
  digitalWrite(verde,HIGH);
  digitalWrite(azul,LOW);
  digitalWrite(vermelho,LOW);
}

void amareloLed()
{
  digitalWrite(verde,50);
  digitalWrite(azul,0);
  digitalWrite(vermelho,255);
  
  
}

void vermelhoLed()
{
  digitalWrite(verde,LOW);
  digitalWrite(azul,LOW);
  digitalWrite(vermelho,HIGH);
}

void setup()
{
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(verde,OUTPUT);
  pinMode(azul,OUTPUT);
  pinMode(vermelho,OUTPUT);
  
  Serial.begin(9600); 
  
}

void loop()
{
  
  digitalWrite(trigger, LOW);
  delay(0005);
  digitalWrite(trigger, HIGH);
  delay(0010);
  digitalWrite(trigger, LOW);
  
 distance =  pulseIn(echo, HIGH);
 distance = distance / 58;
  
  if(distance >= 3 && distance < 110)
   vermelhoLed(); 
  
  else if(distance >=110 && distance < 220)
   amareloLed(); 

  else if(distance>220)
   verdeLed(); 
  
 Serial.print("distance: ");
 Serial.print(distance); 
 Serial.println(" cm");

}
//conectar cabos do Lcd
//fazer a conexão entre arduino1 e arduino2
//passar os dados obtidos no sensor HC-SR04 para o arduino2
