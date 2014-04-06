/*
State pattern describing the 7 states that up down tilt is handled.
 Handles the 5 states left right tilt. 
 Handles the clamping trigger.
 Handles the bro trigger.
 */

//Safe Range
int x_lower_safe=-300;
int x_upper_safe=300;

int y_lower_safe=-350;
int y_upper_safe=350;

//Danger Level
int x_upper1=450;
int x_upper2=850;
int x_lower1=-450;
int x_lower2=-850;



void updateState(int x, int y, boolean c, boolean r, boolean b){
  if(x<=x_upper_safe && x>=x_lower_safe && y<=y_upper_safe && y>=y_lower_safe){
    setMotorVelocity(LEFT_WRIST, 0);
    setMotorVelocity(RIGHT_WRIST,0);
  }

  updateX(x);
  updateY(y);

  updateClamp(c, r);
  updateBro(b);
}

void updateX(int x){
  if(x<=x_upper_safe&& x>=x_lower_safe){
    //Neutral
    setMotorVelocity(SHOULDER, 0);
    setMotorVelocity(ELBOW, 0);
    setMotorVelocity(LEFT_WRIST, 0);
    setMotorVelocity(RIGHT_WRIST,0);
    setMotorVelocity(HAND, 0);
  }
  else if(x > x_upper_safe && x <= x_upper1){
    //Upper wrist
    setMotorVelocity(SHOULDER,0);
    setMotorVelocity(ELBOW, 0);
    setMotorVelocity(LEFT_WRIST, 0.1);
    setMotorVelocity(RIGHT_WRIST, -0.1);
    setMotorVelocity(HAND, 0);
  }
  else if(x>x_upper1 && x<=x_upper2){
    //UP1
    setMotorVelocity(ELBOW, 0.2);
    setMotorVelocity(HAND, 0);
    setMotorVelocity(SHOULDER, 0);
    setMotorVelocity(LEFT_WRIST, 0);
    setMotorVelocity(RIGHT_WRIST,0);
  }
  else if(x>x_upper2){
    //UP2
    setMotorVelocity(SHOULDER, -0.08);
    setMotorVelocity(ELBOW, 0);
    setMotorVelocity(LEFT_WRIST, 0);
    setMotorVelocity(RIGHT_WRIST,0);
    setMotorVelocity(HAND, 0);
  }
  else if(x < x_lower_safe && x >= x_lower1){
    //Lower wrist
    setMotorVelocity(SHOULDER,0);
    setMotorVelocity(ELBOW, 0);
    setMotorVelocity(LEFT_WRIST, -0.1);
    setMotorVelocity(RIGHT_WRIST, 0.1);
    setMotorVelocity(HAND, 0);
  }
  else if(x<-x_lower1 && x>=x_lower2){
    //DOWN1 
    setMotorVelocity(ELBOW, -0.2);
    setMotorVelocity(SHOULDER, 0);
    setMotorVelocity(LEFT_WRIST, 0);
    setMotorVelocity(RIGHT_WRIST,0);
    setMotorVelocity(HAND, 0);
  }
  else if(x<-x_lower2){
    //DOWN2
    setMotorVelocity(SHOULDER, 0.08);
    setMotorVelocity(ELBOW, 0);
    setMotorVelocity(LEFT_WRIST, 0);
    setMotorVelocity(RIGHT_WRIST,0);
    setMotorVelocity(HAND, 0);
  }
  else{
    //Neutral
    setMotorVelocity(SHOULDER, 0);
    setMotorVelocity(ELBOW, 0);
    setMotorVelocity(LEFT_WRIST, 0);
    setMotorVelocity(RIGHT_WRIST,0);
    setMotorVelocity(HAND, 0);
  }
}

void updateY(int y){
  if(y<=350 && y>=-350){
    //Neutral
  }
  else if(y>550 && y<=1000){
    //LEFT1
    setMotorVelocity(LEFT_WRIST, -.10);
    setMotorVelocity(RIGHT_WRIST,-.10);
  }
  else if(y>850){
    //LEFT2  
  }
  else if(y<-350 && y>=-1000){
    //RIGHT1
    setMotorVelocity(LEFT_WRIST, .10);
    setMotorVelocity(RIGHT_WRIST,.10);
  }
  else if(y<-850){
    //RIGHT2
  }
}

//int clampEstimate = 0
void updateClamp(boolean c, boolean r){
  if(c){
    //Do Clamp Stuff
    setMotorVelocity(HAND, 0.15);
    //clampEstimate += 1;
  }
  else if(r){
    //Relax clamp
    setMotorVelocity(HAND, -0.15);
  }
  else{
    setMotorVelocity(HAND, 0);
  }
}

void updateBro(boolean b){
  //if(b){
  //  bro();
  //  noBro();
  //}
}




