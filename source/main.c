#include <string.h>
#include <stdio.h>

#include <switch.h>

//Declare Functions
void updateColorSelection();
void updateCursor(int, int);
void clearScreen();

//Global Variables
//Color Control, 0=Red, 1=Yellow, 2=Green, 3=Blue, 4=Cyan, 5=Purple, 6=White,
int currentColor = 0;
int col = 99;
int row = 50;
bool isDrawing = false;
bool fastCursor = false;

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
	printf("\x1b[6;14H\e[40mPixel-Painter");
	printf("\x1b[10;17HControls");
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
		if (kDown & KEY_MINUS) clearScreen();
		//Handle A
		if (kDown & KEY_A)
		{
			if (isDrawing)
				isDrawing = false;
			else
				isDrawing = true;
			updateCursor(row, col);
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
			updateColorSelection();
		}
		//Handle R
		if (kDown & KEY_R)
		{
			currentColor++;
			if (currentColor > 6)
				currentColor = 0;
			updateColorSelection();
		}
		//Handle Up
		if  ((kDown & KEY_UP) || (fastCursor && (kHeld & KEY_UP)))
		{
			int tempRow = row;
			row--;
			if (row == 1)
			row = 89;
			updateCursor(tempRow, col);
		}
		//Handle Down
		if  ((kDown & KEY_DOWN) || (fastCursor && (kHeld & KEY_DOWN)))
		{
			int tempRow = row;
			row++;
			if (row == 90)
			row = 2;
			updateCursor(tempRow, col);
		}
		//Handle Left
		if  ((kDown & KEY_LEFT) || (fastCursor && (kHeld & KEY_LEFT)))
		{
			int tempCol = col;
			col--;
			if (col == 41)
			col = 159;
			updateCursor(row, tempCol);
		}
		//Handle Right
		if  ((kDown & KEY_RIGHT) || (fastCursor && (kHeld & KEY_RIGHT)))
		{
			int tempCol = col;
			col++;
			if (col == 160)
			col = 42;
			updateCursor(row, tempCol);
		}

		gfxFlushBuffers();
		gfxSwapBuffers();
		gfxWaitForVsync();
	}

	gfxExit();
	return 0;
}

void updateColorSelection()
{
	//Update Selection
	for (int j = 31; j < 37; j++)
	{
		if (currentColor == 0)
			printf("\x1b[%d;7H\e[41m                             ", j);
		else
			printf("\x1b[%d;7H\e[40m                             ", j);
		if (currentColor == 1)
			printf("\x1b[%d;7H\e[43m                             ", j+8);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+8);
		if (currentColor == 2)
			printf("\x1b[%d;7H\e[42m                             ", j+16);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+16);
		if (currentColor == 3)
			printf("\x1b[%d;7H\e[44m                             ", j+24);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+24);
		if (currentColor == 4)
			printf("\x1b[%d;7H\e[46m                             ", j+32);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+32);
		if (currentColor == 5)
			printf("\x1b[%d;7H\e[45m                             ", j+40);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+40);
		if (currentColor == 6)
			printf("\x1b[%d;7H\e[47m                             ", j+48);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+48);
	}
	updateCursor(row, col);
}

void updateCursor(int prevRow, int prevCol)
{
	//Update Cursor Color and Position
	if (isDrawing)
	{
		if (currentColor == 0)
		{
			printf("\x1b[%d;%dH\e[41m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 1)
		{
			printf("\x1b[%d;%dH\e[43m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 2)
		{
			printf("\x1b[%d;%dH\e[42m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 3)
		{
			printf("\x1b[%d;%dH\e[44m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 4)
		{
			printf("\x1b[%d;%dH\e[46m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 5)
		{
			printf("\x1b[%d;%dH\e[45m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 6)
		{
			printf("\x1b[%d;%dH\e[47m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
	}
	else
	{
		printf("\x1b[%d;%dH\e[40m ", prevRow, prevCol);
		printf("\x1b[%d;%dH#", row, col);
	}
}

void clearScreen()
{
	//Clear Drawing Area
	for (int j = 2; j < 90; j++)
	{
		printf("\x1b[%d;42H\e[40m                                                                                                                      ", j);
	}
	updateCursor(row, col);
}