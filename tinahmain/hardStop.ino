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
  motor.speed(LMOTOR, -255);
  motor.speed(RMOTOR, -255);
  delay(10);
  motor.stop(LMOTOR);
  motor.stop(RMOTOR);
}
void hardLeft() {
  LCD.clear();
  LCD.print("hard left!");
  motor.speed(LMOTOR, -255);
  motor.speed(RMOTOR, -255);
  delay(10);
  motor.stop(LMOTOR);
  motor.stop(RMOTOR);  
}

