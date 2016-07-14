int handleServo(int servoPos, int IRarray[], int IRlevel) {
  IRarray[servoPos / SERVOINC] = IRlevel;

  if (servoPos == SERVOEND) {
    servoPos = SERVOSTART;
    servoOn = 0;
    IRdetected = 0;
  } else {

  }

  return servoOn;
}

