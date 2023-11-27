#define IR_SENSOR_right 2
#define IR_SENSOR_medright 4
#define IR_SENSOR_medleft 7
#define IR_SENSOR_left 8
#define MOTOR_SPEED 180

//Left motor
int enableLeftMotor=10;
int leftMotorPin1=9;
int leftMotorPin2=6;

//Right motor
int enableRightMotor=11;
int rightMotorPin1=5;
int rightMotorPin2=3;

void setup()
{
  TCCR0B = TCCR0B & B11111000 | B00000010 ;
  
  // put your setup code here, to run once:
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_right, INPUT);
  pinMode(IR_SENSOR_medright, INPUT);
  pinMode(IR_SENSOR_medleft, INPUT);
  pinMode(IR_SENSOR_left, INPUT);
  rotateMotor(0,0);   
}


void loop()
{

  int rightIRSensorValue = digitalRead(IR_SENSOR_right);
  int medrightIRSensorValue = digitalRead(IR_SENSOR_medright);
  int medleftIRSensorValue = digitalRead(IR_SENSOR_medleft);
  int leftIRSensorValue = digitalRead(IR_SENSOR_left);

  if (leftIRSensorValue == HIGH && medleftIRSensorValue == HIGH && medrightIRSensorValue == HIGH && rightIRSensorValue == HIGH )
  {
    rotateMotor( 0 , 0 );
  }
  else if (leftIRSensorValue == LOW && medleftIRSensorValue == LOW && medrightIRSensorValue == LOW  && rightIRSensorValue == HIGH )
  {
      rotateMotor(150,-150); 
  }
   else if (leftIRSensorValue == LOW && medleftIRSensorValue == LOW && medrightIRSensorValue == LOW  && rightIRSensorValue == LOW )
  {
      rotateMotor(-150,-150); 
  } 
   else if (leftIRSensorValue == LOW && medleftIRSensorValue == LOW && medrightIRSensorValue == HIGH && rightIRSensorValue == LOW )
  {
      rotateMotor( 1,-150 ); 
  } 
   else if (leftIRSensorValue == LOW && medleftIRSensorValue == LOW && medrightIRSensorValue == HIGH && rightIRSensorValue == HIGH )
  {
      rotateMotor(150, -150); 
  }
   else if (leftIRSensorValue == LOW && medleftIRSensorValue == HIGH && medrightIRSensorValue == LOW && rightIRSensorValue == LOW )
  {
      rotateMotor(-150, 1 ); 
  }
   else if (leftIRSensorValue == LOW && medleftIRSensorValue == HIGH && medrightIRSensorValue == LOW && rightIRSensorValue == HIGH )
  {
      rotateMotor(150, -150); 
  }
   else if (leftIRSensorValue == LOW && medleftIRSensorValue == HIGH && medrightIRSensorValue == HIGH && rightIRSensorValue == LOW )
  {
      rotateMotor(-150, -150); 
  }
   else if (leftIRSensorValue == LOW && medleftIRSensorValue == HIGH && medrightIRSensorValue == HIGH && rightIRSensorValue == HIGH )
  {
      rotateMotor(150, -150); 
  }
   else if (leftIRSensorValue == HIGH && medleftIRSensorValue == LOW && medrightIRSensorValue == LOW && rightIRSensorValue == LOW )
  {
      rotateMotor(-150, 150); 
  }
   else if (leftIRSensorValue == HIGH && medleftIRSensorValue == LOW && medrightIRSensorValue == HIGH && rightIRSensorValue == LOW )
  {
      rotateMotor(-150, 150); 
  }
  else if (leftIRSensorValue == HIGH && medleftIRSensorValue == HIGH && medrightIRSensorValue == HIGH && rightIRSensorValue == LOW )
  {
      rotateMotor(-150, 150); 
  }
  else if (leftIRSensorValue == HIGH && medleftIRSensorValue == HIGH && medrightIRSensorValue == LOW && rightIRSensorValue == LOW )
  {
      rotateMotor(-150, 150); 
  }
  else 
  {
    rotateMotor(0, 0);
  }
}


void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}
