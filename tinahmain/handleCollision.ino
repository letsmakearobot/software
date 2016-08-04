void handleCollision() {
  int temp;
  temp = lastNode;
  lastNode = nextNode;
  nextNode = temp;
  
  if (nextNode != 18) {
    motor.speed(LMOTOR, -250);
    motor.speed(RMOTOR, 200);
  }
}  
