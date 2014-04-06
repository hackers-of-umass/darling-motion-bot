/*
The data collection mehthod of hackbot. Uses the provided LSM303 Method given 
 by the pololu website.*/

#include <Wire.h>
#include <LSM303.h>

LSM303 compass;

//toClamp or not to clamp that is the question
boolean toClamp;
//toRelax or not to relax that is the question
boolean toRelax;
//A Bro toBro fromBro
boolean toBro;

//Count towards bro
int count;

//A0 Pin for the Force Sensitive Resistor
int FSR_Pin = A0;
int FSR;

/*
Initiate data collection
 */
void startData(){
  Wire.begin();
  compass.init();
  compass.enableDefault();
  count = 0;
}

/*
Update the readings from the FSR and MinIMU-9 v2
*/
void update(){
  compass.read();
  FSR = analogRead(FSR_Pin);
  readClamp(FSR);
}

/*
Get the current x, y ,z state of the LSM303DLHC
*/
int getState(int n){
  if(n==0) return toG(compass.a.x);
  if(n==1) return toG(compass.a.y);
  if(n==2) return toG(compass.a.z);
}

/*
Get the current state of toBro and toClamp
*/
boolean getClamp(int n){
  if(n==0) return toClamp;
  if(n==1) return toRelax;
  if(n==2) return toBro;
}

void printRaw(){
  Serial.println(toG(compass.a.x));
  Serial.println(toG(compass.a.y));
  Serial.println(toG(compass.a.z));
  Serial.println(FSR);
  Serial.println();
}

/*
Read the FSR 
*/
void readClamp(int i){
  if(i>650){
    toClamp=true;
    count++;
  }
  else if(i>50){
    toRelax=true;
  }
  else{
    toClamp=false;
    toRelax=false;
  }
  if(count==6){
    toBro=true;
    count=0;
  }
}

//
void noBro(){
  toBro = false;
}

/*
Converts raw to right data precision
*/
int toG(int x){
  return x/16;
}

