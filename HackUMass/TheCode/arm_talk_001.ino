/*
Supported by Walter Brown, propery to GrAEyTeam.
IF THIS WAS IN JAVA, EVERYTHING HERE WOULD BE PRIVATE ACCEPT FOR
setMotorVelocity(motor enum, velocity double between -1 and 1).
*/

/* Address the motors using these. */
enum motor{BASE, SHOULDER, ELBOW, RIGHT_WRIST,
           LEFT_WRIST, HAND, LAST};
           
/* Set to 0 for initial speeds to be set to zero. */
#define MOTOR_DEBUG 0

/* Clock */
double tickers[LAST];

/* Speed controls */
double deltas[LAST];

/* Add to setup somewhere. */
void setup() {
  /* Set all pins to be outputs. */
  for(int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  /* Set deltas. */
  for(int i = 0; i < LAST; i++) {
    if(MOTOR_DEBUG)
      setMotorVelocity(i, 0.01*(i+1));
    else
      setMotorVelocity(i, 0.0);
  }
}

/* Add to loop somewhere. */
void loop() {
  for(int i = 0; i < LAST; i++)
    updateMotor(i);
  delay(1);
}

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

/*
Makes sure that a given motor is being given the correct
inputs, slowly incrementing its state.
Use motor enum.
*/
void updateMotor(int m) {
  tickers[m] += deltas[m];
  if(((int)tickers[m])%2) digitalWrite(2*m+1, HIGH);
  else digitalWrite(2*m+1, LOW);
  if((((int)tickers[m])/2)%2) digitalWrite(2*m, HIGH);
  else digitalWrite(2*m, LOW);

}
