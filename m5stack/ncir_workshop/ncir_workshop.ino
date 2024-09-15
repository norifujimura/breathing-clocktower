/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5Core2 sample source code
*                          配套  M5Core2 示例源代码
* Visit for more information: https://docs.m5stack.com/en/unit/ncir
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/unit/ncir
*
* Product: ncir.  单点红外测温传感器
* Date: 2021/8/27
*******************************************************************************
  Please connect to Port  A,Use NCIR Unit to measure the temperature without contact and display the value on the screen.
  请连接端口A,使用NCIR单元无接触测量温度，并在屏幕上显示。
*/
#include <M5Core2.h>

//for graph
#define MAX_LEN 320
#define X_OFFSET 0
#define Y_OFFSET 100
#define X_SCALE 1
int pt;
int16_t val_buf[MAX_LEN] = {0};
//

  static uint16_t result;
  static float temperature,baseTemp;

void graph(int value,int fromLow,int fromHigh) {
  
  val_buf[pt] = map((int16_t)(value * X_SCALE), fromLow, fromHigh,  100, 0);

  if (--pt < 0) {
    pt = MAX_LEN - 1;
  }

  for (int i = 1; i < (MAX_LEN); i++) {
    int now_pt = (pt + i) % (MAX_LEN);
    M5.Lcd.drawLine(i + X_OFFSET, val_buf[(now_pt + 1) % MAX_LEN] + Y_OFFSET, i + 1 + X_OFFSET, val_buf[(now_pt + 2) % MAX_LEN] + Y_OFFSET, TFT_BLACK);
    if (i < MAX_LEN - 1) {
      M5.Lcd.drawLine(i + X_OFFSET, val_buf[now_pt] + Y_OFFSET, i + 1 + X_OFFSET, val_buf[(now_pt + 1) % MAX_LEN] + Y_OFFSET, TFT_WHITE);
    }
  }
}

void setup() {
  M5.begin();
  M5.lcd.setTextSize(2); 
  Wire.begin();
  Serial.begin(9600);

    Wire.beginTransmission(
      0x5A);  // Send Initial Signal and I2C Bus Address  发送初始信号和I2C总线地址
  Wire.write(
      0x07);  // Send data only once and add one address automatically.  只发送一次数据，并自动添加一个地址。

  
}

void loop() {
  M5.update();  //Read the press state of the key.
/*
  Wire.beginTransmission(
      0x5A);  // Send Initial Signal and I2C Bus Address  发送初始信号和I2C总线地址
  Wire.write(
      0x07);  // Send data only once and add one address automatically.  只发送一次数据，并自动添加一个地址。
      */
  Wire.endTransmission(false);  // Stop signal  停止信号

  Wire.requestFrom(
      0x5A,
      2);  // Get 2 consecutive data from 0x5A, and the data is stored only.  从0x5A中获取2个连续的数据，并且只存储这些数据。
 
  result = Wire.read();        // Receive DATA  接收数据
  result |= Wire.read() << 8;  // Receive DATA  接收数据

  //Wire.endTransmission(false);  // Stop signal  停止信号

  float temp = result * 0.02 - 273.15;

  if(temp<100){
    temperature = temp;
  }
  

  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) {
    showBatteryLevel();
    baseTemp= temperature;
    Serial.println('A');
  }
  if(M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200)) {
    showBatteryLevel();
    baseTemp= temperature;
    Serial.println('B');
  }
  if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200)) {
    showBatteryLevel();
    baseTemp= temperature;
    Serial.println('C');
  }

  graph(temperature,baseTemp-10,baseTemp+10);

  M5.lcd.fillRect(0, 20, 300, 100,BLACK);  // Fill the screen with black (to clear the
                         // screen).  将屏幕填充黑色(用来清屏)

  M5.lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.println("NCIR");
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  M5.lcd.setCursor(0, 20);
  M5.Lcd.printf("Temp: %.3f C",temperature);
  M5.lcd.setCursor(0, 40);
  M5.Lcd.printf("BaseTemp: %.3f C",baseTemp);
  String s = String(baseTemp)+","+String(temperature);
  Serial.println(s);
  delay(50);
}

void showBatteryLevel(){
  //https://community.m5stack.com/topic/2994/core2-how-to-know-the-current-battery-level/4
  float batVoltage = M5.Axp.GetBatVoltage();
  float batPercentage = ( batVoltage < 3.2 ) ? 0 : ( batVoltage - 3.2 ) * 100;
  String s = String("Battery:")+String(batPercentage ).c_str()+String("%");
   //M5.Lcd.drawString(s, 0, 100, 1); 
  int i = (int) batPercentage;
  M5.Lcd.setCursor(0, 240-20);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print(s);
  M5.Lcd.progressBar(0, 240-10, 320, 20, i); 
}
