#include <string.h>
#include <stdio.h>

#include <switch.h>

//Declare Functions
void updateColorSelection();
void updateCursor(int, int);

//Global Variables
//Color Control, 0=Red, 1=Yellow, 2=Green, 3=Blue, 4=Cyan, 5=Purple,
int currentColor = 0;
int col = 99;
int row = 50;
bool isDrawing = false;

int main(int argc, char **argv)
{
	gfxInitDefault();

	//Initialize console. Using NULL as the second argument tells the console library to use the internal console structure as current one.
	consoleInit(NULL);

	//Draw Frame
	printf("\x1b[0;0H\x1b[47m                                                                                                                                                                ");
	printf("\x1b[100;0H                                                                                                                                                                ");
	for (int j = 2; j < 90; j++)
	{
		printf("\x1b[%d;0H ", j);
		printf("\x1b[%d;41H ", j);
		printf("\x1b[%d;160H ", j);
	}
	
	//Draw Controls
	printf("\x1b[9;14H\x1b[40mPixel-Painter");
	printf("\x1b[14;17HControls");
	printf("\x1b[17;6HLPad/LStick = Cursor controller");
	printf("\x1b[20;8HL/R = Cycle colors up/down");
	printf("\x1b[23;8HA = Toggle drawing/erasing");
	printf("\x1b[26;10HPlus = Exits to HBmenu");

	//Draw Out Color Selection
	for (int j = 30; j < 37; j++)
	{
		printf("\x1b[%d;2H\x1b[41m                                       ", j);
		printf("\x1b[%d;2H\x1b[43m     ", j+10);
		printf("\x1b[%d;36H\x1b[43m     ", j+10);
		printf("\x1b[%d;2H\x1b[42m     ", j+20);
		printf("\x1b[%d;36H\x1b[42m     ", j+20);
		printf("\x1b[%d;2H\x1b[44m     ", j+30);
		printf("\x1b[%d;36H\x1b[44m     ", j+30);
		printf("\x1b[%d;2H\x1b[46m     ", j+40);
		printf("\x1b[%d;36H\x1b[46m     ", j+40);
		printf("\x1b[%d;2H\x1b[45m     ", j+50);
		printf("\x1b[%d;36H\x1b[45m     ", j+50);
	}
	
	//Draw out initial cursor position
	printf("\x1b[%d;%dH\x1b[40m#", row, col);
	
	while(appletMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();
		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		if (kDown & KEY_PLUS) break; // break in order to return to hbmenu
		
		if (kDown & KEY_A)
		{
			if (isDrawing)
				isDrawing = false;
			else
				isDrawing = true;
			updateCursor(row, col);
		}
		if (kDown & KEY_L)
		{
			currentColor--;
			if (currentColor < 0)
				currentColor = 5;
			updateColorSelection();
		}
		if (kDown & KEY_R)
		{
			currentColor++;
			if (currentColor > 5)
				currentColor = 0;
			updateColorSelection();
		}
		if (kDown & KEY_UP)
		{
			int tempRow = row;
			row--;
			if (row == 1)
				row = 89;
			updateCursor(tempRow, col);
		}
		if (kDown & KEY_DOWN)
		{
			int tempRow = row;
			row++;
			if (row == 90)
				row = 2;
			updateCursor(tempRow, col);
		}
		if (kDown & KEY_LEFT)
		{
			int tempCol = col;
			col--;
			if (col == 41)
				col = 159;
			updateCursor(row, tempCol);
		}
		if (kDown & KEY_RIGHT)
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
	for (int j = 30; j < 37; j++)
	{
		if (currentColor == 0)
			printf("\x1b[%d;7H\x1b[41m                             ", j);
		else
			printf("\x1b[%d;7H\x1b[40m                             ", j);
		if (currentColor == 1)
			printf("\x1b[%d;7H\x1b[43m                             ", j+10);
		else
			printf("\x1b[%d;7H\x1b[40m                             ", j+10);
		if (currentColor == 2)
			printf("\x1b[%d;7H\x1b[42m                             ", j+20);
		else
			printf("\x1b[%d;7H\x1b[40m                             ", j+20);
		if (currentColor == 3)
			printf("\x1b[%d;7H\x1b[44m                             ", j+30);
		else
			printf("\x1b[%d;7H\x1b[40m                             ", j+30);
		if (currentColor == 4)
			printf("\x1b[%d;7H\x1b[46m                             ", j+40);
		else
			printf("\x1b[%d;7H\x1b[40m                             ", j+40);
		if (currentColor == 5)
			printf("\x1b[%d;7H\x1b[45m                             ", j+50);
		else
			printf("\x1b[%d;7H\x1b[40m                             ", j+50);
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
			printf("\x1b[%d;%dH\x1b[41m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 1)
		{
			printf("\x1b[%d;%dH\x1b[43m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 2)
		{
			printf("\x1b[%d;%dH\x1b[42m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 3)
		{
			printf("\x1b[%d;%dH\x1b[44m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 4)
		{
			printf("\x1b[%d;%dH\x1b[46m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 5)
		{
			printf("\x1b[%d;%dH\x1b[45m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
	}
	else
	{
		printf("\x1b[%d;%dH\x1b[40m ", prevRow, prevCol);
		printf("\x1b[%d;%dH#", row, col);
	}
}