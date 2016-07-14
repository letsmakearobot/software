int decideTurn(int IRarray[]) {
  turnDecision = findMax(IRarray, SERVOEND/SERVOINC);

  if (turnDecision > (2.0/3*SERVOEND/SERVOINC))
    turnDecision == RIGHT;
  else if (turnDecision > (1.0/3*SERVOEND/SERVOINC))
    turnDecision == STRAIGHT;
  else
    turnDecision == LEFT;

  return turnDecision;
}

