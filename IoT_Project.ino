#include <AFMotor.h>
//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int x;

char command = '0';
char state = '0';
unsigned long prevTime = millis();
unsigned long currTime;

void setup() {
  Serial.begin(9600);
  stop();
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    state = command == 'F' || command == 'B' ? command : state;
    directionSelector();
  }

  currTime = millis();
  if (currTime - prevTime >= 200) {
    if (x <= 235) {
      x += 10;
      directionSelector();
    }
    prevTime = currTime;
  }
}

void directionSelector() {
  if (state == 'F' && command == 'O') {
    topRight();
  } else if (state == 'F' && command == 'I') {
    topLeft();
  } else if (state == 'B' && command == 'I') {
    bottomLeft();
  } else if (state == 'B' && command == 'O') {
    bottomRight();
  } else if (command == 'F') {
    forward();
  } else if (command == 'B') {
    back();
  } else if (command == 'L') {
    left();
  } else if (command == 'R') {
    right();
  } else if (command == 'O') {
    topRight();
  } else if (command == 'I') {
    topLeft();
  } else if (command == 'D') {
    bottomLeft();
  } else if (command == 'S') {
    bottomRight();
  } else if (command == '0') {
    state = '0';
    stop();
  } else if (command == '1') {
    state == 'F' ? forward() : state == 'B' ? back()
                                            : stop();
  }
}

void bottomRight() {

  motor1.setSpeed(x);
  motor1.run(BACKWARD);
  motor2.setSpeed(x);
  motor2.run(BACKWARD);
  motor3.setSpeed(x);
  motor3.run(FORWARD);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
void bottomLeft() {
  motor1.setSpeed(x);
  motor1.run(FORWARD);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(x);
  motor3.run(BACKWARD);
  motor4.setSpeed(x);
  motor4.run(BACKWARD);
}
void topRight() {
  motor1.setSpeed(x);
  motor1.run(FORWARD);
  motor2.setSpeed(x);
  motor2.run(FORWARD);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(x);
  motor4.run(BACKWARD);
}
void topLeft() {
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(x);
  motor2.run(BACKWARD);
  motor3.setSpeed(x);
  motor3.run(FORWARD);
  motor4.setSpeed(x);
  motor4.run(FORWARD);
}
void forward() {
  motor1.setSpeed(x);
  motor1.run(FORWARD);
  motor2.setSpeed(x);
  motor2.run(FORWARD);
  motor3.setSpeed(x);
  motor3.run(FORWARD);
  motor4.setSpeed(x);
  motor4.run(FORWARD);
}
void back() {
  motor1.setSpeed(x);
  motor1.run(BACKWARD);
  motor2.setSpeed(x);
  motor2.run(BACKWARD);
  motor3.setSpeed(x);
  motor3.run(BACKWARD);
  motor4.setSpeed(x);
  motor4.run(BACKWARD);
}
void right() {
  motor1.setSpeed(x);
  motor1.run(FORWARD);
  motor2.setSpeed(x);
  motor2.run(FORWARD);
  motor3.setSpeed(x);
  motor3.run(BACKWARD);
  motor4.setSpeed(x);
  motor4.run(BACKWARD);
}
void left() {
  motor1.setSpeed(x);
  motor1.run(BACKWARD);
  motor2.setSpeed(x);
  motor2.run(BACKWARD);
  motor3.setSpeed(x);
  motor3.run(FORWARD);
  motor4.setSpeed(x);
  motor4.run(FORWARD);
}
void stop() {
  x = 145;
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}