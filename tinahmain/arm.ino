void armGetPassenger() {
  armGoTo(ARMLOWIN1, ARMLOWIN2);
  armGoTo(ARMLOWOUT1, ARMLOWOUT2);
  gripperClose();
}

void armDropPassenger() {
  armGoTo(ARMLOWIN1, ARMLOWIN2);
  armGoTo(ARMHIGHIN1, ARMHIGHIN2);
  if (numPassengers >= 2) { 
    armRotate(ARMSERVREST);
    return;
  } else if (numPassengers == 0) {
    armRotate(ARMBOX0);
    gripperOpen();
  } else if (numPassengers == 1) {
    armRotate(ARMBOX1);
    gripperOpen();
  }
  armRotate(45);
  armGoTo(ARMREST1, ARMREST2);
  armRotate(ARMSERVREST); 
}

void armRotate(int angle) {
  RCServo0.write(angle);
}

void armGoTo(int shoulderDest, int elbowDest) {
  int shoulderMin = shoulderDest - ARMTOLERANCE;
  int shoulderMax = shoulderDest + ARMTOLERANCE;
  int elbowMin = elbowDest - ARMTOLERANCE;
  int elbowMax = elbowDest + ARMTOLERANCE;

  int shoulder = analogRead(ARMPOS1);
  int elbow = analogRead(ARMPOS2);
  
  while ((shoulder > shoulderMax) && (shoulder < shoulderMin) 
    && (elbow > elbowMax) && (elbow < elbowMin)){
    if (shoulder > shoulderMax) {
      motor.speed(ARMMOTOR1, ARMSPEEDNEG);
    } else if (shoulder < shoulderMin) {
      motor.speed(ARMMOTOR1, ARMSPEEDPOS);
    } else {
      motor.speed(ARMMOTOR1, 0);
    }
    if (elbow > elbowMax) {
      motor.speed(ARMMOTOR2, ARMSPEEDNEG);
    } else if (elbow < elbowMin) {
      motor.speed(ARMMOTOR2, ARMSPEEDPOS);
    } else {
      motor.speed(ARMMOTOR2, 0);
    }
    shoulder = analogRead(ARMPOS1);
    elbow = analogRead(ARMPOS2);

    if (digitalRead(BGRIPBUMP))
      break;
  }

// in case the motor hit the switch and didn't stop!
  motor.speed(ARMMOTOR1, 0);
  motor.speed(ARMMOTOR2, 0);
}

