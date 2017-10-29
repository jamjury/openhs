#ifndef WINSTONE_BOARD_H
#define WINSTONE_BOARD_H


#include "Player.h"

class Board {
public:
	Player *player_one, *player_two;
	Player *current_player;

	Board();
	~Board();
};


#endif //WINSTONE_BOARD_H
