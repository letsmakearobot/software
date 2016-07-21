void armLowExtend() {
  armGoTo(ARMLOWIN1, ARMLOWIN2);
  armGoTo(ARMLOWOUT1, ARMLOWOUT2);
}

void armLowRetract() {
  armGoTo(ARMLOWOUT1, ARMLOWOUT2);  
  armGoTo(ARMLOWIN1, ARMLOWIN2);
}
void armDropPassenger() {
  
}

void armRaise() {

}

void armGoTo(int shoulderDest, int elbowDest) {
  int shoulderMin = shoulderDest - ARMTOLERANCE;
  int shoulderMax = shoulderDest + ARMTOLERANCE;
  int elbowMin = elbowDest - ARMTOLERANCE;
  int elbowMax = elbowDest + ARMTOLERANCE;

  int shoulder = analogRead(ARMPOS1);
  int elbow = analogRead(ARMPOS2);
  
  while ( (shoulder > shoulderMax) && (shoulder < shoulderMin) 
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
  }
}

