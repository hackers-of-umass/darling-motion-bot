/*
Supported by Walter Brown, propery to GrAEyTeam.
IF THIS WAS IN JAVA, EVERYTHING HERE WOULD BE PRIVATE ACCEPT FOR
setMotorVelocity(motor enum, velocity double between -1 and 1).
*/
//Controller of the Mini Mover 5 robotic motors

/* Address the motors using these. */
enum motor{BASE, HAND, ELBOW, SHOULDER, LEFT_WRIST, RIGHT_WRIST,
LAST};

/* Clock */
double tickers[LAST];

/* Speed controls */
double deltas[LAST];

/* Add to setup somewhere. */
void startControl() {
  /* Set all pins to be outputs. */
  for(int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}
  
  //setMotorVelocity(LEFT_WRIST, -0.05);
  //setMotorVelocity(RIGHT_WRIST, 0.05);
  //bro();
//}

/*
Set the speed of a specified motor.
Use motor enum to specifie motor used.
Velocity should be between -1 and 1.
*/
void setMotorVelocity(int motor, double velocity) {
  deltas[motor] = velocity;
  if(deltas[motor] >  1) deltas[motor] =  1;
  if(deltas[motor] < -1) deltas[motor] = -1;
}

void updateAllMotors() {
  for(int i = 0; i < LAST; i++)
    updateMotor(i);
}

/*
Makes sure that a given motor is being given the correct
inputs, slowly incrementing its state.
Use motor enum.
*/
//Implementer note: Big pin number goes to B.
void updateMotor(int m) {
  tickers[m] += deltas[m];
  while(tickers[m] < 0) tickers[m] += 4;
  while(tickers[m] > 4) tickers[m] -= 4;
  if(((int)tickers[m])%2) digitalWrite(2*m, HIGH);
  else digitalWrite(2*m, LOW);
  if((((int)tickers[m])/2)%2) digitalWrite(2*m+1, HIGH);
  else digitalWrite(2*m+1, LOW);
  
}

void bro() {
  setMotorVelocity(LEFT_WRIST, -0.05);
  setMotorVelocity(RIGHT_WRIST, 0.05);
  setMotorVelocity(SHOULDER, 0.13/2);
  setMotorVelocity(ELBOW, 0.13);
  for(int i = 0; i < 700; i++) {
    updateAllMotors();
    delay(1);
  }
  setMotorVelocity(LEFT_WRIST, 0.05);
  setMotorVelocity(RIGHT_WRIST, -0.05);
  setMotorVelocity(ELBOW, -0.13);
  for(int i = 0; i < 700; i++) {
    updateAllMotors();
    delay(1);
  }
  setMotorVelocity(LEFT_WRIST, 0);
  setMotorVelocity(RIGHT_WRIST, 0);
  setMotorVelocity(ELBOW, 0);
  setMotorVelocity(SHOULDER, -0.13);
  for(int i = 0; i < 700; i++) {
    updateAllMotors();
    delay(1);
  }
  setMotorVelocity(SHOULDER, 0);
}
