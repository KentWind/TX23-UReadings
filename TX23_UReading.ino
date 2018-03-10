#include <LaCrosse_TX23.h>
#include "TX23Manipulations.h"
#include "internetConn.h"

//DATA wire connected to arduino port 9
LaCrosse_TX23 anemometer = LaCrosse_TX23(9);

TX23manipulations manipulations;
internetConn conn;

void setup(){
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  conn.startConn();
  
  conn.printIPAddress();
}

void loop(){
  conn.maintainConn();

  manipulations.printTX23Data(anemometer);
  
  //delay between succesive read requests must be at least 2sec, otherwise wind speed will read 0.
  delay(2000);
}
