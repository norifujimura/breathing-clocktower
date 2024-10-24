//#include <M5Core2.h>
#include <M5Unified.h>

/*
void showRGBW(){
    String s = String(r)+","+String(g)+","+String(b)+","+String(w);
    Serial.println(s);

    M5.Lcd.setCursor(0, 240-40);
    M5.Lcd.setTextSize(2);
    M5.Lcd.print(s);

    uint16_t rgbColor = 0;
    rgbColor = M5.Lcd.color565(r, g, b);
    uint16_t whiteColor = 0;
    whiteColor = M5.Lcd.color565(w,w,w);
    
    uint16_t blended = 0;
    blended = M5.Lcd.alphaBlend(128, rgbColor, whiteColor);
  
    M5.Lcd.fillRect(0,40, 320, 240-82, blended); 
}
*/

void sendAlive(BLECharacteristic *pCharacteristic){
  pCharacteristic->setValue("alive");
}

void parseReceivedJson(uint8_t *payload){
 char *json = (char *)payload;
 DeserializationError error = deserializeJson(doc, json);
 
 if (error) {
   Serial.print(F("deserializeJson() failed: "));
   Serial.println(error.c_str());
   return;
 }
  
  //deserializeJson(doc, json);
 //JsonObject obj = doc.as<JsonObject>();

}

void parseReceivedJson2(char json[]){
  DeserializationError error = deserializeJson(doc, json);
 
 if (error) {
   Serial.print(F("deserializeJson() failed: "));
   Serial.println(error.c_str());
   return;
 }
  
  //deserializeJson(doc, json);
 //JsonObject obj = doc.as<JsonObject>();

}

void showName(){
  Serial.println(bleName);

  M5.Lcd.setCursor(0, 240-240);
  M5.Lcd.setTextSize(4);
  M5.Lcd.print(bleName);
}

void showValue(){
  M5.Lcd.clear();
  M5.Lcd.fillRect(x, y, 4, 4, WHITE);

  /*
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextSize(2);
  
  M5.Lcd.print(x);
  M5.Lcd.print(":");
  M5.Lcd.print(y);
  M5.Lcd.print(" ");
  */
}

/*
void showValue(){

  M5.Lcd.clear();

  String s = String(value);
  Serial.println(s);

  M5.Lcd.setCursor(0, 240-40);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print(s);
  M5.Lcd.print(" ");

  M5.Lcd.drawLine(0, 120, 320,120,DARKGREY); 

  int x = 0, y = 0;


  if(-160<value && value<0){
    //right
    x = -1*value + 160;
    y = 118;
    M5.Lcd.fillRect(x, y, 4, 4, WHITE);
  }else if(0<value && value<160){
    //left
    x = 160 - value;
    y = 118;
    M5.Lcd.fillRect(x, y, 4, 4, WHITE);
  }
  
  uint16_t rgbColor = 0;
  rgbColor = M5.Lcd.color565(r, g, b);
  uint16_t whiteColor = 0;
  whiteColor = M5.Lcd.color565(w,w,w);
  
  uint16_t blended = 0;
  blended = M5.Lcd.alphaBlend(128, rgbColor, whiteColor);

  M5.Lcd.fillRect(0,40, 320, 240-82, blended); 
  
}
*/
