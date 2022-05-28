#define trigPin2 10
#define echoPin2 A0
#define trigPin1 11
#define echoPin1 A1
#define In1 1
#define In2 2
#define In3 3
#define In4 4
#define EnA A2
#define EnB A3

int max=200;
int nolimit=500;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  analogWrite(EnA, 255);
  analogWrite(EnB,255);
  }
  
void loop() {
  float duration1, distance1, duration2, distance2;
  
//Generating Pulse for Sensor 1
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
//Generating Pulse for Sensor 2
  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

//Receiving, Measuring and Displaying Sensor 1 Value
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) * 0.03313;
  Serial.print("Distance = ");
  Serial.print(distance1);
  Serial.println(" cm");
  delay(500);
  
//Receiving, Measuring and Displaying Sensor 2 Value
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) * 0.03313;
  Serial.print("Distance = ");
  Serial.print(distance2);
  Serial.println(" cm");
  delay(500);

//Applying Condition for Right
    if (distance2>=max) {
      digitalWrite(In1,LOW);
      digitalWrite(In2,HIGH);
      digitalWrite(In3,HIGH);
      digitalWrite(In4,LOW);
      delay(100);
    }

//Applying Condition for Forward
    if (distance1>=max){
      digitalWrite(In1,HIGH);
      digitalWrite(In2,LOW);
      digitalWrite(In3,HIGH);
      digitalWrite(In4,LOW);
      delay(100);
   }
   
//Applying Condition for Left
    if (distance1<max && distance2<max){
      digitalWrite(In1,HIGH);
      digitalWrite(In2,LOW);
      digitalWrite(In3,LOW);
      digitalWrite(In4,HIGH);
      delay(100);
    }
    
//Applying Condition for Stop
    if (distance1>nolimit && distance2>nolimit){
      digitalWrite(In1,LOW);
      digitalWrite(In2,LOW);
      digitalWrite(In3,LOW);
      digitalWrite(In4,LOW);
      delay(100);
    }
    
}
