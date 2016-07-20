void handleIntersect() {
  int temp;
  int lInt = !digitalRead(LINTTAPE);
  int rInt = !digitalRead(RINTTAPE);

  if (lInt) {
    hardLeft();

    temp = nodeMap[lastNode][nextNode][0];
    lastNode = nextNode;
    nextNode = temp;
  }
  else if (rInt) {
    hardRight();

    temp = nodeMap[lastNode][nextNode][1];
    lastNode = nextNode;
    nextNode = temp;
  }
}
