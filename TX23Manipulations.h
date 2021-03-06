
#ifndef TX23manipulations_h
#define TX23manipulations_h

#include <LaCrosse_TX23.h>


class TX23manipulations{
  public:
    float metersToMiles(float speed);
    float getMeterToMile();
    void printTX23Data(LaCrosse_TX23 anemometer);
    int getDir();
    int getSpeed();
  private:
    const float meterToMile = 2.2369;
    int theDirection;
    float theSpeed;
    
};

#endif
