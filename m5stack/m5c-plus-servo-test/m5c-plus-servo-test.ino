#include <M5StickCPlus.h>

#include "CBACK_DRIVER.h"

bool flag = true;

String state = "init"; //init,0,5,15,30,45,60

CBACK_DRIVER Driver;

float degree = 0.0;

void setup() {
    M5.begin();
    Driver.Init();
    Serial.println("C Back Driver Test...");
    M5.Lcd.setTextColor(TFT_GREEN);
    M5.Lcd.setRotation(1);
    M5.Lcd.drawCentreString("C BACK Driver", 120, 30, 4);
    M5.Lcd.drawCentreString("Click Btn A Start", 120, 65, 4);
}

void loop() {

  degree = degree +1.0;
  if(degree>360){
    degree = 0;
  }

    float radian = (degree * 71) / 4068.0;

    double resultRaw = sin(radian);
    double result = (resultRaw+1.0)/2.0; // 0 to 1;

    double target = 60.0 * result;
    double targetRounded = round(target);
    int targetInt = int(targetRounded);


    M5.Lcd.fillScreen(BLACK);
      M5.Lcd.drawCentreString("Status:"+state, 120, 65, 4);
    if (M5.BtnA.wasPressed()) {
        if (flag){
          flag = false;
        }else{
          flag = true;
        }
    }

      Serial.print("0");
      Driver.SetServoAngle(1, targetInt);
      Driver.SetServoAngle(2, targetInt);
       Driver.SetOutput(1);

    
    Serial.print("PortB ADC: ");
    Serial.println(Driver.ReadADC());
    M5.update();
}
