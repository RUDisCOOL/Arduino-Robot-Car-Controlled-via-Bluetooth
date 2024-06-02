# Arduino Bluetooth Robot Car

This is a project that I have created as an IoT Project for my University.
<p align="center">
<img src="/assets/images/image2.png" width=250px alt="side-view-of-car"/>
<img src="/assets/images/image1.png" width=250px alt="top-view-of-car"/>
</p>

## Introduction

- In this project we have created a car which is controlled via Bluetooth using a Smartphone.
- This project helps us to understand the working of Bluetooth module and using it with motors and Arduino board.
- It is a great project for learning basics of Arduino board, Motor Driver and using the Adafruit Motor Library.

## Components

- Arduino Uno R3
- L293d Motor Driver
- HC-05 Bluetooth Module
- 18650 Lithium-Ion Battery
- Gear Motors
- Wheels
- Jumper Wires

## Circuit Diagram

<img src="/assets/images/circuit_diagram.png" alt="circuit-diagram">

## Working

- Initially we have to connect our Bluetooth module with our Smartphone via "Arduino Bluetooth" application.
- Then using the controller feature of the application we can press buttons to control our car.
- For each button pressed the application sends an character to the Bluetooth module.
- The Arduino will select a function based on the character it received from the Bluetooth module.
- Then the L293d motor driver is responsible for controlling the motors and moving the car accordingly.
- The Arduino Bluetooth application sends a '0' character if a button is released.
- If the Arduino receives the '0' character it commands the Motor Driver to stop running the motors.

## Code

> **Note:** This code is already available in the [_IoT_Project.ino_](/IoT_Project.ino) file.

Here is the arduino code to receive the characters sent by the mobile application to the Bluetooth Module:

```
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
```

## Conclusion

- Our project demonstrates the integration of Arduino, motor control, and Bluetooth technology in a practical application.
- Through hands-on experience, we've gained proficiency in programming fundamentals and hardware interfacing.
- This project enhances our understanding of electronics and robotics, particularly in the context of real-world applications.
- Looking ahead, we're eager to apply these skills to future projects, leveraging our knowledge for further innovation.
- Overall, our Bluetooth-controlled car project signifies our commitment to learning and exploring new frontiers in technology.
