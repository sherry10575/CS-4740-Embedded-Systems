#include "dac.h"
#include "sys/pio.h"
#include <stdint.h>

void dac_init(void) {
    // Initialization placeholder
}

void set_dac_voltage(int channel, float voltage) {
    if (channel < 0 || channel >= DAC_CHANNELS) {
        return;
    }

    if (voltage < -5.0f) voltage = -5.0f;
    if (voltage > 5.0f) voltage = 5.0f;

    uint16_t value = (uint16_t)((voltage + 5.0f) / 10.0f * 4095.0f);
    uint16_t address = DAC_BASE + (2 * channel);

    outw(address, value);
}
