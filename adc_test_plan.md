# ADC Test Plan

## Test Environment
- TCS System powered on
- Hand controllers connected (channels 0-2)
- Voltmeter available for physical verification
- Terminal program running

## Test Cases
| TC-ID | Channel | Expected Range | Physical State | Notes |
|-------|---------|----------------|----------------|-------|
| ADC-01 | 0 | -5.0V to +5.0V | Throttle MIN to MAX | Verify linear change |
| ADC-02 | 1 | -5.0V to +5.0V | Throttle MIN to MAX | Verify linear change |
| ADC-03 | 2 | -5.0V to +5.0V | Throttle MIN to MAX | Verify linear change |
| ADC-04 | 3 | ~0.0V ± noise | Unconnected | Expect noise |
| ADC-05 | 4 | ~0.0V ± noise | Unconnected | Expect noise |
| ADC-06 | 5 | ~0.0V ± noise | Unconnected | Expect noise |
| ADC-07 | 6 | ~0.0V ± noise | Unconnected | Expect noise |
| ADC-08 | 7 | ~0.0V ± noise | Unconnected | Expect noise |

## Test Procedure
1. Compile: `mgcc -o adc_test adc_test.c adc.c -I.`
2. Upload to TCS
3. Run program, press ENTER to sample all channels
4. Compare printed voltages with physical measurements
5. Verify channels 0-2 track throttle position
