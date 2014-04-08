/*
Main method arduino class that is used to access the accelerometer input and convert that 
into robotic arm output.
*/

//Boolean method to establish test lights in 13 12 11 Pins
boolean test = false;

/*
Setup method. Calls other start methods in the other class
*/
void setup(){
  
  if(test){
    startTest();
  }
  
  Serial.begin(9600);

  startData();//Start the data collection
  startControl();//Start the controller
}

void loop()
{
  /*Data collection*/
  update();//Update the readings from the sensors
  printRaw();//Print the raw data for debugging
  
  /*State update*/
  updateState(getState(0), getState(1), getClamp(0), getClamp(1), getClamp(2)); //Update to relative state based on reading changes in sensors
  updateAllMotors(); //Update motors to move the bot
  
  //Short delay to ensure fluidness of motion
  delay(1);
}
