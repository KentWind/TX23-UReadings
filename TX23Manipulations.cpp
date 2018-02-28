#include "TX23Manipulations.h"

float TX23manipulations::metersToMiles(float speed){
  speed = speed * getMeterToMile();
  return speed;
}

float TX23manipulations::getMeterToMile(){
  return meterToMile;
}



