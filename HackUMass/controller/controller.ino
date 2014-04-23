/*
Main method arduino class that is used to access the accelerometer input and convert that 
into robotic arm output.
*/

boolean test = false;
void setup()
{
  if(test){
    startTest();
  }
  Serial.begin(9600);
  startData();
}

void loop()
{
  //Data Collection
  getDelta();
  //printDelta();
  printRaw();
  delay(100);
}
