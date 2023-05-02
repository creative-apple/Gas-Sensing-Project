#ifndef WIFI_H_
#define WIFI_H_

#include <WiFiClientSecure.h>

extern WiFiClientSecure client;

#define ssid      "hipass2.4GHz"        //ssid = Service Set Identifier  와이파이 이름
#define password  "2612612526126125"
#define host      "script.google.com"   //구글 앱스 스크립트 주소
#define path      "/macros/s/AKfycbxJDZ74RSEKnSelEl_8Azc_8vrTtsG3t2YwoWJM_STCUwsPElZUIJBIw2tRZKSe2QmlkQ/exec"







void WIFI_Init(void);
void WIFI_Send_Data(float * adc);
void WIFI_Connect_Tcp_Server(void);
void WIFI_Combine_Date(String * data, float * adc);

#endif /* WIFI_H_ */
