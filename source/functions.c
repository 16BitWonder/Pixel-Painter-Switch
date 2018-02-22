#include <stdio.h>
#include <switch.h>
#include "functions.h"

void updateColorSelection(int row, int col, int currentColor, bool isDrawing)
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
	updateCursor(row, col, row, col, currentColor, isDrawing);
}

void updateCursor(int prevRow, int prevCol, int row, int col, int currentColor, bool isDrawing)
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

void clearScreen(int row, int col, int currentColor, bool isDrawing)
{
	//Clear Drawing Area
	for (int j = 2; j < 90; j++)
	{
		printf("\x1b[%d;42H\e[40m                                                                                                                      ", j);
	}
	updateCursor(row, col, row, col, currentColor, isDrawing);
}