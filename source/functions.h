//Row, Col, currentColor, isDrawing
void updateColorSelection(int, int, int, bool, int);

//prevRow, prevCol, row, col, currentColor, isDrawing, changedSize, prevSize
void updateCursor1x1(int, int, int, int, int, bool, bool, int);
void updateCursor2x2(int, int, int, int, int, bool, bool, int);
void updateCursor3x3(int, int, int, int, int, bool, bool, int);
void updateCursor4x4(int, int, int, int, int, bool, bool, int);

//row, col, currentColor, isDrawing
void clearScreen(int, int, int, bool, int);