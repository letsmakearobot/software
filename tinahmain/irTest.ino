void IRTest() {
  while (!stopbutton()) {
    LCD.clear();
    LCD.setCursor(0,0);
    labelPrint("L", ,"R", ,"S", );
    LCD.setCursor(0,1);
    LCD.print("PU ");
    labelPrint("L", ,"R", ,"",0);
  }
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("START to test, hold");
  LCD.setCursor(0,1);
  LCD.print("STOP&START to cont");
  while (!startbutton()) {
    // just chilling
  }
}

