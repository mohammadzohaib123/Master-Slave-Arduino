#include <Wire.h>
char t[10];
int analogInput = A1;
float vout = 0.0;
float vin = 0.0;
float R1 = 39000.0; //  
float R2 = 10000.0; // 
int value = 0;
float iout=0;
String floatToString;
void setup(){
   pinMode(analogInput, INPUT);
   Serial.begin(9600);
   Wire.begin(7);
   Wire.onRequest(requestEvent);
   //Serial.print("DC VOLTMETER");
}
void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; // see text
  // vin = vout / (R2/(R1+R2)); 
//  iout=vout/R2;
   
Serial.print("OUTPUT V= ");
Serial.println(vout);
/*Serial.println(vout,7);
Serial.println(iout,7);*/
delay(100);
dtostrf(vout,1,7,t);
}
void requestEvent(){
 
Wire.write(t);
}


