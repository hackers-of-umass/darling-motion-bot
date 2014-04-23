
//Leftward deviation of x in the leftward direction. Negative
int Left1 = -250;
int Left2 = -500;
int Left3 = -750;

int Right1 = 250;
int Right2 = 500;
int Right3 = 750;

void checkX(int x){
  if(x<=250 || x>=-250){
    dimTest(1);
    dimTest(2);
    dimTest(3);
  }
  if(x>250 || x<-250){
    lightTest(1);
    dimTest(2);
    dimTest(3);
  }
  if(x>500 || x<-500){
    lightTest(1);
    lightTest(2);
    dimTest(3);
  }
  if(x>750 || x<-750){
      lightTest(1);
      lightTest(2);
      lightTest(3);
  }
}

void checkY(int y){
  if(y<=400 || y>=-350){
    dimTest(1);
    dimTest(2);
    dimTest(3);
  }
  if(y>600 || y<-350){
    lightTest(1);
    dimTest(2);
    dimTest(3);
  }
  if(y>850 || y<-750){
      lightTest(1);
      lightTest(2);
      lightTest(3);
  }
}

