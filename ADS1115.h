#ifndef ADS1115_H_
#define ADS1115_H_


extern Adafruit_ADS1115 ads1115_1;
extern Adafruit_ADS1115 ads1115_2;



void ADC1115_Init(void);
void ADC1115_Read_Data(float * adc);
void ADC1115_Print_Data(float * adc);

#endif /* ADS1115_H_ */
