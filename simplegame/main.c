#include <stdio.h>
#include <conio.h>
#include <stdbool.h>


#include "player.h"

int main(void) {
	struct player * newplayer = create_player('X', 15, 15, 70, 25);
	display(newplayer);

	int checkquit = 0;

	while (true) {
		while (_kbhit() != 0) {
			char ch = _getch();
			if (ch == 'w' || ch == 'W') {
				movey(newplayer, -1);
				display(newplayer);
			}
			else if (ch == 's' || ch == 'S') {
				movey(newplayer, 1);
				display(newplayer);
			}
			else if (ch == 'a' || ch == 'A') {
				movex(newplayer, -1);
				display(newplayer);
			}
			else if (ch == 'd' || ch == 'D') {
				movex(newplayer, 1);
				display(newplayer);
			}
			else if (ch == 'q' || ch == 'Q') {
				checkquit = 1;
				break;
			}
		}
		if (checkquit == 1) {
			break;
		}
	}
	delete_player(newplayer);
	return 0;
}