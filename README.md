# rfid_carparking
An RFID based automated car parking system to ease parking.

1. Connections to be made as in connections.txt
2. Test the Rfid sensor using the code in Rfid.ino 
3. Test the IR and OLED sensors using the code in IR.ino 
4. To the final connections , upload carp.ino .

Possible errors :
1. OLED not displaying anything : 
   Check the OLED address , try with the following two addresses - '0x3C' and '0X3F'
   Try powering the OLED with 3.3V if not 5V
2. IR sensors not detecting properly :
   Caliberate the IR sensor using the potentiometer.
3. Servo motor twitching /not working :
   1. Insufficient power supply. Servo motor requires 5V of supply.
   2. Gnd and +5 interchanged
DO NOT POWER SERVO MOTORS WITH LITHIUM ION BATTERIES 


Working model : https://youtu.be/TyeHmX3Uz6s
