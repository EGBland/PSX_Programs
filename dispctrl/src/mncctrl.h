#ifndef __MNCCTRL_H_DEFINED
#define __MNCCTRL_H_DEFINED 1

typedef void (*ctrl_callback_t)(char, unsigned short);

// initialise controllers
void ctrl_init();

// poll controller state
void poll_ctrl_state();

void provide_ctrl_press(ctrl_callback_t callback);

void provide_ctrl_release(ctrl_callback_t callback);

// get controller state; ctrl=0 for controller 1 and ctrl=1 for controller 2
unsigned short get_ctrl_state(char ctrl);

#endif