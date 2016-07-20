void handleIntersect() {  
  int lTape = !digitalRead(LTAPE);
  int rTape = !digitalRead(RTAPE);
  
  int lInt = !digitalRead(LINTTAPE);
  int rInt = !digitalRead(RINTTAPE);
  int temp;

  if (!lInt && !rInt) {
    return;
  }
  
  if (lInt) {
    // turn left
    LCD.clear();
    LCD.print("hard left!");
    motor.speed(LMOTOR, 300);
    motor.speed(RMOTOR, 0);
    delay(150);
    while(!digitalRead(LTAPE)) {
      motor.speed(LMOTOR, 300);
      motor.speed(RMOTOR, 0);
    }
    temp = nodeMap[lastNode][nextNode][0];
    lastNode = nextNode;
    nextNode = temp;
  } else if (rInt) {
    // turn right
    LCD.clear();
    LCD.print("hard right!");
    motor.speed(RMOTOR, 300);
    motor.speed(LMOTOR, 0);
    delay(150);    
    while(!digitalRead(RTAPE)) {
      motor.speed(RMOTOR, 300);
      motor.speed(LMOTOR, 0);
    }
    temp = nodeMap[lastNode][nextNode][1];
    lastNode = nextNode;
    nextNode = temp;
  } 
}
