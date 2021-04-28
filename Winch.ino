#include <PRIZM.h> 
#include <TELEOP.h>    
PRIZM prizm; 
PS4 ps4;
int motorSpeed = 0;
void setup() {
prizm.PrizmBegin();  
motorSpeed=20; //Start my motor in a clockwise rotation 
}
void loop() {    
 ps4.getPS4();
 if (ps4.Connected) {
   if (ps4.Button(CROSS)){prizm.setMotorPower(1,0);}
   if (ps4.Button(SQUARE)){prizm.PrizmEnd();}
   if (ps4.Button(CIRCLE)){motorSpeed = motorSpeed*-1;} 
   if (ps4.Button(UP)) {if (motorSpeed < 100) {motorSpeed = motorSpeed + 1;}}
   if (ps4.Button(DOWN)) {if (motorSpeed > -100) {motorSpeed = motorSpeed - 1;}}
   if(ps4.Button(R1)){if (prizm.readSonicSensorCM(2) < 4) {prizm.setMotorPower(1,0);} else {prizm.setMotorPower(1,motorSpeed);}}
      else{
        prizm.setMotorPower(1,0);
      }
 } else {
   prizm.setMotorPower(1,0);
   prizm.PrizmEnd();
 }}            

 //2:20, 58cm//
