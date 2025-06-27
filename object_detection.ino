#include <Servo.h>
long time;
int distance;

const int trigPin = 10;
const int echoPin = 9; 

Servo servo1;
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  servo1.attach(8);
  servo1.write(0);
  Serial.begin(115200);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time = pulseIn(echoPin, HIGH);
  distance = time * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance<10){
    servo1.write(180);
  } else {
    servo1.write(0);
  }
  delay(50);
}