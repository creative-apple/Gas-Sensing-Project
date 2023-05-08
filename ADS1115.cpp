#include <Adafruit_ADS1X15.h>
#include "ADS1115.h"


/* PIN MAP
 * D1 - SCL
 * D2 - SDA
 */
void ADC1115_Init(void)
{
  ads1115_1.begin(0x48);
  ads1115_1.setGain(GAIN_TWOTHIRDS);
  ads1115_2.begin(0x49);
  ads1115_2.setGain(GAIN_TWOTHIRDS);
  Serial.println("--------------------ADC1115_Init Done-----------------");
}

void ADC1115_Read_Data(float * adc)
{
  for(int i=0;i<4;i++)
  {
    adc[i]   = ads1115_1.readADC_SingleEnded(i);
    adc[i+4] = ads1115_2.readADC_SingleEnded(i);
  }
}

void ADC1115_Print_Data(float * adc)
{
  Serial.println("ADC data");
  for(int i=0;i<8;i++)
  {
    Serial.printf("%f, ",adc[i]);
  }
}
