#include <stdio.h>
#include "handcontroller.h"

int main(void) {
    handcontroller_init();
    printf("=== Hand Controller Digital Input Test ===\\n");
    printf("Press ENTER to sample all three controllers.\\n");
    printf("Press Ctrl+C to exit.\\n\\n");

    while (1) {
        getchar();
        printf("\\n--- Sampling ---\\n");

        for (int i = 0; i < NUM_CONTROLLERS; i++) {
            hand_state_t s = read_hand_controller((hand_controller_t)i);

            printf("Controller %c: RAW=0x%02X  ", 'A' + i, s.raw_port_value);
            printf("EM:%s HN:%s DIR:%s TURN:%s\\n",
                s.emergency == BTN_DOWN ? "DOWN" : "UP",
                s.horn == BTN_DOWN ? "DOWN" : "UP",
                s.direction == DIR_FORWARD ? "FWD" : "BACK",
                s.turn_request == TURN_LEFT ? "LEFT" :
                s.turn_request == TURN_RIGHT ? "RIGHT" : "CENTER");
        }

        printf("--- End Sample ---\\n");
    }

    return 0;
}
