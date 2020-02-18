#define M5STACK_MPU6886

#include <Arduino.h>
#include <BluetoothSerial.h>
#include <M5Stack.h>

BluetoothSerial SerialBT;

float accX  = 0.0F;
float accY  = 0.0F;
float accZ  = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float pitch = 0.0F;
float roll  = 0.0F;
float yaw   = 0.0F;

float temp  = 0.0F;

void setup() 
{
  Serial.begin(115200);
  SerialBT.begin("M5Stack");

  M5.begin();
  M5.Power.begin();
  M5.IMU.Init();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("I am alive, ma dude");
}

void loop() 
{
  M5.IMU.getGyroData(&gyroX,&gyroY,&gyroZ);
  M5.IMU.getAccelData(&accX,&accY,&accZ);
  M5.IMU.getAhrsData(&pitch,&roll,&yaw);
  M5.IMU.getTempData(&temp);
  
  SerialBT.write(gyroX);
  SerialBT.write(gyroY);
  SerialBT.write(gyroZ);

  SerialBT.write(accX);
  SerialBT.write(accY);
  SerialBT.write(accZ);

  SerialBT.write(pitch);
  SerialBT.write(roll);
  SerialBT.write(yaw);

  SerialBT.write(temp);

  SerialBT.write('\n');
  delay(100);

  // M5.Lcd.setCursor(0, 20);
  // M5.Lcd.printf("%6.2f  %6.2f  %6.2f      ", gyroX, gyroY, gyroZ);
  // M5.Lcd.setCursor(220, 42);
  // M5.Lcd.print(" o/s");
  // M5.Lcd.setCursor(0, 65);
  // M5.Lcd.printf(" %5.2f   %5.2f   %5.2f   ", accX, accY, accZ);
  // M5.Lcd.setCursor(220, 87);
  // M5.Lcd.print(" G");
  // M5.Lcd.setCursor(0, 110);
  // M5.Lcd.printf(" %5.2f   %5.2f   %5.2f   ", pitch, roll, yaw);
  // M5.Lcd.setCursor(220, 132);
  // M5.Lcd.print(" degree");
  // M5.Lcd.setCursor(0, 155);
  // M5.Lcd.printf("Temperature : %.2f C", temp);

  // delay(1);


  // if(Serial.available()){
  //   SerialBT.write(Serial.read());
  // }
  // if(SerialBT.available()){
  //   Serial.write(SerialBT.read());
  // }
}