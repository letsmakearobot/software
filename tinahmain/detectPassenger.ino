#define IR_THRESH 100
#define MAX_NOISE_AMP 10

int IRVal = 0;

void detectPassenger(){
  if (analogRead(IRLEFT)> IR_THRESH)
  {
    //passenger detedcted on the left
    //turn on a dime
    motor.speed(LMOTOR, -200);
    motor.speed(RMOTOR, 200);
    
    //todo: implement method
  }

  if (analogRead(IRRIGHT1)> IR_THRESH)
  {
    //passenger detedcted on the right
    
    if(analogRead(IRRIGHT1)<IRVal){
      hardStop();
      pickupPassenger();
    }else{
      IRVal = analogRead(IRRIGHT1);
    }
  }
}

void pickupPassenger(){};

