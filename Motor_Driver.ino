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

  analogWrite (en1, 220);
  analogWrite (en2, 110);
/*
    for (int x=2; x<=7; x++)
    {
      if (x!=3 || x!=5)
      {
      digitalWrite (x,LOW);
      }
    }
  */  
//Forward   
/*    digitalWrite(in1,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in2,LOW);
    lcd.print ("Forward");
    /*for (k = 0; k <= 15; k++)
    {
    lcd.print(" ");
    }
    Serial.println("Forward");
 delay(10000);*/
//Reverse
 /*   digitalWrite(in2,HIGH);
    digitalWrite(in4,HIGH);
    lcd.print ("Backward");
    for (k = 0; k <= 15; k++)
    {
    lcd.print(" ");
    }
    Serial.println("Backward");*/
 
//Left
    digitalWrite(in1,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    
    lcd.print ("Left");
    for (k = 0; k <= 15; k++)
    {
    lcd.print(" ");
    }
    Serial.println("Left");
 
//Right   
   /* digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    lcd.print ("Right");
    for (k = 0; k <= 15; k++)
    {
    lcd.print(" ");
    }
    Serial.println("Right");

//Stop
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    lcd.print ("Stop");
    for (k = 0; k <= 15; k++)
    {
    lcd.print(" ");
    }
    Serial.println("Stop");
  }*/
  delay(1000);
}
