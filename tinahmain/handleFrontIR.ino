int handleFrontIR(int servoPos, int IRarray[], int IRlevel) {
  int nextTurn = STRAIGHT;
  IRarray[servoPos / SERVOINC] = IRlevel;

  if (servoPos == SERVOEND) {
    RCservo0.write(SERVOSTART);
    nextTurn = decideTurn(IRarray);
  } else {
    RCservo0.write(servoPos + SERVOINC);
  }

  return nextTurn;
}

