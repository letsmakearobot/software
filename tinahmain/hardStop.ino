void hardStop(){
  LCD.clear();
  LCD.print("hard stop!");
  motor.speed(LMOTOR, -255);
  motor.speed(RMOTOR, -255);
  delay(10);
  motor.stop(LMOTOR);
  motor.stop(RMOTOR);
}
void hardRight() {
  LCD.clear();
  LCD.print("hard right!");

  motor.speed(RMOTOR, 250);
  motor.speed(LMOTOR, 0);
  delay(150);

  while(!digitalRead(RTAPE)) {
    motor.speed(RMOTOR, 300);
    motor.speed(LMOTOR, 0);
  }
}

void hardLeft() {
  LCD.clear();
  LCD.print("hard left!");

  motor.speed(LMOTOR, 250);
  motor.speed(RMOTOR, 0);
  delay(150);

  while(!digitalRead(LTAPE)) {
    motor.speed(LMOTOR, 300);
    motor.speed(RMOTOR, 0);
  }
}

