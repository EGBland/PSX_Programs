#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include <libapi.h>
#include <kernel.h>
#include <malloc.h>
#include <rand.h>
#include <libetc.h>

#include "mncetc.h"

////////////////////////////////////////////////////
//
// INIT
//
////////////////////////////////////////////////////
#define OT_LENGTH 1
#define MAX_PACKETS 18
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

GsOT theOT[2];
GsOT_TAG theOT_TAG[2][1<<OT_LENGTH];
PACKET GPUPackets[2][MAX_PACKETS];

u_long _ramsize = 0x00200000;    // 2048kb
u_long _stacksize = 0x00004000;  //   16kb
#define STACK (0x80000000 + _ramsize - _stacksize)

short currentBuffer = 0;
u_long heap_base[4];

////////////////////////////////////////////////////
//
// VARS
//
////////////////////////////////////////////////////
char *the_int;
int i;
unsigned short pad1 = 0;
unsigned short lkp = 0;
unsigned int counter = 0;

////////////////////////////////////////////////////
//
// PROTOTYPES
//
////////////////////////////////////////////////////
void init();
void draw();
void lkp_callback(char, unsigned short);

////////////////////////////////////////////////////
//
// IMPLEMENTATIONS
//
////////////////////////////////////////////////////
int main() {
	init();
	FntLoad(960, 256);
	SetDumpFnt(FntOpen(5, 20, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 512));

	while(1) {
		//counter = GetRCnt(0);
		
		sprintf(the_int, "    S  S    RLRL\n");
		sprintf(the_int+17, "LDRUT  ESXOT1122\n");
		short_to_bin_str(the_int+34, pad1);
		*(the_int+50)='\n';
		short_to_bin_str(the_int+51, lkp);
		sprintf(the_int+67, "\n%d\0", counter);
		FntPrint(the_int);
		draw();
	}
	return 0;
}

void init() {
	ResetCallback();
	PadInit(0);
	InitHeap3((u_long *)heap_base, STACK-(u_long)heap_base);
	
	provide_ctrl_press(*lkp_callback);
	
	the_int = (char *)malloc3(256*sizeof(char));
	
	SetVideoMode(0);
	GsInitGraph(SCREEN_WIDTH, SCREEN_HEIGHT, GsNONINTER|GsOFSGPU, 1, 0);
	GsDefDispBuff(0, 0, 0, SCREEN_HEIGHT);

	theOT[0].length = OT_LENGTH;
	theOT[1].length = OT_LENGTH;
	theOT[0].org = theOT_TAG[0];
	theOT[1].org = theOT_TAG[1];

	GsClearOt(0, 0, &theOT[0]);
	GsClearOt(0, 0, &theOT[1]);
}

void draw() {
	poll_ctrl_state();
	pad1 = get_ctrl_state(0);
	FntFlush(-1);
	currentBuffer = GsGetActiveBuff();
	GsSetWorkBase((PACKET*)GPUPackets[currentBuffer]);
	GsClearOt(0, 0, &theOT[currentBuffer]);
	DrawSync(0);
	VSync(0);
	GsSwapDispBuff();
	GsSortClear(50, 50, 50, &theOT[currentBuffer]);
	GsDrawOt(&theOT[currentBuffer]);
}

void lkp_callback(char ctrl, unsigned short diff) {
	counter++;
	if(ctrl) {}
	else {
		lkp = diff;
	}
}