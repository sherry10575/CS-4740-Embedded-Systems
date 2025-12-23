#include "handcontroller.h"
#include "sys/pio.h"

#define RED_BTN_MASK   0x01
#define BLACK_BTN_MASK 0x02
#define DIR_MASK       0x04
#define TURN_MASK      0x18

void handcontroller_init(void) {
    // Initialization placeholder
}

hand_state_t read_hand_controller(hand_controller_t controller) {
    hand_state_t state;
    uint8_t addr = HC_BASE_ADDR + controller;

    state.raw_port_value = inb(addr);

    state.emergency = (state.raw_port_value & RED_BTN_MASK) ? BTN_DOWN : BTN_UP;
    state.horn = (state.raw_port_value & BLACK_BTN_MASK) ? BTN_DOWN : BTN_UP;
    state.direction = (state.raw_port_value & DIR_MASK) ? DIR_FORWARD : DIR_BACKWARD;

    uint8_t turn_bits = (state.raw_port_value & TURN_MASK) >> 3;
    switch(turn_bits) {
        case 0x01: state.turn_request = TURN_LEFT; break;
        case 0x02: state.turn_request = TURN_RIGHT; break;
        default:   state.turn_request = TURN_CENTER;
    }

    return state;
}
