#ifndef ADC_H
#define ADC_H

#define ADC_CHANNELS 8
#define ADC_BASE 0x240

float read_adc_voltage(int channel);

#endif
