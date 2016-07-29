void handleCollision() {
  if (nextNode != 18) {
    motor.speed(LMOTOR, -200);
    motor.speed(RMOTOR, 200);
  }
}  
