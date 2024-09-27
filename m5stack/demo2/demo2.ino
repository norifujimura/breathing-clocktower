#include <M5Unified.h>
//#include <M5Core2.h>
#include <Adafruit_NeoPixel.h>
//const int TIMEOUT = 30000;

//binary
uint8_t* bin;

const int len = 180;
int rLen = 0;
int count = 0;
//https://qiita.com/hikoalpha/items/c4931230bebdf3c3955b
uint8_t buf[len];

//static void showValue(const void* mem, uint32_t len);

//https://arduino.stackexchange.com/questions/8457/serial-read-vs-serial-readbytes

//LED
int ledPin = 2;//core2: 32
int ledBrightness = 255;
int ledLength = 180;  //300 for 5m. 60 for 1m

Adafruit_NeoPixel strip(ledLength, ledPin, NEO_GRBW + NEO_KHZ800);

uint8_t red=  0;
uint8_t green = 0;
uint8_t blue = 0;

int degCounter = 0;

String state = "taito";//red,gree,blue,white,all

int r = 0;
int g = 0;
int b = 0;
int rw = 0;
int gw = 0;
int bw = 0;
int ww = 0;


//static void HslToRgb(double hue, double saturation, double lightness);

void setup() {
 M5.begin();
  Serial.begin(115200);
  setupLED();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("OK");

}

void loop() {
  M5.update();

  long time = millis();
  int min = time/1000/60;

  int minTwo = round(min%10);
  if(0<=minTwo && minTwo<2){
    state = "kaito";
  }else if(1<minTwo && minTwo<4){
    state = "maiko";
  }else if(3<minTwo && minTwo<6){
    state = "yohko";
  }else if(5<minTwo && minTwo<8){
    state = "taito";
  }else{
     state = "none";
  }

  if (M5.BtnA.wasReleased()) {
    if(state == "taito"){
      state = "kaito";
    }else if(state == "kaito"){
      state = "maiko";
    }else if(state == "maiko"){
      state = "yohko";
    }else if(state == "yohko"){
      state = "none";
    }else if(state == "none"){
      state = "taito";
    }
  }

  if(degCounter>360){
    degCounter = 0;
  }

  bleathSin4(255,degCounter);

  degCounter+=1;

  delay(50);

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println(state);
  M5.Lcd.setCursor(0, 30);
  M5.Lcd.println(min);
  M5.Lcd.setCursor(0, 50);
  M5.Lcd.println(minTwo);
  M5.Lcd.setCursor(0, 70);
  M5.Lcd.println(rw);
  M5.Lcd.setCursor(30, 70);
  M5.Lcd.println(gw);
  M5.Lcd.setCursor(60, 70);
  M5.Lcd.println(bw);
  M5.Lcd.setCursor(90, 70);
  M5.Lcd.println(ww);
  /*
  unsigned long timeout = millis() + TIMEOUT;
  uint8_t inIndex = 0;
  while ( ((int32_t)(millis() - timeout) < 0) && (inIndex < (sizeof(inData)/sizeof(inData[0])))) {
      if (Serial.available() > 0) {
          // read the incoming byte:
          inData[inIndex] = Serial.read();
          if (inIndex == length) {
              break;
          }
      }
  }
  */
}

/*
void serialEvent() {
    //https://arduinogetstarted.com/reference/serial-readbytesuntil
  // check if data is available
  if (Serial.available() > 0) {
    char c = char(255);
    rLen = Serial.readBytesUntil(c, buf, len);
    if(rLen==(len-1)){
      showValue();
      showLED();
    }
    
    Serial.flush();
  }
}
*/

/*
void serialEvent() {

  uint8_t character= 255;

  rLen = Serial.readBytesUntil(char(255), buf, len);
  //Serial.readBytes(buf, len);
  
  /*
  uint8_t index= 0;

  while(Serial.available()>0){
    buf[index] = Serial.read();
    if(buf[index] == 255){
      break;
    }
    
    //Serial.readBytes(buf, len);
    index++;
  }
  
  //Serial.flush();
  //showValue();
  
  
}
*/


void showValue(){

  M5.Lcd.fillRect(0,100,320,120, BLACK);

  /*
  for(int i = 0;i<len;i++){
    int w;
    w = buf[i];
    
    if(w == 254){
      uint16_t rgbColor = 0;
      rgbColor = M5.Lcd.color565(255, 255, 255);
      //rgbColor = M5.Lcd.color565(10,10,10);

      M5.Lcd.drawLine(i, 100,i,240,rgbColor); 
    }else{
      uint16_t rgbColor = 0;
      rgbColor = M5.Lcd.color565(0,0,0);
      //rgbColor = M5.Lcd.color565(10,10,10);

      M5.Lcd.drawLine(i, 100,i,240,rgbColor); 
    }
    
    uint16_t rgbColor = 0;
    rgbColor = M5.Lcd.color565(w, w, w);
    //rgbColor = M5.Lcd.color565(10,10,10);

    int x = i;
    if(x>319){
      x = 319;
    }

    M5.Lcd.drawLine(x, 100,x,240,rgbColor); 
  }
  */

  for(int i = 0;i<len;i++){
    int w;
    w = buf[i];
    uint16_t wColor = 0;
    wColor = M5.Lcd.color565(w, w, w);

    /*
    int x = i;
    */
    int x = round(i/4);
    if(x>300){
      x = 300;
    }
    //M5.Lcd.drawLine(x, 120,x,240,wColor); 
    if(w>0){
      M5.Lcd.fillRect(x-1, 120,4,120, wColor);
    }
    
  }

  M5.Lcd.setTextSize(2);
  M5.Lcd.println(rLen, DEC);
  
}

float degToRad(float deg){
  float rad = (deg * 71) / 4068;
  return rad;
}


