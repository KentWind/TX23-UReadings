#ifndef internetConn_h
#define internetConn_h

/*
  Circuit:
   Ethernet shield attached to pins 10, 11, 12, 13
*/

#include <SPI.h>
#include <Ethernet.h>

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):

class internetConn{
  public:
    void startConn();
    void maintainConn();
    void printIPAddress();
  private:
    
};

#endif
