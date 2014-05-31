#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 3

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup(void){
  // start serial port
  Serial.begin(9600);
  sensors.begin();
}

void loop(void){
  sensors.requestTemperatures(); // Send the command to get temperatures
  int t1=sensors.getTempCByIndex(0);
  int t2=sensors.getTempCByIndex(1);
  Serial.print(t1);
  Serial.print('@');
  Serial.println(t2);
}