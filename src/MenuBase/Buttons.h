int LocalButtons = 0xD19800;
enum Buttons
{
	UP = 0x1FF,
	DOWN = 0x20F,
	RIGHT = 0x22F,
	LEFT = 0x21F,
	R3 = 0x1CF,
	L3 = 0x1BF,
	SQUARE = 0xEF,
	CROSS = 0xCF,
	TRIANGLE = 0xFF,
	CURCLE = 0xDF,
	APAD_UP = 0x27F,
	APAD_LEFT = 0x29F,
	APAD_RIGHT = 0x2AF,
	APAD_DOWN = 0x28F,
	R2 = 0x1EF,
	L2 = 0x1DF,
	L1 = 0x10F,
	R1 = 0x11F,
	SELECT = 0x1AF,
	START = 0x19F
};
bool detect(Buttons Button)
{
	return (*(int*)(LocalButtons + Button) != 0);
}

/*
//SDK button monitoring, works on every game
//Doesn't work well in paint hook, may work better in separate thread
//Keeps getting detected for about a second after letting go of the button

#include <cell/pad.h>
#include <time.h> 
#include <sys\spu_thread.h>

#define LEFT (1 << 7)
#define DOWN (1 << 6)
#define RIGHT (1 << 5)
#define UP (1 << 4)
#define START (1 << 3)
#define R3 (1 << 2)
#define L3 (1 << 1)
#define SELECT (1 << 0)
#define SQUARE (1 << 15)
#define CROSS (1 << 14) 
#define CIRCLE (1 << 13)
#define TRIANGLE (1 << 12)
#define R1 (1 << 11)
#define L1 (1 << 10)
#define R2 (1 << 9)
#define L2 (1 << 8)

CellPadData PadData;

bool KeyPressed(int key) {
	cellPadGetData(0, &PadData);
	_Uint32t _key = (PadData.button[3] << 8) + PadData.button[2];
	return ((_key == key) & 1);
}

int Key() {
	cellPadGetData(0, &PadData);
	_Uint32t _key = (PadData.button[3] << 8) + PadData.button[2];
	return _key;
}
*/