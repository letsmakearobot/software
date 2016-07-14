#include "constants.h"
#include <phys253.h>
#include <LiquidCrystal.h>

// Define timeouts here!
#define TSERVO 100
#define TIRDETECT 10
#define TPASSDETECT 300

#define SERVOSTART 0
#define SERVOEND 180
#define SERVOINC 45

int c = 0;
int nextTurn = STRAIGHT;
int IRdetected = FALSE;
int IRlevel = 0;
int IRthresh = 300;
int turnDecision;

int IRlevels[SERVOEND/SERVOINC];

void setup() {
  // put your setup code here, to run once:
  #include <phys253setup.txt>
}

void loop() {
  followTape();

  if ((!(c % TSERVO)) && approachingInt) {
    nextTurn = handleFrontIR(servo.read(IRSERVO), IRlevels, analogRead(IRFRONT));
  }

  if (! (c % TPASSDETECT)) {
    passengerRoutine();
  }

  c++;
}
