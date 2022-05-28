#define trigPin A0
#define echoPin 3

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  }
  
void loop() {
  float duration, distance;

//Generating Pulse for Sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
 // delayMicroseconds(10);
//  digitalWrite(trigPin, HIGH);

//Receiving, Measuring and Displaying Sensor Value
  duration = pulseIn(echoPin, HIGH);  // MicroSeconds
  distance = (duration / 2) * 0.03313;  // Cm
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");    
}
