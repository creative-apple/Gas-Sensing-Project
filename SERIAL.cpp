
#include <Arduino.h>

void SERIAL_Init(void)
{
  Serial.begin(115200);
  Serial.println("------------------------------------------------------");
  Serial.println("--------------------Start Program!--------------------");
  Serial.println("------------------------------------------------------");
  Serial.println("------------------------------------------------------");
  Serial.println("--------------------SERIAL_Init Done-------------------");
}
