/*
Main method arduino class that is used to access the accelerometer input and convert that 
into robotic arm output.
*/

//Boolean method to establish test lights in 13 12 11 Pins
boolean test = false;
//Rate of data collection

/*
Setup method. Calls other start methods in the other class
*/
void setup(){
  if(test){
    startTest();
  }
  Serial.begin(9600);
  startData();
  startControl();
}

void loop()
{
  //Data collection
  update();
 printRaw();
  //State update
  
  //updateState(getState(0), getState(1), getClamp(0), getClamp(1), getClamp(2));
  //updateAllMotors();
  
  delay(100);
}
