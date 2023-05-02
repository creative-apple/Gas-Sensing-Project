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
  //  Serial.print("AIN0: "); Serial.println(adc0);
//  Serial.print("AIN0 Voltage : "); Serial.println(adc0*0.1875/1000);
//  Serial.print("AIN1: "); Serial.println(adc1);
//  Serial.print("AIN1 Voltage : "); Serial.println(adc1*0.1875/1000);
//  Serial.print("AIN2: "); Serial.println(adc2);
//  Serial.print("AIN2 Voltage : "); Serial.println(adc2*0.1875/1000);
//  Serial.print("AIN3: "); Serial.println(adc3);
//  Serial.print("AIN3 Voltage : "); Serial.println(adc3*0.1875/1000);
//  Serial.print("AIN4: "); Serial.println(adc4);
//  Serial.print("AIN4 Voltage : "); Serial.println(adc4*0.1875/1000);
//  Serial.print("AIN5: "); Serial.println(adc5);
//  Serial.print("AIN5 Voltage : "); Serial.println(adc5*0.1875/1000);
//  Serial.print("AIN6: "); Serial.println(adc6);
//  Serial.print("AIN6 Voltage : "); Serial.println(adc6*0.1875/1000);
//  Serial.print("AIN7: "); Serial.println(adc7);
//  Serial.print("AIN7 Voltage : "); Serial.println(adc7*0.1875/1000);
//  Serial.println(" ");
}
