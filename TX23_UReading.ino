#include <LaCrosse_TX23.h>
#include "TX23Manipulations.h"

//DATA wire connected to arduino port 10

LaCrosse_TX23 anemometer = LaCrosse_TX23(10);

TX23manipulations manipulations;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String dirTable[]= {"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
  float speed;
  float mphSpeed;
  int direction;
  
  if(anemometer.read(speed, direction))
  {
    mphSpeed = manipulations.metersToMiles(speed);
    Serial.println("Speed = " + String(mphSpeed,1) + " mph");
    //Serial.println("Speed = " + String(speed,1) + " m/s");
    Serial.println("Dir = " + dirTable[direction]);    
  }
  else
  {
    Serial.println("Read error");
  }

  
  //delay between succesive read requests must be at least 2sec, otherwise wind speed will read 0.
  delay(2000);
}
