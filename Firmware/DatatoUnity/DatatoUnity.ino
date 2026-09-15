#include <elapsedMillis.h>

const int switchPin = 2;
const int potentiometerPin = A0;

bool switchVal = 0;
int potentiometerVal = 0;

//time variables
elapsedMillis sendToUnityTimer;
//could use int but using long for double number of bits
//unsigned means variable value will always be pos. good for millis since time adds up quickly
unsigned long sendToUnityInterval = 40;

void setup() {
  Serial.begin(115200);
  pinMode (switchPin, INPUT_PULLUP);
  //looking for full range of values on potentiometer so no pullup
  pinMode (potentiometerPin, INPUT);
}

void loop() {
  readSensors():
  sendSensorDataToUnity();

}

void readSensors(){
  //always off or on so digitalRead
  switchVal = digitalRead(switchPin);
  potentiometerVal = analogRead(pontentiometerPin);
}

void sendSensorDataToUnity(){
  Serial.print(switchVal);
  Serial.print(',');
  Serial.println(potentiometerVal);
}
