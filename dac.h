#ifndef DAC_H
#define DAC_H

#define DAC_CHANNELS 6
#define DAC_BASE 0x250

void set_dac_voltage(int channel, float voltage);
void dac_init(void);

#endif
