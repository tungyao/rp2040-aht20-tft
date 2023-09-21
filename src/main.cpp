#include <Wire.h>
#include <TFT_eSPI.h>       // Include the graphics library
TFT_eSPI tft = TFT_eSPI();  // Create object "tft"
void readAHT20Data();



void setup() {
  Wire.begin();
  // 设置AHT20的I2C地址
  Wire.beginTransmission(0x38);
  Wire.endTransmission();
  delay(500);


  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_DARKGREY);
  tft.setTextFont(2);
}

void loop() {

  tft.fillRectHGradient(0, 0, 160, 50, TFT_MAGENTA, TFT_BLUE);
  tft.setCursor(10,10);
  tft.print("Horizontal gradient");

  readAHT20Data();
  // 处理读取到的数据
  // TODO: 在这里处理读取到的数据

  delay(1000);
}
void readAHT20Data() {
  // 发送命令来读取数据
  Wire.beginTransmission(0x38);
  Wire.write(0xAC);
  Wire.write(0x33);
  Wire.write(0x00);
  Wire.endTransmission();

  // 延迟等待传感器测量完成
  delay(100);

  // 请求传感器发送数据
  Wire.beginTransmission(0x38);
  Wire.write(0x00);
  Wire.endTransmission();

  // 读取传感器发送的数据
  Wire.requestFrom(0x38, 6);
  while (Wire.available()) {
    byte msb = Wire.read();
    byte lsb = Wire.read();
    byte crc = Wire.read();
    // 解析数据
    // TODO: 在这里处理接收到的数据
  }
}
