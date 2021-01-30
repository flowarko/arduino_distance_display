/*
  Dev:      flowarko
  Version:  1
  Hardware: Elegoo Nano V3, HC-SR04, Oled-Display I2c;

  Pins:     HC-SR04 Ultrasonic Sensor
              echoPin = 2
              trigPin = 3
              VCC     = 5V
              GND
            Oled-Display I2c
              SDA     = A4
              SCL     = A5
              VCC     = 3,3V
              GND
*/
#include <U8g2lib.h>

//Display Config
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/
U8X8_PIN_NONE);
u8g2_uint_t offset;
u8g2_uint_t width;

//Hardware Variables
const int trigPin = 3;
const int echoPin = 2;

void setup(void) { 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   
  u8g2.begin();
  u8g2.setFont(u8g2_font_logisoso16_tf);
  u8g2.setFontMode(0);
}
void loop(void) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duration = pulseIn(echoPin, HIGH);
  float distance_cm = duration/58.2;  //duration in cm
  u8g2.firstPage();
  u8g2.setCursor(0, 16);
  u8g2.print("Distanz:");
  u8g2.setCursor(0,60);
  u8g2.print(distance_cm, 2);
  u8g2.setCursor(60,60);
  u8g2.print("cm");
  u8g2.nextPage(); 
  u8g2.clearBuffer();
}
