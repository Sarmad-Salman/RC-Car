#include <LiquidCrystal.h>

#define en1 3
#define en2 5
#define in1 2
#define in2 4
#define in3 6
#define in4 7
#define en 11
#define rs 13
#define d4 12
#define d5 10
#define d6 9
#define d7 8

int k;
char dir;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  for (int i=2; i<=13; i++)
  {
  pinMode(i,OUTPUT);
  } 
  
  Serial.begin(9600);
  
  lcd.begin (16,2);
  
  lcd.print (" HOST  18273334 ");

  
}

void loop() {
  lcd.setCursor(0,1);
    
  if (Serial.available()>0)
  {
    dir = Serial.read();

    analogWrite (en1, 170);
    analogWrite (en2, 255);
  
    if(dir == 'F')
    {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    lcd.print ("Forward");
    for (k = 0; k <= 15; k++)
    {
    lcd.print(" ");
    }
    Serial.println("Forward");
    }
 
    else if(dir == 'B')
    {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    lcd.print ("Backward");
    for (k = 0; k <= 15; k++)
    {
    lcd.print(" ");
    }
    Serial.println("Backward");
    }
 
    else if(dir == 'R')
    {
    analogWrite(en1,80);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    lcd.print ("Right");
    for (k = 0; k <= 15; k++)
    {
    lcd.print(" ");
    }
    Serial.println("Right");
    }
 
    else if(dir == 'L')
    {      
    analogWrite(en2,80);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    lcd.print ("Left");
    for (k = 0; k <= 15; k++)
    {
    lcd.print(" ");
    }
    Serial.println("Left");
    }

    else if(dir=='S')
    {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    lcd.print ("Stop");
    for (k = 0; k <= 15; k++)
    {
    lcd.print(" ");
    }
    Serial.println("Stop");
    }
  }
  delay(100);
}
