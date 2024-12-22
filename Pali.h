#define AIN1 5 //Forward A
#define AIN2 9 //Backward A
#define BIN1 10 //Forward B
#define BIN2 11 //Backward B

//-----MOTOR-----//

void motor(int8_t L , int8_t R)
{
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);

    L = constrain(L, -100, 100);
    R = constrain(R, -100, 100);

    uint8_t speedL;
    uint8_t speedR;

    if (L > 0)
    {
        speedL = map(L, 0, 100, 0, 255);
    }
    else 
    {
        speedL = map(L, -0, -100, 0, 255);
    }
    if (R > 0)
    {
        speedR = map(R, 0, 100, 0, 255);
    }
    else
    {
        speedR = map(R, -0, -100, 0, 255);
    }

    if (L > 0)
    {
        analogWrite(5, 0);
        analogWrite(6, speedL);
    }
    else
    {
        analogWrite(5, speedL);
        analogWrite(6, 0);
    }
    if (R > 0)
    {
        analogWrite(9, 0);
        analogWrite(10, speedR);
    }
    else
    {
        analogWrite(9, speedR);
        analogWrite(10, 0);
    }
    if (L == 0)
    {
        analogWrite(5, 255);
        analogWrite(6, 255);
    }
    else if (R == 0)
    {
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
    motor(speed,speed);
}

void fd2(uint8_t speedL , uint8_t speedR)
{
    motor(speedL,speedR);
}

void bk(uint8_t speed)
{
    motor(-speed,-speed);
}

void bk2(uint8_t speedL , uint8_t speedR)
{
    motor(-speedL,-speedR);
}

void sl(uint8_t speed)
{
    motor(-speed,speed);
}

void sr(uint8_t speed)
{
    motor(speed,-speed);
}

void tl(uint8_t speed)
{
    motor(0,speed);
}

void tr(uint8_t speed)
{
    motor(speed,0);
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
  while(!digitalRead(2));
  while(digitalRead(2));
}