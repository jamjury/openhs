#include "event/Event.h"
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

void Board::trigger_conseq(Event *event) {
	for (auto &conseq : triggered_events[typeid(*event)]) {
		conseq->set_board(this);
		conseq->occur();
	}
}

Player *Board::current_opponent() {
	return current_player == player_two ? player_one : player_two;
}

void Board::switch_player() {
	current_player = current_opponent();
}
