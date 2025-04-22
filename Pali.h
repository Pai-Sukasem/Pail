#include <Servo.h>

int servo_pins[] = { 14, 15, 16 }; // A0, A1, A2
Servo myServo[3]; // 3 servos

//-----MOTOR-----//
void motor(int8_t L , int8_t R)
{
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);

    L = constrain(L, -100, 100);
    R = constrain(R, -100, 100);

    uint8_t speedL = map(abs(L), 0, 100, 0, 255);
    uint8_t speedR = map(abs(R), 0, 100, 0, 255);

    // Left motor control
    if (L > 0) {
        analogWrite(5, 0);
        analogWrite(6, speedL);
    } else {
        analogWrite(5, speedL);
        analogWrite(6, 0);
    }

    // Right motor control
    if (R > 0) {
        analogWrite(9, 0);
        analogWrite(10, speedR);
    } else {
        analogWrite(9, speedR);
        analogWrite(10, 0);
    }

    // Stop motors if either L or R is zero
    if (L == 0) {
        analogWrite(5, 255);
        analogWrite(6, 255);
    }
    if (R == 0) {
        analogWrite(9, 255);
        analogWrite(10, 255);
    }
}

void motor_stop()
{
    analogWrite(5, 255);
    analogWrite(6, 255);
    analogWrite(9, 255);
    analogWrite(10, 255);
}

void fd(uint8_t speed)
{
    motor(speed, speed);
}

void fd2(uint8_t speedL , uint8_t speedR)
{
    motor(speedL, speedR);
}

void bk(uint8_t speed)
{
    motor(-speed, -speed);
}

void bk2(uint8_t speedL , uint8_t speedR)
{
    motor(-speedL, -speedR);
}

void sl(uint8_t speed)
{
    motor(-speed, speed);
}

void sr(uint8_t speed)
{
    motor(speed, -speed);
}

void tl(uint8_t speed)
{
    motor(0, speed);
}

void tr(uint8_t speed)
{
    motor(speed, 0);
}

void ao()
{
    motor_stop();
}

//-----I/O PIN-----//
int analog(uint8_t ch)
{
    ch = constrain(ch, 0, 7);
    return analogRead(A0 + ch);
}

int in(uint8_t ch)
{
    ch = constrain(ch, 0, 7);
    return digitalRead(A0 + ch);
}

//-----Switch-----//
void waitSW_OK(void)
{
    while(!digitalRead(2)); // Wait until switch is pressed
    while(digitalRead(2));  // Wait until switch is released
}

//-----Servo-----//
void servo(char n, signed int angle)
{
    if (n < 1 || n > 3) {
      return; // Invalid servo number
    }

    n -= 1; // Convert 1-3 to 0-2

    if (angle == -1) {
      myServo[n].detach();
    } else {
      if (!myServo[n].attached()) {
        myServo[n].attach(servo_pins[n]);
      }
      myServo[n].write(angle);
    }
}
