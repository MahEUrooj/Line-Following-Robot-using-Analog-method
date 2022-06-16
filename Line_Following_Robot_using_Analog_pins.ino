#define LeftMotorReverse 3
#define LeftMotorForward 5
#define RightMotorForward 6
#define RightMotorReverse 9

#define leftIR A0
#define rightIR A1

void setup() {
  // put your setup code here, to run once:
  pinMode(LeftMotorForward,OUTPUT);
  pinMode(RightMotorForward,OUTPUT);
  pinMode(LeftMotorReverse,OUTPUT);
  pinMode(RightMotorReverse,OUTPUT);
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(leftIR) < 500 && analogRead(rightIR) < 500)//Forward
  {
    digitalWrite(LeftMotorForward,150);
    digitalWrite(RightMotorForward, 150);
  }

  else if(analogRead(leftIR) <150 && analogRead(rightIR)>= 500) //Right
  {
    analogWrite(LeftMotorForward,130);
    analogWrite(RightMotorForward,LOW);
  }
  else if(analogRead(leftIR)>=500 && analogRead(rightIR)<500)//Left
  {
    analogWrite(LeftMotorForward,LOW);
    analogWrite(RightMotorForward,130);
  }
  else if(analogRead(leftIR)>= 500 && analogRead(rightIR) >=500)//Stop
  {
    analogWrite(LeftMotorForward,LOW);
    analogWrite(RightMotorForward,LOW);
  }
  delay(1);
}
