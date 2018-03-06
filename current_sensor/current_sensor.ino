#include <Wire.h>
char t[10];
int analogInput = A1;
float vout = 0.0;
float vin = 0.0;
float R1 = 33000.0; //  
float R2 = 10000.0; // 
int value = 0;
float iout=0;
String floatToString;
void setup(){
   pinMode(analogInput, INPUT);
   Serial.begin(9600);
   Wire.begin(8);
   Wire.onRequest(requestEvent);
   //Serial.print("DC VOLTMETER");
}
void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; // see text
  // vin = vout / (R2/(R1+R2)); 
  iout=vout/R2;
  Serial.println(iout);
   
//Serial.print("OUTPUT I= ");
/*Serial.println(vout,7);
Serial.println(iout,7);*/
delay(100);
dtostrf(iout,1,7,t);
}
void requestEvent(){
 
Wire.write(t);
}


