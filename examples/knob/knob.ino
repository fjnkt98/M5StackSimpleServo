#include <M5Stack.h>
#include "m5stack_simple_servo.h"

M5StackSimpleServo myservo(3, 1.0, 2.0);

void setup() {
  // hardware initialization
  M5.begin();
  M5.Power.begin();
  M5.Lcd.print("Servo Test!!");

  // attaches the servo on GPIO5 pin of M5Stack
  myservo.attach(5);
}

void loop() {
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
}
