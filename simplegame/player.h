#pragma once

struct player;

//create a player using malloc
//initialize position and symbol
//return its pointer
//if malloc fails, return NULL
struct player * create_player(char sym, int x, int y, int max_x, int max_y);

//move player by (deltax, 0)
//this function is for relative position
void movex(struct player * plr, int deltax);

//move player by (0, deltay)
//this function is for relative position
void movey(struct player * plr, int deltay);

//move player to (x, y)
//this function is for absolute position
void setposition(struct player * plr, int x, int y);

//get position of player and pass by pointer
void getposition(struct player * plr, int * x, int * y);

//display the player's position
//require cursorcontrol
void display(struct player * plr);

//delete the player by free
void delete_player(struct player * plr);