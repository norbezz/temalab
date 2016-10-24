#include <Servo.h>

Servo myservo;

int pos = 0;
int left = LOW;
int right = LOW;
int leftbutton = 12;
int rightbutton = 13;
int servomotor = 15;

void setup() {
  pinMode(rightbutton, INPUT);
  pinMode(leftbutton, INPUT);
  pinMode(servomotor, OUTPUT);
  myservo.attach(servomotor);
}
void loop() {
  left = digitalRead(leftbutton);
  if (left == HIGH){
    for (pos = 0; pos <= 180; pos += 1) {
      // in steps of 1 degree
      myservo.write(pos);
      delay(15);
    }
  }
  left = LOW;
  right = digitalRead(rightbutton);
  if(right == HIGH){
    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
  right = LOW;
}
