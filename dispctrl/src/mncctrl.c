#include "mncctrl.h"

#include <stddef.h>
#include <libetc.h>
#include <libpad.h>

unsigned short pad1_status;
unsigned short pad2_status;
unsigned short pad1_status_prev;
unsigned short pad2_status_prev;

ctrl_callback_t on_ctrl_press;
ctrl_callback_t on_ctrl_release;

void provide_ctrl_press(ctrl_callback_t f) {
	on_ctrl_press = f;
}

void provide_ctrl_release(ctrl_callback_t f) {
	on_ctrl_release = f;
}

void ctrl_init() {
	PadInit(0);
	on_ctrl_press = (void *)0;
	on_ctrl_release = (void *)0;
}

void poll_ctrl_state() {
	unsigned int pads_status;
	int i;
	unsigned short pad1_diff, pad2_diff;
	
	pad1_status_prev = pad1_status;
	pad2_status_prev = pad2_status;
	
	pads_status = PadRead(0);
	pad1_status = (unsigned short)(pads_status & 0x0000ffff);
	pad2_status = (unsigned short)((pads_status & 0xffff0000) >> 16);
	
	pad1_diff = pad1_status ^ pad1_status_prev;
	pad2_diff = pad2_status ^ pad2_status_prev;
	
	// check for presses on controller 1
	if(pad1_diff & pad1_status) {
		if(on_ctrl_press) (*on_ctrl_press)(0, pad1_diff & pad1_status);
	}
	
	// check for releases on controller 1
	if(pad1_diff & (~pad1_status)) {
		if(on_ctrl_release) (*on_ctrl_release)(0, pad1_diff & (~pad1_status));
	}
}

unsigned short get_ctrl_state(char ctrl) {
	if(ctrl) {
		return pad2_status;
	}
	
	else {
		return pad1_status;
	}
}