#ifndef WIFI_H_
#define WIFI_H_

#include <WiFiClientSecure.h>

extern WiFiClientSecure client;

//#define ssid      "hipass2.4GHz"        //ssid = Service Set Identifier  와이파이 이름
//#define password  "2612612526126125"
#define ssid      "817 (NDL)"        //ssid = Service Set Identifier  와이파이 이름
#define password  "nanodev123456"
#define host      "script.google.com"   //구글 앱스 스크립트 주소
#define path      "/macros/s/AKfycbzgxtBaMKhGTBi5CIL83pkpFwyEFgE5TUqTwA_42xR9uF6FKIQOhM5sQxgZdy7fTAcudw/exec"
//#define path      "/macros/s/AKfycbxZMYWI9otF9KBL0xnFi5NwdTR2iiPoHMjn9uxCDtvn/dev"





void WIFI_Init(void);
void WIFI_Send_Data(float * adc);
void WIFI_Connect_Tcp_Server(void);
void WIFI_Combine_Date(String * data, float * adc);

#endif /* WIFI_H_ */
