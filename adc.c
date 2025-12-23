#include "adc.h"
#include "sys/pio.h"
#include <stdint.h>

float read_adc_voltage(int channel) {
    if (channel < 0 || channel >= ADC_CHANNELS) {
        return 0.0f;
    }

    outb(ADC_BASE + 2, channel);
    outb(ADC_BASE + 1, 0x00);

    while (inb(ADC_BASE + 2) & 0x80);

    uint16_t raw = inw(ADC_BASE);
    raw = (raw >> 4) & 0x0FFF;

    return ((float)raw / 4095.0f) * 10.0f - 5.0f;
}
