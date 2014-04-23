void startTest(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
} 
  void lightTest(int n){
    if(n==1){digitalWrite(13, HIGH);}
    if(n==2){digitalWrite(12, HIGH);}
    if(n==3){digitalWrite(11, HIGH);}
  }
  
  void dimTest(int n){
    if(n==1){digitalWrite(13, LOW);}
    if(n==2){digitalWrite(12, LOW);}
    if(n==3){digitalWrite(11, LOW);}
  }
