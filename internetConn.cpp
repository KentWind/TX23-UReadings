#include "internetConn.h"

void internetConn::startConn(){
  // start the Ethernet connection:
  //MAC address
  byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for (;;)
      ;
  }
}

void internetConn::maintainConn(){
  switch (Ethernet.maintain()){
    case 1:
      //renewed fail
      Serial.println("Error: renewed fail");
      break;

    case 2:
      //renewed success
      Serial.println("Renewed success");
      //print local IP address:
      printIPAddress();
      break;

    case 3:
      //rebind fail
      Serial.println("Error: rebind fail");
      break;

    case 4:
      //rebind success
      Serial.println("Rebind success");

      //print local IP address:
      printIPAddress();
      break;

    default:
      //nothing happened
      break;
  }
}
void internetConn::printIPAddress(){
   Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print(".");
  }
  Serial.println();
}

