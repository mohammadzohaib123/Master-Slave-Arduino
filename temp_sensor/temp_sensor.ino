#include <Wire.h>
float temp;
int tempPin = 0;
char t[10];
void setup()

{
Wire.begin(6);
Serial.begin(9600);

}

void loop()

{
Wire.onRequest(requestEvent);
temp = analogRead(tempPin);

temp = temp * 0.48828125;

Serial.print("TEMPRATURE = ");

Serial.print(temp);

Serial.print("*C");

Serial.println();
dtostrf(temp,2,4,t);
delay(100);

}
void requestEvent(){
 
Wire.write(t);
}

