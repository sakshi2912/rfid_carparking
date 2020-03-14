/*
 *
 * RST 9
 * MISO 12
 * MOSI 11
 * SCK 13
 * SDA 10

  BUZZER 7
 
 */
#include <SPI.h>
#include <MFRC522.h>
#include<Servo.h>

Servo toll;
#define SS_PIN 10
#define RST_PIN 9
#define SP_PIN 8
#define buzz 7
MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
  toll.attach(1);
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(buzz,OUTPUT);
  toll.write(0);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

//  Serial.print(F("PICC type: "));
    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
// Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
/*  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI ||
    piccType != MFRC522::PICC_TYPE_MIFARE_1K ||
    piccType != MFRC522::PICC_TYPE_MIFARE_4K ) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }*/

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? "" : "");
  }
  strID.toUpperCase();
  Serial.println(strID);
  if(strID.indexOf("14B74283")>=0)
  {
    Serial.println("YES");
    digitalWrite(buzz,LOW);  // buzzer disabled 
    toll.write(90);         // open
    delay(1300);             //wait
    toll.write(0);          //close
  }
  else {
    Serial.println("NO");
    digitalWrite(buzz,HIGH);    // buzzer enabled
    delay(500);                 //beep
    digitalWrite(buzz,LOW);     // stop beep 
    }
  Serial.print("Tap card key: ");
  
  Serial.println(strID);

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
 
}
