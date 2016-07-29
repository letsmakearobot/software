void armTest() {
  int motorSpeed;
  int negMotorSpeed;
  while(!(startbutton() && stopbutton())){
    while (!startbutton()){
      if (!(c%200)) {
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("Motor speed: ");
        LCD.print(knob(6)/2);
        LCD.setCursor(0,1);
        LCD.print("START to cont.");   
      }
    }
    motorSpeed = knob(6)/2;
    negMotorSpeed = -1*motorSpeed;
    while(!stopbutton()){
      if (!(c%200)) {
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("Op/cl servo: ");
        LCD.print(knob(6));
        LCD.setCursor(0,1);
        LCD.print("STOP to cont.");   
        if (knob(6) > 500) {
          RCServo0.write(GRIPSERVMAX);
        } else {
          RCServo0.write(GRIPSERVMIN);
        }
      }
    }
    while (!startbutton()){
      if (!(c%200)) {
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("+ armspeed:");
        LCD.setCursor(0,1);
        LCD.print("START to cont.");   
        motor.speed(2, motorSpeed);
        
      }
    }
    while(!stopbutton()){
      if (!(c%200)) {
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("- armspeed:");
        LCD.setCursor(0,1);
        LCD.print("STOP to cont.");   
        motor.speed(2, negMotorSpeed);
      }
    }
    motor.stop_all();
  }
}

