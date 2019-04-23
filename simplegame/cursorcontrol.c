#include <windows.h>

void gotoxy(int x, int y)
{
	COORD position;
	position.X = x - 1;
	position.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void gotostart(void) {
	gotoxy(1, 1);
}