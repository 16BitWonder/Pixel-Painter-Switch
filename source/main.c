#include <stdio.h>
#include <switch.h>
#include "functions.h"

//Global Variables
//Color Control, 0=Red, 1=Yellow, 2=Green, 3=Blue, 4=Cyan, 5=Purple, 6=White,
int currentColor = 0;
int col = 99;
int row = 50;
bool isDrawing = false;
bool fastCursor = false;
//Cursor size 0=1x1, 1=2x2, 2=3x3, 3=4x4,
int currentCursorSize = 0;

int main(int argc, char **argv)
{
	gfxInitDefault();

	//Initialize console. Using NULL as the second argument tells the console library to use the internal console structure as current one.
	consoleInit(NULL);

	//Draw Frame
	printf("\x1b[0;0H\e[47m                                                                                                                                                                ");
	printf("\x1b[100;0H                                                                                                                                                                ");
	for (int j = 2; j < 90; j++)
	{
		printf("\x1b[%d;0H ", j);
		printf("\x1b[%d;41H ", j);
		printf("\x1b[%d;160H ", j);
	}
	
	//Draw Controls
	printf("\x1b[4;14H\e[40mPixel-Painter");
	printf("\x1b[7;17HControls");
	printf("\x1b[10;4HZL/ZR = Cycle brush size Left/Right");
	printf("\x1b[13;6HLPad/LStick = Cursor controller");
	printf("\x1b[16;8HL/R = Cycle colors up/down");
	printf("\x1b[19;8HA = Toggle drawing/erasing");
	printf("\x1b[22;8HMinus = Clear drawing area");
	printf("\x1b[25;10HY = Toggle fast cursor");
	printf("\x1b[28;10HPlus = Exits to HBmenu");
	

	//Draw Out Color Selection
	for (int j = 31; j < 37; j++)
	{
		printf("\x1b[%d;2H\e[41m                                       ", j);
		printf("\x1b[%d;2H\e[43m     ", j+8);
		printf("\x1b[%d;36H\e[43m     ", j+8);
		printf("\x1b[%d;2H\e[42m     ", j+16);
		printf("\x1b[%d;36H\e[42m     ", j+16);
		printf("\x1b[%d;2H\e[44m     ", j+24);
		printf("\x1b[%d;36H\e[44m     ", j+24);
		printf("\x1b[%d;2H\e[46m     ", j+32);
		printf("\x1b[%d;36H\e[46m     ", j+32);
		printf("\x1b[%d;2H\e[45m     ", j+40);
		printf("\x1b[%d;36H\e[45m     ", j+40);
		printf("\x1b[%d;2H\e[47m     ", j+48);
		printf("\x1b[%d;36H\e[47m     ", j+48);
	}
	
	//Draw out initial cursor position
	printf("\x1b[%d;%dH\e[40m#", row, col);
	
	while(appletMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();
		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		u32 kHeld = hidKeysHeld(CONTROLLER_P1_AUTO);
		
		
		if (kDown & KEY_PLUS) break; // break in order to return to hbmenu
		if (kDown & KEY_MINUS) clearScreen(row, col, currentColor, isDrawing, currentCursorSize);
		//Handle A
		if (kDown & KEY_A)
		{
			if (isDrawing)
				isDrawing = false;
			else
				isDrawing = true;
			if (currentCursorSize == 0)
				updateCursor1x1(row, col, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 1)
				updateCursor2x2(row, col, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 2)
				updateCursor3x3(row, col, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 3)
				updateCursor4x4(row, col, row, col, currentColor, isDrawing, false, 0);
		}
		//Handle Y
		if (kDown & KEY_Y)
		{
			if (fastCursor)
				fastCursor = false;
			else
				fastCursor = true;
		}
		//Handle L
		if (kDown & KEY_L)
		{
			currentColor--;
			if (currentColor < 0)
				currentColor = 6;
			updateColorSelection(row, col, currentColor, isDrawing, currentCursorSize);
		}
		//Handle R
		if (kDown & KEY_R)
		{
			currentColor++;
			if (currentColor > 6)
				currentColor = 0;
			updateColorSelection(row, col, currentColor, isDrawing, currentCursorSize);
		}
		//Handle ZL
		if (kDown & KEY_ZL)
		{
			int prevSize = currentCursorSize;
			currentCursorSize--;
			if (currentCursorSize < 0)
				currentCursorSize = 3;
			if (currentCursorSize == 0)
				updateCursor1x1(row, col, row, col, currentColor, isDrawing, true, prevSize);
			if (currentCursorSize == 1)
				updateCursor2x2(row, col, row, col, currentColor, isDrawing, true, prevSize);
			if (currentCursorSize == 2)
				updateCursor3x3(row, col, row, col, currentColor, isDrawing, true, prevSize);
			if (currentCursorSize == 3)
				updateCursor4x4(row, col, row, col, currentColor, isDrawing, true, prevSize);
		}
		//Handle ZR
		if (kDown & KEY_ZR)
		{
			int prevSize = currentCursorSize;
			currentCursorSize++;
			if (currentCursorSize > 3)
				currentCursorSize = 0;
			if (currentCursorSize == 0)
				updateCursor1x1(row, col, row, col, currentColor, isDrawing, true, prevSize);
			if (currentCursorSize == 1)
				updateCursor2x2(row, col, row, col, currentColor, isDrawing, true, prevSize);
			if (currentCursorSize == 2)
				updateCursor3x3(row, col, row, col, currentColor, isDrawing, true, prevSize);
			if (currentCursorSize == 3)
				updateCursor4x4(row, col, row, col, currentColor, isDrawing, true, prevSize);
		}
		//Handle Up
		if  ((kDown & KEY_UP) || (fastCursor && (kHeld & KEY_UP)))
		{
			int tempRow = row;
			row--;
			if (row == 1)
				row = 89-currentCursorSize;
			if (currentCursorSize == 0)
				updateCursor1x1(tempRow, col, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 1)
				updateCursor2x2(tempRow, col, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 2)
				updateCursor3x3(tempRow, col, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 3)
				updateCursor4x4(tempRow, col, row, col, currentColor, isDrawing, false, 0);
		}
		//Handle Down
		if  ((kDown & KEY_DOWN) || (fastCursor && (kHeld & KEY_DOWN)))
		{
			int tempRow = row;
			row++;
			if (row == 90-currentCursorSize)
				row = 2;
			if (currentCursorSize == 0)
				updateCursor1x1(tempRow, col, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 1)
				updateCursor2x2(tempRow, col, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 2)
				updateCursor3x3(tempRow, col, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 3)
				updateCursor4x4(tempRow, col, row, col, currentColor, isDrawing, false, 0);
		}
		//Handle Left
		if  ((kDown & KEY_LEFT) || (fastCursor && (kHeld & KEY_LEFT)))
		{
			int tempCol = col;
			col--;
			if (col == 41)
				col = 159-currentCursorSize;
			if (currentCursorSize == 0)
				updateCursor1x1(row, tempCol, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 1)
				updateCursor2x2(row, tempCol, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 2)
				updateCursor3x3(row, tempCol, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 3)
				updateCursor4x4(row, tempCol, row, col, currentColor, isDrawing, false, 0);
		}
		//Handle Right
		if  ((kDown & KEY_RIGHT) || (fastCursor && (kHeld & KEY_RIGHT)))
		{
			int tempCol = col;
			col++;
			if (col == 160-currentCursorSize)
				col = 42;
			if (currentCursorSize == 0)
				updateCursor1x1(row, tempCol, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 1)
				updateCursor2x2(row, tempCol, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 2)
				updateCursor3x3(row, tempCol, row, col, currentColor, isDrawing, false, 0);
			if (currentCursorSize == 3)
				updateCursor4x4(row, tempCol, row, col, currentColor, isDrawing, false, 0);
		}

		gfxFlushBuffers();
		gfxSwapBuffers();
		gfxWaitForVsync();
	}

	gfxExit();
	return 0;
}