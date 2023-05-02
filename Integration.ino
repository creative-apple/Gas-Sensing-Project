#include <Adafruit_ADS1X15.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include "Integration.h"
#include "ADS1115.h"
#include "WIFI.h"
#include "SERIAL.h"


Adafruit_ADS1115 ads1115_1;
Adafruit_ADS1115 ads1115_2;

WiFiClientSecure client;

String url;
float adc[8] = {1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f};       //adc 값을 담을 전역변수

void setup() {
  SERIAL_Init();    //시리얼 포트 활성화
  ADC1115_Init();   //ADC모듈 활성화
  WIFI_Init();      //wemos 내장 와이파이 활성화
  Serial.println("------------------------------------------------------");
  Serial.println("------------------------------------------------------");
  Serial.println("--------------------Setup is Done---------------------");
  Serial.println("------------------------------------------------------");
  Serial.println("------------------------------------------------------");
}

void loop()
{
//  ADC1115_Read_Data(adc);
//  ADC1115_Print_Data(adc);
  WIFI_Send_Data();
}
