#include "Wire.h"
#define SERIAL_BAUD   115200
#define SERIAL_EN                //comment out if you don't want any serial output

#ifdef SERIAL_EN
  #define SERIAL_BAUD   115200
  #define DEBUG(input)   {Serial.print(input);}
  #define DEBUGln(input) {Serial.println(input);}
  #define SERIALFLUSH() {Serial.flush();}
#else
  #define DEBUG(input);
  #define DEBUGln(input);
  #define SERIALFLUSH();
#endif

#define si7051Addr 0x40
float dewpout_eu;

void setup() {
  Wire.begin();
#ifdef SERIAL_EN
  Serial.begin(SERIAL_BAUD);
#endif
}

void loop() {
  unsigned int data[2];
  Wire.beginTransmission(si7051Addr);
  // Send temperature measurement command
  Wire.write(0xF3);
  Wire.endTransmission();
  delay(200);
  // Request 2 bytes of data
  Wire.requestFrom(si7051Addr, 2);
  // Read 2 bytes of data for temperature
  if (Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }
  
  // Convert the data
  float temp  = ((data[0] * 256.0) + data[1]);
  float celsTemp = ((175.72 * temp) / 65536.0) - 46.85;
  
  // Output data to serial monitor
  Serial.print("Celsius : ");
  Serial.print(celsTemp);
  Serial.println(" C");
  delay(1000);

}
