# Hand Controller Test Plan

## Test Environment
- TCS System powered on
- Hand controllers physically connected
- Terminal program running on development VM

## Test Cases
| TC-ID | Controller | Physical State | Expected raw_value | Expected Decoded State |
|-------|------------|----------------|-------------------|------------------------|
| HC-01 | A          | All buttons UP, switch CENTER, throttle MIN | 0x1C | EM:UP, HN:UP, DIR:FWD, TURN:CENTER |
| HC-02 | A          | Red button DOWN | 0x1D | EM:DOWN, HN:UP, DIR:FWD, TURN:CENTER |
| HC-03 | A          | Black button DOWN | 0x1E | EM:UP, HN:DOWN, DIR:FWD, TURN:CENTER |
| HC-04 | A          | Direction switch BACKWARD | 0x18 | EM:UP, HN:UP, DIR:BACK, TURN:CENTER |
| HC-05 | A          | Turn switch LEFT | 0x14 | EM:UP, HN:UP, DIR:FWD, TURN:LEFT |
| HC-06 | A          | Turn switch RIGHT | 0x10 | EM:UP, HN:UP, DIR:FWD, TURN:RIGHT |
| HC-07 | B          | All buttons UP, switch CENTER | 0x1C | EM:UP, HN:UP, DIR:FWD, TURN:CENTER |
| HC-08 | C          | All buttons DOWN, switch LEFT | 0x07 | EM:DOWN, HN:DOWN, DIR:BACK, TURN:LEFT |

## Test Procedure
1. Compile test program: `mgcc -o hc_test handcontroller_test.c handcontroller.c -I.`
2. Upload to TCS: `scp hc_test [user]@student.cs.uni.edu:/srv/tftp/trainlab/projects/solo`
3. On TCC, select program from menu
4. Press ENTER to sample controller states
5. Verify printed values match expected states
