#include <stdio.h>
#include "adc.h"

int main(void) {
    printf("=== ADC Channel Voltage Test ===\\n");
    printf("Press ENTER to read all 8 channels.\\n");
    printf("Press Ctrl+C to exit.\\n\\n");

    while (1) {
        getchar();
        printf("\\nADC Readings:\\n");

        for (int ch = 0; ch < ADC_CHANNELS; ch++) {
            float voltage = read_adc_voltage(ch);
            printf("  CH%d: %+6.2f V", ch, voltage);

            if (ch == 2 || ch == 5) printf("\\n");
        }

        printf("\\n--- End Sample ---\\n");
    }

    return 0;
}
