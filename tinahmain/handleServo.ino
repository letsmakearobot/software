void handleServo(){
  IRlevels[servoPos / SERVOINC] = IRlevel;

  if (servoPos == SERVOSTART) {
    RCServo0.write(servoPos);
    servoOn = true;
    servoPos += SERVOINC;
  }

  if (servoPos == SERVOEND) {
    servoOn = 0;
    IRdetected = 0;
    turnDecision = findMax(IRlevels, SERVOEND/SERVOINC);

    if (turnDecision > (2.0/3*SERVOEND/SERVOINC))
      turnDecision == RIGHT;
    else if (turnDecision > (1.0/3*SERVOEND/SERVOINC))
      turnDecision == STRAIGHT;
    else
      turnDecision == LEFT;
  }
}

