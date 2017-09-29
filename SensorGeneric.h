#ifndef _SENSORGENERIC_h
#define _SENSORGENERIC_h

#include <Arduino.h>
#include "Timing.h"


enum SensorType {
	AVERAGE,
	MAX
};


class SensorGeneric
{
 protected:
	 bool isSetup = false;
	 Timing reportTimer;

	 char* _sensorName;
	 char* _mqttName;
	 char* _dataDesc;
	 char* _dataUnit;
	 SensorType _sensorType;
	 unsigned long _deviceLostAfter;

	 float dataAcc = 0;
	 uint16_t dataMeasurements = 0;
	 float dataMax = 0;
	 unsigned long lastDataReceivedAt;

	 void sendData();
 public:
	 void connect( const char * sensorName, const char * mqttName, const char * dataDesc, const char * dataUnit, SensorType sensorType, uint16_t reportFreq, uint16_t deviceLostAfter );
	 void handle();
	 void addIncomingData( float value );
	 float getAvgValue();
	 bool isSensorAlive();
};

#endif

