#include "constants.h"
#include <phys253.h>
#include <LiquidCrystal.h>
#include <ServoTINAH.h>         //   ***** from 253 template file

// Define +timeouts here!
#define TSERVO 100
#define TIRDETECT 10
#define TPASSDETECT 300

// TUNED VARIABLES (make them constants in final)
int lbase = 150;
int rbase = 150;
int kp = 60;
int kd = 60;

// INPUT/OUTPUT VARIABLES
int left = 0;
int right = 0;
int leftint = 0;
int rightint = 0;
int l_motor = 0;
int r_motor = 0;

// INTERMEDIATE VARIABLES
int p = 0;
int d = 0;
int con = 0;

// ERROR HANDLING
int err = 0;
int recerr = 0;
int lerr = 0;

//TIMING
int q = 0;
int m = 0;

// Clock
int c = 0;

int IRVal = 0;
int IRlevel = 0;
int IRthresh = 300;
int turnDecision;
int numPassengers = 0;

int nodeMap[21][21][3] = {
  {{0,0,0},{-1,6,2},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{11,-1,16},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{10,-1,-1},{0,0,0},{-1,9,3},{0,0,0},{0,0,0},{0,0,0},{-1,5,11},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{6,-1,0},{0,0,0},{-1,7,4},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{13,12,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{9,-1,1},{0,0,0},{-1,15,-1},{0,0,0},{0,0,0},{8,-1,14},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{7,-1,2},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{-1,14,20},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,11,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,2,-1},{0,0,0},{0,0,0},{0,0,0},{-1,-1,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{12,10,17},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{2,4,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{-1,-1,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{15,13,19},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{14,3,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{1,3,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{-1,11,13},{14,-1,12},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{-1,1,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{6,17,12},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{5,-1,1},{0,0,0},{0,0,0},{0,0,0},{16,0,-1},{0,0,0},{9,13,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{2,-1,13},{0,0,0},{17,6,10},{0,0,0},{-1,14,9},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{-1,2,12},{0,0,0},{0,0,0},{11,-1,9},{0,0,0},{7,19,15},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{-1,8,3},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{12,9,-1},{0,0,0},{4,20,-1},{0,0,0},{0,0,0},{0,0,0},{20,18,-1},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{3,-1,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{19,7,13},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{-1,19,-1}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{11,-1,18},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{-1,10,-1},{0,0,0},{-1,-1,19},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{-1,11,16},{0,0,0},{14,-1,20},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{13,15,7},{0,0,0},{0,0,0},{0,0,0},{-1,-1,17},{0,0,0},{15,-1,-1}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{14,-1,4},{0,0,0},{0,0,0},{0,0,0},{-1,14,18},{0,0,0}}
};

int lastNode;
int nextNode;

void setup() {
  // put your setup code here, to run once:
  #include <phys253setup.txt>
  armTest();
  initializeRobot();
}

void loop() {
  while ( ! stopbutton() ) {
    // digitalRead true if on tape, false otherwise
    left = !digitalRead(LTAPE);
    right = !digitalRead(RTAPE);
    leftint = !digitalRead(LINTTAPE);
    rightint = !digitalRead(RINTTAPE);

    // Both sensors on tape
    if (left && right)
      err = 0;
    // left sensor on tape, right sensor off
    if (left && (! right))
      err = -1;
    // right sensor on tape, left sensor off
    if ((! left) && right)
      err = 1;
    // both sensors are off the tape
    if (!(left || right)) {
      if (lerr > 0)
        err = 5;
      if (lerr <= 0)
        err = -5;
    }
    if (!(err==lerr)) {
      recerr=lerr;
      q=m;
      m=1;
    }

    p = kp * err;
    d = (int)((float)kd * (float)(err-recerr)/(float)(q+m));
    con = p+d;

    l_motor = lbase+con;
    r_motor = rbase-con;

    if (l_motor < -250) {
      l_motor = -250;
    } else if (l_motor > 250) {
      l_motor = 250;
    }
    if (r_motor < -250) {
      r_motor = -250;
    } else if (r_motor > 250) {
      r_motor = 250;
    }

    m++;
    motor.speed(LMOTOR, l_motor);
    motor.speed(RMOTOR, r_motor);
    lerr=err;

    if (!(c % 200)) {
      if( startbutton() ){
//        lbase = knob(6)-300;
//        rbase = knob(7)-300;
        LCD.clear();
        LCD.setCursor(0,0);
        labelPrint("LM", l_motor, "RM", r_motor, "P", kp);
        LCD.setCursor(0,1);
        labelPrint("D", kd, "L", lbase, "R", rbase);
      } else {
        LCD.clear();
        LCD.setCursor(0,0);
        labelPrint("LT", left, "RT", right, "LI", leftint);
        LCD.setCursor(0,1);
        labelPrint("RI", rightint, "LN", lastNode, "NN", nextNode);
      }
    }

    if(leftint || rightint){
      handleIntersect();
    }

    if (numPassengers <= 3) {
      detectPassengerTest();
    }
    c++;
  }

  motor.stop_all();
  Menu(kp, kd);
}
