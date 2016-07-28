void armTest() {
  while(TRUE){
    while (!startbutton()){
      if (!(c%200)) {
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("Knob to 10: ");
        LCD.print(knob(6));
        LCD.setCursor(0,1);
        LCD.print("START to cont.");   
      }
    }
    while(!stopbutton()){
      if (!(c%200)) {
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("Arm Servo: ");
        LCD.print(knob(6));
        LCD.setCursor(0,1);
        LCD.print("STOP to cont.");   
        
      }
      RCServo0.write(knob(6));
    }
    while (!startbutton()){
      if (!(c%200)) {
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("+ armspeed:");
        LCD.setCursor(0,1);
        LCD.print("START to cont.");   
        motor.speed(2, 100);
        
      }
    }
    while(!stopbutton()){
      if (!(c%200)) {
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("- armspeed:");
        LCD.setCursor(0,1);
        LCD.print("STOP to cont.");   
        motor.speed(2, -100);
        
      }
    }
    motor.stop_all();
  }
}

