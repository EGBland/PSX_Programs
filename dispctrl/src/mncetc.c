#include "mncetc.h"

void int_to_bin_str(char *buf, int a) {
	int i;
	for(i = 0; i < 32; i++) {
		*(buf+31-i) = ((a & (1 << i)) >> i) + 0x30;
	}
}

void short_to_bin_str(char *buf, short a) {
	int i;
	for(i = 0; i < 16; i++) {
		*(buf+15-i) = ((a & (1 << i)) >> i) + 0x30;
	}
}