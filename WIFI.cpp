#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>
#include "WIFI.h"


void WIFI_Init(void)
{
  Serial.printf("Connecting to %s\n", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) //wait until wifi is connected
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("My IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("--------------------WIFI_Init Done--------------------");
}


void WIFI_Send_Data(float * adc)
{
  WIFI_Connect_Tcp_Server();

  String data = "func=addData";
  WIFI_Combine_Date(&data, adc);
  Serial.println(data);

  //서버로 데이터 송신 - client.print()
  //GET 메서드 사용
  //"?" 마크를 통해 URL의 끝을 알리면서, 데이터 표현의 시작점을 알린다.
  client.println("GET " + String(path) +"?"+ data + " HTTP/1.1");
  client.println("Host: " + String(host));
  client.println("Connection: close");
  client.println();
               
  delay(500);
  
  String section="header";
  while(client.available()) //서버로 부터 수신된게 있으면 출력
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



void WIFI_Combine_Date(String * data, float * adc)
{ 
  for(int i=0;i<8;i++)
  {
    *data = *data + "&" + "val" + String(i) + "="; // "&vali="
    *data = *data + String(adc[i]);
  }
//  *data = *data + "&val=" + String(adc[3]) + "&name=" + String(adc[5]);

}
