#include <LaCrosse_TX23.h>
#include "TX23Manipulations.h"
#include "internetConn.h"
#include <SPI.h>
#include <Ethernet.h>

//DATA wire connected to arduino port 9
LaCrosse_TX23 anemometer = LaCrosse_TX23(9);

TX23manipulations manipulations;
//internetConn conn;

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,50,65);
char server[] = "192.168.50.143";
EthernetClient client;

void setup(){
  Serial.begin(9600);

  Serial.println("test");
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  //conn.startConn();
  // start the Ethernet connection
  Ethernet.begin(mac, ip);
  
  //conn.printIPAddress();
}

void loop(){
  //conn.maintainConn();

  manipulations.printTX23Data(anemometer);//This NEEDS to be called first, because bad code
  
  Serial.print("TEST");
  if (client.connect(server, 8095)) {
    Serial.println("Connected");
    client.print("GET /write_data.php?"); // This
    client.print("SensorID="); // This
    client.print("1");
    client.print("&Speed=");
    client.print(manipulations.getSpeed());
    client.print("&Direction=");
    client.println(manipulations.getDir());
    client.stop();    // Closing connection to server

  }

  else {
    // If Arduino can't connect to the server (your computer or web page)
    Serial.println("--> connection failed\n");
  }
 
  // Give the server some time to recieve the data and store it. I used 10 seconds here. Be advised when delaying. If u use a short delay, the server might not capture data because of Arduino transmitting new data too soon.
  delay(10000);
  //delay between succesive read requests must be at least 2sec, otherwise wind speed will read 0.
}
