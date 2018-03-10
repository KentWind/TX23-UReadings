#include "TX23Manipulations.h"

float TX23manipulations::metersToMiles(float speed){
  speed = speed * getMeterToMile();
  return speed;
}

float TX23manipulations::getMeterToMile(){
  return meterToMile;
}

void TX23manipulations::printTX23Data(LaCrosse_TX23 anemometer){
  String dirTable[]= {"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
  float speed;
  float mphSpeed;
  int direction;
  
  if(anemometer.read(speed, direction))
  {
    mphSpeed = metersToMiles(speed);
    Serial.println("Speed = " + String(mphSpeed,1) + " mph");
    //Serial.println("Speed = " + String(speed,1) + " m/s");
    Serial.println("Dir = " + dirTable[direction]);    
  }
  else
  {
    Serial.println("Read error");
  }
}


