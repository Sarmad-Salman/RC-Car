const int analogInPin = A0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = digitalRead(3);
  Serial.println(sensorValue);
  delay(2);
} 
