#include <stdio.h>
#include <stdlib.h>
#include "cursorcontrol.h"

struct player {
	char symbol;
	int x;
	int y;
	int prev_x;
	int prev_y;
	int max_x;
	int max_y;
};

struct player * create_player(char sym, int x, int y, int max_x, int max_y) {
	struct player * thisptr = malloc(sizeof(struct player));
	if (thisptr == NULL) {
		return thisptr;
	}
	else {
		thisptr->symbol = sym;
		thisptr->x = x;
		thisptr->y = y;
		thisptr->prev_x = 1;
		thisptr->prev_y = 1;
		thisptr->max_x = max_x;
		thisptr->max_y = max_y;
		return thisptr;
	}
}

void movex(struct player * plr, int deltax) {
	int newx = plr->x + deltax;
	if (newx > plr->max_x) {
		newx = plr->max_x;
	}
	if (newx < 1) {
		newx = 1;
	}
	plr->prev_x = plr->x;
	plr->prev_y = plr->y;
	plr->x = newx;
}

void movey(struct player * plr, int deltay) {
	int newy = plr->y + deltay;
	if (newy > plr->max_y) {
		newy = plr->max_y;
	}
	if (newy < 1) {
		newy = 1;
	}
	plr->prev_x = plr->x;
	plr->prev_y = plr->y;
	plr->y = newy;
}

void setposition(struct player * plr, int x, int y) {
	int newx = x;
	int newy = y;
	if (newx > plr->max_x) {
		newx = plr->max_x;
	}
	if (newx < 1) {
		newx = 1;
	}
	if (newy > plr->max_y) {
		newy = plr->max_y;
	}
	if (newy < 1) {
		newy = 1;
	}
	plr->prev_x = plr->x;
	plr->prev_y = plr->y;
	plr->x = newx;
	plr->y = newy;
}

void getposition(struct player * plr, int * x, int * y) {
	*x = plr->x;
	*y = plr->y;
}

void display(struct player * plr) {
	gotoxy(plr->prev_x, plr->prev_y);
	printf(" ");
	gotoxy(plr->x, plr->y);
	printf("%c", plr->symbol);
	gotoxy(plr->max_x, plr->max_y);
}

void delete_player(struct player * plr) {
	free(plr);
}