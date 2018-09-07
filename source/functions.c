#include <stdio.h>
#include <switch.h>
#include "functions.h"

void updateColorSelection(int row, int col, int currentColor, bool isDrawing, int cursorSize)
{
	//Update Selection
	for (int j = 31; j < 34; j++)
	{
		if (currentColor == 0)
			printf("\x1b[%d;7H\e[41m                             ", j);
		else
			printf("\x1b[%d;7H\e[40m                             ", j);
		if (currentColor == 1)
			printf("\x1b[%d;7H\e[43m                             ", j+5);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+5);
		if (currentColor == 2)
			printf("\x1b[%d;7H\e[42m                             ", j+10);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+10);
		if (currentColor == 3)
			printf("\x1b[%d;7H\e[44m                             ", j+15);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+15);
		if (currentColor == 4)
			printf("\x1b[%d;7H\e[46m                             ", j+20);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+20);
		if (currentColor == 5)
			printf("\x1b[%d;7H\e[45m                             ", j+25);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+25);
		if (currentColor == 6)
			printf("\x1b[%d;7H\e[47m                             ", j+30);
		else
			printf("\x1b[%d;7H\e[40m                             ", j+30);
	}
	if (cursorSize == 0)
		updateCursor1x1(row, col, row, col, currentColor, isDrawing, false, 0);
	if (cursorSize == 1)
		updateCursor2x2(row, col, row, col, currentColor, isDrawing, false, 0);
	if (cursorSize == 2)
		updateCursor3x3(row, col, row, col, currentColor, isDrawing, false, 0);
	if (cursorSize == 3)
		updateCursor4x4(row, col, row, col, currentColor, isDrawing, false, 0);
}

void clearScreen(int row, int col, int currentColor, bool isDrawing, int cursorSize)
{
	//Clear Drawing Area
	for (int j = 2; j < 67; j++)
	{
		printf("\x1b[%d;42H\e[40m                                                                              ", j);
	}
	if (cursorSize == 0)
		updateCursor1x1(row, col, row, col, currentColor, isDrawing, false, 0);
	if (cursorSize == 1)
		updateCursor2x2(row, col, row, col, currentColor, isDrawing, false, 0);
	if (cursorSize == 2)
		updateCursor3x3(row, col, row, col, currentColor, isDrawing, false, 0);
	if (cursorSize == 3)
		updateCursor4x4(row, col, row, col, currentColor, isDrawing, false, 0);
}

void updateCursor1x1(int prevRow, int prevCol, int row, int col, int currentColor, bool isDrawing, bool changedSize, int prevSize)
{
	//Update Cursor Color and Position
	if (isDrawing)
	{
		if (currentColor == 0)
		{
			if (changedSize && (prevSize == 1))
			{
				printf("\x1b[%d;%dH\e[41m  ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[41m  ", prevRow+1, prevCol);
			}
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[41m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[41m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[41m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[41m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[41m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 1)
		{
			if (changedSize && (prevSize == 1))
			{
				printf("\x1b[%d;%dH\e[43m  ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[43m  ", prevRow+1, prevCol);
			}
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[43m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[43m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[43m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[43m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[43m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 2)
		{
			if (changedSize && (prevSize == 1))
			{
				printf("\x1b[%d;%dH\e[42m  ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[42m  ", prevRow+1, prevCol);
			}
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[42m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[42m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[42m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[42m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[42m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 3)
		{
			if (changedSize && (prevSize == 1))
			{
				printf("\x1b[%d;%dH\e[44m  ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[44m  ", prevRow+1, prevCol);
			}
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[44m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[44m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[44m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[44m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[44m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 4)
		{
			if (changedSize && (prevSize == 1))
			{
				printf("\x1b[%d;%dH\e[46m  ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[46m  ", prevRow+1, prevCol);
			}
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[46m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[46m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[46m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[46m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[46m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 5)
		{
			if (changedSize && (prevSize == 1))
			{
				printf("\x1b[%d;%dH\e[45m  ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[45m  ", prevRow+1, prevCol);
			}
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[45m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[45m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[45m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[45m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[45m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
		if (currentColor == 6)
		{if (changedSize && (prevSize == 1))
			{
				printf("\x1b[%d;%dH\e[47m  ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[47m  ", prevRow+1, prevCol);
			}
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[47m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[47m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[47m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[47m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[47m ", prevRow, prevCol);
			printf("\x1b[%d;%dH#", row, col);
		}
	}
	else
	{
		if (changedSize && (prevSize == 1))
		{
			printf("\x1b[%d;%dH\e[40m  ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[40m  ", prevRow+1, prevCol);
		}
		if (changedSize && (prevSize == 3))
		{
			printf("\x1b[%d;%dH\e[40m    ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[40m    ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[40m    ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH\e[40m    ", prevRow+3, prevCol);
		}
		printf("\x1b[%d;%dH\e[40m ", prevRow, prevCol);
		printf("\x1b[%d;%dH#", row, col);
	}
}

void updateCursor2x2(int prevRow, int prevCol, int row, int col, int currentColor, bool isDrawing, bool changedSize, int prevSize)
{
	//Update Cursor Color and Position
	if (isDrawing)
	{
		if (currentColor == 0)
		{
			if (changedSize && (prevSize == 2))
			{
				printf("\x1b[%d;%dH\e[41m   ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[41m   ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[41m   ", prevRow+2, prevCol);
			}
			printf("\x1b[%d;%dH\e[41m  ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[41m  ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH##", row, col);
			printf("\x1b[%d;%dH##", row+1, col);
		}
		if (currentColor == 1)
		{
			if (changedSize && (prevSize == 2))
			{
				printf("\x1b[%d;%dH\e[43m   ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[43m   ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[43m   ", prevRow+2, prevCol);
			}
			printf("\x1b[%d;%dH\e[43m  ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[43m  ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH##", row, col);
			printf("\x1b[%d;%dH##", row+1, col);
		}
		if (currentColor == 2)
		{
			if (changedSize && (prevSize == 2))
			{
				printf("\x1b[%d;%dH\e[42m   ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[42m   ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[42m   ", prevRow+2, prevCol);
			}
			printf("\x1b[%d;%dH\e[42m  ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[42m  ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH##", row, col);
			printf("\x1b[%d;%dH##", row+1, col);
		}
		if (currentColor == 3)
		{
			if (changedSize && (prevSize == 2))
			{
				printf("\x1b[%d;%dH\e[44m   ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[44m   ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[44m   ", prevRow+2, prevCol);
			}
			printf("\x1b[%d;%dH\e[44m  ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[44m  ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH##", row, col);
			printf("\x1b[%d;%dH##", row+1, col);
		}
		if (currentColor == 4)
		{
			if (changedSize && (prevSize == 2))
			{
				printf("\x1b[%d;%dH\e[46m   ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[46m   ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[46m   ", prevRow+2, prevCol);
			}
			printf("\x1b[%d;%dH\e[46m  ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[46m  ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH##", row, col);
			printf("\x1b[%d;%dH##", row+1, col);
		}
		if (currentColor == 5)
		{
			if (changedSize && (prevSize == 2))
			{
				printf("\x1b[%d;%dH\e[45m   ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[45m   ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[45m   ", prevRow+2, prevCol);
			}
			printf("\x1b[%d;%dH\e[45m  ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[45m  ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH##", row, col);
			printf("\x1b[%d;%dH##", row+1, col);
		}
		if (currentColor == 6)
		{
			if (changedSize && (prevSize == 2))
			{
				printf("\x1b[%d;%dH\e[47m   ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[47m   ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[47m   ", prevRow+2, prevCol);
			}
			printf("\x1b[%d;%dH\e[47m  ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[47m  ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH##", row, col);
			printf("\x1b[%d;%dH##", row+1, col);
		}
	}
	else
	{
		if (changedSize && (prevSize == 2))
		{
			printf("\x1b[%d;%dH\e[40m   ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[40m   ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[40m   ", prevRow+2, prevCol);
		}
		printf("\x1b[%d;%dH\e[40m  ", prevRow, prevCol);
		printf("\x1b[%d;%dH\e[40m  ", prevRow+1, prevCol);
		printf("\x1b[%d;%dH##", row, col);
		printf("\x1b[%d;%dH##", row+1, col);
	}
}

void updateCursor3x3(int prevRow, int prevCol, int row, int col, int currentColor, bool isDrawing, bool changedSize, int prevSize)
{
	//Update Cursor Color and Position
	if (isDrawing)
	{
		if (currentColor == 0)
		{
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[41m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[41m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[41m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[41m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[41m   ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[41m   ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[41m   ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH###", row, col);
			printf("\x1b[%d;%dH###", row+1, col);
			printf("\x1b[%d;%dH###", row+2, col);
		}
		if (currentColor == 1)
		{
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[43m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[43m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[43m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[43m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[43m   ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[43m   ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[43m   ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH###", row, col);
			printf("\x1b[%d;%dH###", row+1, col);
			printf("\x1b[%d;%dH###", row+2, col);
		}
		if (currentColor == 2)
		{
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[42m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[42m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[42m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[42m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[42m   ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[42m   ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[42m   ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH###", row, col);
			printf("\x1b[%d;%dH###", row+1, col);
			printf("\x1b[%d;%dH###", row+2, col);
		}
		if (currentColor == 3)
		{
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[44m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[44m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[44m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[44m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[44m   ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[44m   ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[44m   ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH###", row, col);
			printf("\x1b[%d;%dH###", row+1, col);
			printf("\x1b[%d;%dH###", row+2, col);
		}
		if (currentColor == 4)
		{
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[46m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[46m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[46m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[46m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[46m   ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[46m   ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[46m   ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH###", row, col);
			printf("\x1b[%d;%dH###", row+1, col);
			printf("\x1b[%d;%dH###", row+2, col);
		}
		if (currentColor == 5)
		{
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[45m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[45m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[45m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[45m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[45m   ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[45m   ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[45m   ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH###", row, col);
			printf("\x1b[%d;%dH###", row+1, col);
			printf("\x1b[%d;%dH###", row+2, col);
		}
		if (currentColor == 6)
		{
			if (changedSize && (prevSize == 3))
			{
				printf("\x1b[%d;%dH\e[47m    ", prevRow, prevCol);
				printf("\x1b[%d;%dH\e[47m    ", prevRow+1, prevCol);
				printf("\x1b[%d;%dH\e[47m    ", prevRow+2, prevCol);
				printf("\x1b[%d;%dH\e[47m    ", prevRow+3, prevCol);
			}
			printf("\x1b[%d;%dH\e[47m   ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[47m   ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[47m   ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH###", row, col);
			printf("\x1b[%d;%dH###", row+1, col);
			printf("\x1b[%d;%dH###", row+2, col);
		}
	}
	else
	{
		if (changedSize && (prevSize == 3))
		{
			printf("\x1b[%d;%dH\e[40m    ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[40m    ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[40m    ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH\e[40m    ", prevRow+3, prevCol);
		}
		printf("\x1b[%d;%dH\e[40m   ", prevRow, prevCol);
		printf("\x1b[%d;%dH\e[40m   ", prevRow+1, prevCol);
		printf("\x1b[%d;%dH\e[40m   ", prevRow+2, prevCol);
		printf("\x1b[%d;%dH###", row, col);
		printf("\x1b[%d;%dH###", row+1, col);
		printf("\x1b[%d;%dH###", row+2, col);
	}
}

void updateCursor4x4(int prevRow, int prevCol, int row, int col, int currentColor, bool isDrawing, bool changedSize, int prevSize)
{
	//Update Cursor Color and Position
	if (isDrawing)
	{
		if (currentColor == 0)
		{
			printf("\x1b[%d;%dH\e[41m    ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[41m    ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[41m    ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH\e[41m    ", prevRow+3, prevCol);
			printf("\x1b[%d;%dH####", row, col);
			printf("\x1b[%d;%dH####", row+1, col);
			printf("\x1b[%d;%dH####", row+2, col);
			printf("\x1b[%d;%dH####", row+3, col);
		}
		if (currentColor == 1)
		{
			printf("\x1b[%d;%dH\e[43m    ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[43m    ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[43m    ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH\e[43m    ", prevRow+3, prevCol);
			printf("\x1b[%d;%dH####", row, col);
			printf("\x1b[%d;%dH####", row+1, col);
			printf("\x1b[%d;%dH####", row+2, col);
			printf("\x1b[%d;%dH####", row+3, col);
		}
		if (currentColor == 2)
		{
			printf("\x1b[%d;%dH\e[42m    ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[42m    ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[42m    ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH\e[42m    ", prevRow+3, prevCol);
			printf("\x1b[%d;%dH####", row, col);
			printf("\x1b[%d;%dH####", row+1, col);
			printf("\x1b[%d;%dH####", row+2, col);
			printf("\x1b[%d;%dH####", row+3, col);
		}
		if (currentColor == 3)
		{
			printf("\x1b[%d;%dH\e[44m    ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[44m    ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[44m    ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH\e[44m    ", prevRow+3, prevCol);
			printf("\x1b[%d;%dH####", row, col);
			printf("\x1b[%d;%dH####", row+1, col);
			printf("\x1b[%d;%dH####", row+2, col);
			printf("\x1b[%d;%dH####", row+3, col);
		}
		if (currentColor == 4)
		{
			printf("\x1b[%d;%dH\e[46m    ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[46m    ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[46m    ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH\e[46m    ", prevRow+3, prevCol);
			printf("\x1b[%d;%dH####", row, col);
			printf("\x1b[%d;%dH####", row+1, col);
			printf("\x1b[%d;%dH####", row+2, col);
			printf("\x1b[%d;%dH####", row+3, col);
		}
		if (currentColor == 5)
		{
			printf("\x1b[%d;%dH\e[45m    ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[45m    ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[45m    ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH\e[45m    ", prevRow+3, prevCol);
			printf("\x1b[%d;%dH####", row, col);
			printf("\x1b[%d;%dH####", row+1, col);
			printf("\x1b[%d;%dH####", row+2, col);
			printf("\x1b[%d;%dH####", row+3, col);
		}
		if (currentColor == 6)
		{
			printf("\x1b[%d;%dH\e[47m    ", prevRow, prevCol);
			printf("\x1b[%d;%dH\e[47m    ", prevRow+1, prevCol);
			printf("\x1b[%d;%dH\e[47m    ", prevRow+2, prevCol);
			printf("\x1b[%d;%dH\e[47m    ", prevRow+3, prevCol);
			printf("\x1b[%d;%dH####", row, col);
			printf("\x1b[%d;%dH####", row+1, col);
			printf("\x1b[%d;%dH####", row+2, col);
			printf("\x1b[%d;%dH####", row+3, col);
		}
	}
	else
	{
		printf("\x1b[%d;%dH\e[40m    ", prevRow, prevCol);
		printf("\x1b[%d;%dH\e[40m    ", prevRow+1, prevCol);
		printf("\x1b[%d;%dH\e[40m    ", prevRow+2, prevCol);
		printf("\x1b[%d;%dH\e[40m    ", prevRow+3, prevCol);
		printf("\x1b[%d;%dH####", row, col);
		printf("\x1b[%d;%dH####", row+1, col);
		printf("\x1b[%d;%dH####", row+2, col);
		printf("\x1b[%d;%dH####", row+3, col);
	}
}

int checkForRowCursorOverlap(int row, int newSize)
{
	while (row > 66-newSize)
	{
		row--;
	}
	return row;
}

int checkForColCursorOverlap(int col, int newSize)
{
	while (col > 119-newSize)
	{
		col--;
	}
	return col;
}
