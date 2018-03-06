#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
char temp[10]={};
char volt[10]={};
char amp[10]={};
int b1=52;
int b2=53;
int j=0,x=0;
void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
 pinMode(b1,INPUT);
 pinMode(b2,INPUT);
  lcd.begin(16,2);
  lcd.print("Hello");
}

void loop() {
  Wire.requestFrom(8, 9);    // request 10 bytes from slave device #8
int i=0;
  while (Wire.available()) { // slave may send less than requested
     amp[i] = Wire.read(); // receive a byte as character
             i++;
             // print the character
  }
  Serial.print(amp);
  Serial.println("amp");
  delay(400);
  Wire.requestFrom(7, 9);    // request 10 bytes from slave device #8
 i=0;
  while (Wire.available()) { // slave may send less than requested
     volt[i] = Wire.read(); // receive a byte as character
             i++;
             // print the character
  }
  Serial.print(volt);
  Serial.println("v");
  delay(400);
  Wire.requestFrom(6, 7);    // request 10 bytes from slave device #8
 i=0;
  while (Wire.available()) { // slave may send less than requested
     temp[i] = Wire.read(); // receive a byte as character
             i++;
             // print the character
  }
  Serial.print(temp);
  Serial.println("*c");

  delay(400);
  if((digitalRead(b1)==HIGH)&&x<2)
  x++;
  if((digitalRead(b2)==HIGH)&&x>0&&x<=2)
  x--;
  if(x==0){
lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("Temperature");
  lcd.setCursor(0,1);
   lcd.print(temp);
  
  }
  
  if(x==1){
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("voltage");
   
    lcd.setCursor(0,1);
    lcd.print(volt);
  }
  
  if(x==2)
{
   lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ampere");
   
    lcd.setCursor(0,1);
    lcd.print(amp);
}
 /* if(x==0)
  {
  lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("Temperature");
  lcd.setCursor(0,1);
    Wire.requestFrom(6, 7); // request 10 bytes from slave device #8
 
  while (Wire.available()) { // slave may send less than requested
      // receive a byte as character
     lcd.write(Wire.read());
             
             // print the character
  }
  
  
  
    }*/
}


