#include <Servo.h>

Servo RightHip;
Servo RightAnkle;
Servo LeftHip;
Servo LeftAnkle;

int initialRH = 90;
int initialRA = 90;
int initialLH = 80;
int initialLA = 95;

int oppositeKick = 10;
int liftAngle = 35;
int twistAngle = 20;

void setup() {
  RightHip.attach(9);  
  RightAnkle.attach(8);
  LeftHip.attach(6);
  LeftAnkle.attach(7);
  RightHip.write(initialRH);  
  RightAnkle.write(initialRA);
  LeftAnkle.write(initialLA);
  LeftHip.write(initialLH);
  delay(2000);
}

void loop() {
  
  LeftAnkle.write(initialLH - oppositeKick);
  SweepNegative(RightAnkle, initialRA, initialRA - liftAngle);
  LeftHip.write(initialLH);
  LeftAnkle.write(initialLA);
  SweepNegative(RightHip, initialRH, initialRH - twistAngle);  
  SweepPositive(RightAnkle, initialRA - liftAngle, initialRA);
  delay(200);
  RightAnkle.write(initialRA + oppositeKick);
  SweepPositive(LeftAnkle, initialLA, initialLA + liftAngle);
  RightHip.write(initialRH);
  RightAnkle.write(initialRA);
  SweepPositive(LeftHip, initialLH, initialLH + twistAngle); 
  SweepNegative(LeftAnkle, initialLA + liftAngle, initialLA);
  delay(200);
    
}

void SweepPositive(Servo myservo, int from, int to){
  for (pos = from; pos <= to; pos += 5) { 
    myservo.write(pos);
    delay(15);
  }
}

void SweepNegative(Servo myservo, int from, int to){
  for (pos = from; pos >= to; pos -= 5) { 
    myservo.write(pos);
    delay(15);
  }
}
