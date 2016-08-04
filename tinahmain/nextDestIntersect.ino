//Returns the next direction you should go based on the IR intensity
int nextDestIntersect(int currentNode, int nextNode){
  int lIntIr = -1;
  int rIntIr = -1;
  int fIntIr = -1;

  if(nodeMap[currentNode][nextNode][LEFT] > -1){
    lIntIr = analogRead(IRFRONTLEFT);
  }
  if(nodeMap[currentNode][nextNode][RIGHT] > -1){
    rIntIr  = analogRead(IRFRONTRIGHT);
  }
  if(nodeMap[currentNode][nextNode][STRAIGHT] > -1){
    fIntIr = analogRead(IRFRONT);
  }
  int Irs[3] = {lIntIr, rIntIr, fIntIr};
  return findMax(Irs, 3);
}
