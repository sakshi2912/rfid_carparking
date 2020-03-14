#include<SPI.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);

int IRSensor1 = 6; // connect ir sensor to arduino pin 2
int IRSensor2 = 4;
int IRSensor3 = 3; // connect ir sensor to arduino pin 2
int IRSensor4 = 2;
int IR[4];

void setup() 
{
Serial.begin(9600);
  pinMode (IRSensor1, INPUT); // sensor pin INPUT
  pinMode (IRSensor2, INPUT); // sensor pin INPUT
  pinMode (IRSensor3, INPUT); // sensor pin INPUT
  pinMode (IRSensor4, INPUT); // sensor pin INPUT
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

  // Clear the buffer.
  display.clearDisplay();

  // Display Text
  display.setTextSize(1);
  display.setTextColor(WHITE);
 
  display.display();
  
 // display.clearDisplay();

}

void loop()
{
  int statusSensor1 = digitalRead (IRSensor1);
  int statusSensor2 = digitalRead (IRSensor2);
  int statusSensor3 = digitalRead (IRSensor3);
  int statusSensor4 = digitalRead (IRSensor4);
  
    if (statusSensor1 == 1)
    {
      IR[0]=1;
      Serial.println("1:EMPTY"); // LED LOW
    }
  if (statusSensor2 == 1)
    {
    IR[1]=1;
    Serial.println("2:EMPTY"); // LED LOW
    } // LED LOW
  if (statusSensor3 == 1)
    {
    IR[2]=1;
    Serial.println("3:EMPTY"); 
    } // LED LOW
  if (statusSensor4 == 1)
    {
    IR[3]=1;
    Serial.println("4:EMPTY"); 
    } // LED LOW


    
  if (statusSensor1 == 0)
   {
    IR[0]=1;
    Serial.println("1:FULL"); // LED HIGH
   }
  if (statusSensor2 == 0)
   {
    IR[1]=0;
    Serial.println("2:FULL"); // LED LOW
   } // LED LOW
  if (statusSensor3 == 0)
   {
    IR[2]=0;
    Serial.println("3:FULL"); // LED LOW
   } // LED LOW
  if (statusSensor4 == 0)
  {
    IR[3]=0;
    Serial.println("4:FULL"); // LED LOW
   } // LED LOW
        display.setCursor(0,0);
        display.println("EMPTY SLOTS:");
      //  display.setTextSize(1);
      //  display.setTextColor(WHITE);
        display.setCursor(83,0);
  
    for(int i =0 ; i < 4; i++)
    {
      if(IR[i]==1)
      { Serial.print(i+1);
        display.print(i+1);
        display.print(" ");
       
      }
    }

   if(IR[0]==0 && IR[1]==0 && IR[2]==0 && IR[3]==0)
    {
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.print("PARKING FULL");
    }
   display.display();
  delay(2000);
  display.clearDisplay();
}
