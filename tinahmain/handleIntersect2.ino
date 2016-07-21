void handleIntersect2() {
  int temp;
  int lInt = !digitalRead(LINTTAPE);
  int rInt = !digitalRead(RINTTAPE);

  boolean front = (nodeMap[lastNode][nextNode][STRAIGHT] != -1);
  boolean left = (nodeMap[lastNode][nextNode][LEFT] != -1);
  boolean right = (nodeMap[lastNode][nextNode][RIGHT] != -1);

  int intersect = scanIntersection(right, left, front);

  if(intersect == LEFT) {
    hardLeft();
    temp = nodeMap[lastNode][nextNode][0];
    lastNode = nextNode;
    nextNode = temp;
  }
  else if(intersect == RIGHT) {
    hardRight();
    temp = nodeMap[lastNode][nextNode][1];
    lastNode = nextNode;
    nextNode = temp;
  }
  else{
    temp = nodeMap[lastNode][nextNode][2];
    lastNode = nextNode;
    nextNode = temp;
  }
}

// scan intersection with IR detectors to choose the one with highest intensity
int scanIntersection(boolean right, boolean left, boolean front){
  int lIntIr = -1;
  int rIntIr = -1;
  int fIntIr = -1;

  if(left){
    lIntIr = analogRead(IRFRONTLEFT);
  }
  if(right){
    rIntIr  = analogRead(IRFRONTRIGHT);
  }
  if(front){
    fIntIr = analogRead(IRFRONT);
  }
  int Irs[3] = {lIntIr, rIntIr, fIntIr};
  return findMax(Irs, 3);
}
