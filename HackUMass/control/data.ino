/*
The data collection mehthod of hackbot. Uses the provided LSM303 Method given 
by the pololu website.*/

#include <Wire.h>
#include <LSM303.h>

LSM303 compass;

int xState;
int yState;
int zState;

int dx;
int dy;
int dz;

/*
Initiate data collection
*/
void startData(){
  
  Wire.begin();
  compass.init();
  compass.enableDefault();
  
  compass.read();
  logState(toG(compass.a.x), toG(compass.a.y), toG(compass.a.z));
}

/*
Log the current state of xyz
*/
void logState(int x, int y, int z){
  xState=x;
  yState=y;
  zState=z;
}

/*
Get the delta and log the current state
*/
void getDelta(){
  compass.read();
  
  int xCurrent = toG(compass.a.x);
  int yCurrent = toG(compass.a.y);
  int zCurrent = toG(compass.a.z);
  
  dx=abs(xCurrent - xState);
  dy=abs(yCurrent - yState);
  dz=abs(zCurrent - zState);
  
  logState(xCurrent, yCurrent, zCurrent);
}

void update(){
  compass.read();
}

int getState(int n){
if(n==0) return toG(compass.a.x);
if(n==1) return toG(compass.a.y);
if(n==2) return toG(compass.a.z);

}

void printDelta(){
  char report[80];
  int time = millis();
  Serial.print(time);
  

  Serial.println(report);
}

void printRaw(){
  Serial.println(toG(compass.a.x));
  Serial.println(toG(compass.a.y));
  Serial.println(toG(compass.a.z));
  Serial.println();
}

int toG(int x){
  return x/16;
}
