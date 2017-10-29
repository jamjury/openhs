#include "Board.h"

Board::Board() {
	player_one = new Player;
	player_two = new Player;
	current_player = player_one;
}

Board::~Board() {
	delete player_one;
	delete player_two;
}
