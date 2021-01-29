#include "mncetc.h"

int min(int a, int b) {
    return (a>b) ? b : a;
}

int max(int a, int b) {
    return (a<b) ? b : a;
}

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

void char_to_hex_str(char *buf, char a) {
	int i;
	char hi = (a >> 4) & (0x0f);
	char lo = (a)      & (0x0f);

	if(hi < 10) {
		*buf = hi + 48;
	}
	else {
		*buf = hi + 55;
	}

	if(lo < 10) {
		*(buf+1) = lo + 48;
	}
	else {
		*(buf+1) = lo + 55;
	}
}