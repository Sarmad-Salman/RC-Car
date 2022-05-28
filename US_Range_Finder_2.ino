const int TRIG_PIN = A1;
const int ECHO_PIN = 4;
const unsigned int MAX_DIST = 23200;
float ultrasonic_dist;
void setup() {
 Serial.begin(9600);
 pinMode(TRIG_PIN, OUTPUT);
 digitalWrite(TRIG_PIN, LOW);
 pinMode(ECHO_PIN, INPUT);

}

void loop() {
unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;
  float inches;
   digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  while ( digitalRead(ECHO_PIN) == 0 );

  t1 = micros();
  while ( digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;
  ultrasonic_dist = pulse_width / 58.0;
  inches = pulse_width / 148.0;
    Serial.println(ultrasonic_dist);
    Serial.print("  ");/*
  if ( pulse_width > MAX_DIST ) {
    Serial.println("Out of range");
  } else {
   
  }*/
  delay(50);
}
