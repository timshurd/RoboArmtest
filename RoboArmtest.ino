#include <RoboArm.h>
#include <Component.h>
#include <Servo.h>
#include <array>


Servo elbo2,wrist2,grip2,wtwist2,should1,should0, base2;
Component *compList; 
bool r = true;

void setup(){
  Serial.begin(57600);
  elbo2.attach(6);
  wtwist2.attach(3);
  should1.attach(7);
  should0.attach(8);
  base2.attach(9);
  wrist2.attach(4);
  grip2.attach(2);
  
}

void loop(){


  Component gripx(grip2,    22,  102,  8.8,  4,  90,  20,  68,    3.2,  2.8);
  Component wtwistx(wtwist2,11,  171,  3.8,  3,  90,  20,  0.3,   3.2,  2.8);
  Component wristx(wrist2,  10,  170,  1.27, 2,  90,  20,  7.08,  3.2,  2.8);
  Component elbox(elbo2,    10,  170,  7,    1,  0,   41,  10.99, 6.5,  5.2);
  Component shouldx(should1,5,   175,  12.1, 0,  90,  41,  17.9,  6.5,  5.2);
  Component basex(base2,    0,   175,  0,    -1, 0,   0,   0,     0,     0);
  Component shouldx0(should0,5,  175,  0,    0);
  
 RoboArm a(shouldx,elbox,wristx,wtwistx,gripx,basex,true,false,true,shouldx0);  
  

  
  //test rArm function
  //float dista = a.rArm(0);
  //Serial.println(dista);

  float maxlc = a.maxLiftC();

  Serial.println(maxlc);
 
 float *tempx;
 float *tempy;
 tempx = new float;
 tempy = new float;

 delete tempx;
 delete tempy;
  
  
  
  
  
  
  
  
  
 int valS = 20;
  int valElb = 0;
  
  if(valElb >170){
   valElb = 170; 
  }
  grip2.write(30);
  wtwist2.write(173); //90 is flat servo on top, looking down the arm towards the grip a value under 90 or decreasing is a couter-clockwise rotation,
  wrist2.write(0); //DO NOT WRITE OVER 170
  elbo2.write(180); //straight in line with shoulder joint at 85, 0 for 90' back
  base2.write(0);
  should1.write(valS); //write 80 to this servo for vertical placement, 170 for striaght out front
  should0.write(181-valS); //write 101 to this servo for vertical placement, 11 for straight
  
  
  
  

    delay(20);
  

}


