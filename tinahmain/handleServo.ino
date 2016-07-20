int handleServo(int servoPos, int IRarray[], int IRlevel) {
  int servoOn = 0;
  IRarray[servoPos / SERVOINC] = IRlevel;

  if (servoPos == SERVOEND) {
    servoPos = SERVOSTART;
    servoOn = 0;
    IRdetected = 0;
  } else {
    servoOn = 1;
  }

  return 0;
}

