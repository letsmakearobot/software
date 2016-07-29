void handleIntersect2() {
  int temp;
  int lInt = !digitalRead(LINTTAPE);
  int rInt = !digitalRead(RINTTAPE);

  boolean front = (nodeMap[lastNode][nextNode][STRAIGHT] != -1);
  boolean left = (nodeMap[lastNode][nextNode][LEFT] != -1);
  boolean right = (nodeMap[lastNode][nextNode][RIGHT] != -1);

  if(turnDecision == LEFT) {
    hardLeft();
    temp = nodeMap[lastNode][nextNode][0];
    lastNode = nextNode;
    nextNode = temp;
  }
  else if(turnDecision == RIGHT) {
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
