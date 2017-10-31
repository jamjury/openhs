#include "Board.h"
#include "Player.h"

Board::Board() {
	player_one = new Player;
	player_two = new Player;
	current_player = player_one;
}

Board::~Board() {
	delete player_one;
	delete player_two;
}

void Board::trigger_consequences(Event *event) {
	for (auto &consequence : triggered_events[typeid(*event)]) {
		consequence->set_board(this);
		consequence->occur();
	}
}