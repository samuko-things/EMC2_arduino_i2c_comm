#ifndef EMC2_ADRUINO_I2C_COMM_H
#define EMC2_ADRUINO_I2C_COMM_H

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif


#include <Wire.h>


class EMC2ArduinoI2cCommApi {
public:
  EMC2ArduinoI2cCommApi (int);

  bool sendTargetVel(float, float);

  void getMotorsPos(float&, float&);

  void getMotorsVel(float&, float&);

  void getMotorAData(float&, float&);

  void getMotorBData(float&, float&);

  

private:
  int slaveAddr;
  String dataMsg = "", dataMsgBuffer = "", dataBuffer[2];
  float valA, valB;


  void get(String);

  bool send(String, float, float);

  void masterSendData(String);

  String masterReceiveData();

  String masterReceiveDataLarge();

  String masterReceiveDataChar();
  
};

#endif
