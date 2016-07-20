#define IR_THRESH 100
#define MAX_NOISE_AMP 10

int IRVal = 0;

void detectPassenger(){
  if (analogRead(IRLEFT)> IR_THRESH)
  {
    //passenger detected on the left
    //turn on a dime
    motor.speed(LMOTOR, -200);
    motor.speed(RMOTOR, 200);
  }

  if (analogRead(IRRIGHT1)> IR_THRESH)
  {
    if(analogRead(IRRIGHT1)<IRVal){
      hardStop();
      pickupPassenger();
    } else {
      IRVal = analogRead(IRRIGHT1);
    }
  }
}

void pickupPassenger() {
  // adjustGripper();
  adjustChassis();
}

void adjustGripper(){
  int armServo = 0;
  int maxArmServo = 180;
  int armShoulder = analogRead(ARM1);
  int armElbow = analogRead(ARM2);
  int gripIR = analogRead(GRIPPERIR);

  int prevLoIR, prevHiIR;
  int servoSpeed = 5;
  int motorSpeed = 50;

  do {
    RCServo2.write(armServo);
    armServo += servoSpeed;
    if (armServo > maxArmServo)
      break;
    prevLoIR = gripIR - MAX_NOISE_AMP;
    prevHiIR = gripIR + MAX_NOISE_AMP;
    gripIR = analogRead(GRIPPERIR);
  } while (gripIR > prevLoIR && gripIR < prevHiIR);
}

void adjustChassis() {
  int gripIR = analogRead(GRIPPERIR);
  int prevLoIR, prevHiIR;
  int motorSpeed = 50;

  do {
    motor.speed(LMOTOR, motorSpeed);
    motor.speed(RMOTOR, motorSpeed);

    prevLoIR = gripIR - MAX_NOISE_AMP;
    prevHiIR = gripIR + MAX_NOISE_AMP;
    gripIR = analogRead(GRIPPERIR);
  } while (gripIR > prevLoIR && gripIR < prevHiIR);

  hardStop();
}
