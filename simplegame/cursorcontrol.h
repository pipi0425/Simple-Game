#pragma once


//gotoxy(int x, int y) moves cursor to position (x - 1, y - 1)
//(0,0) -> (x,0)
//    ......
//(0,y) -> (x,y)
void gotoxy(int x, int y);

//gotostart() calls gotoxy and move to (1,1)
void gotostart(void);