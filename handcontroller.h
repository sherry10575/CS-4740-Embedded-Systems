#ifndef HANDCONTROLLER_H
#define HANDCONTROLLER_H

#include <stdint.h>

#define HC_BASE_ADDR 0x240
#define NUM_CONTROLLERS 3

typedef enum {
    CONTROLLER_A,
    CONTROLLER_B,
    CONTROLLER_C
} hand_controller_t;

typedef enum {
    BTN_UP,
    BTN_DOWN
} button_state_t;

typedef enum {
    DIR_BACKWARD,
    DIR_FORWARD
} direction_t;

typedef enum {
    TURN_CENTER,
    TURN_LEFT,
    TURN_RIGHT
} turn_request_t;

typedef struct {
    uint8_t raw_port_value;
    button_state_t emergency;
    button_state_t horn;
    direction_t direction;
    turn_request_t turn_request;
} hand_state_t;

void handcontroller_init(void);
hand_state_t read_hand_controller(hand_controller_t controller);

#endif
