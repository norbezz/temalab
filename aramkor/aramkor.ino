#include <Servo.h>

Servo myservo;

int pos = 0;
int left = LOW;
int right = LOW;
int led = 4;
int onboard_led = 2;
int leftbutton = 12;
int rightbutton = 13;
int servomotor = 15;

void setup() {
  pinMode(rightbutton, INPUT);
  pinMode(leftbutton, INPUT);
  pinMode(servomotor, OUTPUT);
  pinMode(onboard_led, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(onboard_led,HIGH);
  myservo.attach(servomotor);
  myservo.write(90);
}
void loop() {left = digitalRead(leftbutton);
  if (left == HIGH) {
    digitalWrite(led,HIGH);
    for (pos = 90; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 90; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
    digitalWrite(led,LOW);
  }
  myservo.write(90);
  right = digitalRead(rightbutton);
  if (right == HIGH) {
    digitalWrite(onboard_led,LOW);
    for (pos = 90; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
    for (pos = 0; pos <= 90; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
    digitalWrite(onboard_led,HIGH);
  }
  myservo.write(90);
}
