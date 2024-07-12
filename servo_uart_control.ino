#include <Servo.h>

Servo myServo;
const int servoPin = D8;
const int servoOnPos = 0;
const int servoOffPos = 140;

void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin);
  Serial.println("Enter 'ON' to move the servo to 0 degrees or 'OFF' to move it to 140 degrees");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove any whitespace or newline characters

    if (input.equalsIgnoreCase("ON")) {
      myServo.write(servoOnPos);
      Serial.println("Servo moved to 0 degrees");
    } else if (input.equalsIgnoreCase("OFF")) {
      myServo.write(servoOffPos);
      Serial.println("Servo moved to 140 degrees");
    } else {
      Serial.println("Invalid input. Enter 'ON' or 'OFF'");
    }
  }
}
