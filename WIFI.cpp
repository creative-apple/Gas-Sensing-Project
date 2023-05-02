#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>
#include "WIFI.h"

extern String url;

void WIFI_Init(void)
{
  Serial.printf("Connecting to %s\n", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) //wait until wifi is connected
  {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("My IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("--------------------WIFI_Init Done--------------------");
}

void WIFI_Send_Data(void)
{

  WIFI_Connect_Tcp_Server();
  float t = 3.14;
  /* GET 메서드
   * "?" 마크를 통해 URL의 끝을 알리면서, 데이터 표현의 시작점을 알린다.
   */
  url = "/macros/s/AKfycbxJDZ74RSEKnSelEl_8Azc_8vrTtsG3t2YwoWJM_STCUwsPElZUIJBIw2tRZKSe2QmlkQ/exec";
  String data = "func=addData&val=" + String(t);
  
//  Serial.print("Requesting URL: ");
//  Serial.println(url);

  //서버로 데이터 송신 - client.print()
  //GET 메서드 사용
  client.println("GET " + url +"?"+ data + " HTTP/1.1");
  client.println("Host: " + String(host));
  client.println("Connection: close");
  client.println();
               
  delay(500);
  
  String section="header";
  while(client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println("TCP connection closed");
  Serial.println();
  Serial.println();
  //client.stop(); // close the connection
}

void WIFI_Connect_Tcp_Server(void)
{
  //http 프로토콜을 사용하여 접근할 것이다.
  const int httpPort = 443; //https 포트 번호
  if (!client.connect(host, httpPort)) //TCP 서버와 연결
  {
    Serial.println("connection failed");
    return;
  }
  else
  {
    Serial.println("TCP connection established");
  }
}
