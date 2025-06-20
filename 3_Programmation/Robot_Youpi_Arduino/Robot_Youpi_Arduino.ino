#include <stdio.h>

#include "includes\initialisation.h"
#include "includes\robots_program.h"

void setup() {

  initialisation();  //Initialisation of the motors --> //void Initialisation(const int MotorPins[]); ??

  // Initialisation of the robot's data
  int   codersMotors[6] = { 0 };  
  float motorAngles[6] = { 0 };
  float cartesianPositions[6] = { 0 };

  lcd.clear();
  delay(125);

  int etat;

  String receivedData = "";

  do {
    receivedData = receive_from_rpi(!DIRECT);
  } while (receivedData != fromRaspberryMessages[FROM_RPI_PROGRAM_EXECUTION]);


  if (receivedData == fromRaspberryMessages[FROM_RPI_PROGRAM_EXECUTION]){
    lcd.setCursor(0,0);
    lcd.print("Demarrage programme");
    robots_program(codersMotors, motorAngles);
  }
  lcd.setCursor(0,0);
  lcd.print("Fin programme");

}

void loop() {

}

