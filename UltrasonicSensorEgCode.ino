#define TRIG_PIN 15 
#define ECHO_PIN 17 

float duration_us, distance_cm;//calc distance 

void setup() {
  // begin serial port
  Serial.begin(9600);

  // configure the trigger pin to output mode
  pinMode(TRIG_PIN, OUTPUT);
  // configure the echo pin to input mode
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;//conv duration to distance 

  // print to serial monitor 
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}