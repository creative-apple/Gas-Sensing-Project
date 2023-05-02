#ifndef WIFI_H_
#define WIFI_H_

#include <WiFiClientSecure.h>


#define ssid      "hipass2.4GHz"        //ssid = Service Set Identifier  와이파이 이름
#define password  "2612612526126125"
#define host      "script.google.com"   //구글 앱스 스크립트 주소




extern WiFiClientSecure client;




void WIFI_Init(void);
void WIFI_Send_Data(void);
void WIFI_Connect_Tcp_Server(void);

#endif /* WIFI_H_ */
