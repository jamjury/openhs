#include "event/Event.h"
#include "Board.h"
#include "Player.h"

Board::Board() {
	player1 = new Player;
	player2 = new Player;
	cur_player = player1;
}

Board::~Board() {
	delete player1;
	delete player2;
}

void Board::trigger_conseq(Event *event) {
	for (auto &conseq : triggered_events[typeid(*event)]) {
		conseq->set_board(this);
		conseq->occur();
	}
}

Player &Board::get_cur_opp() const {
	return cur_player == player2 ? *player1 : *player2;
}

void Board::switch_player() {
	cur_player = &get_cur_opp();
}

Player &Board::get_cur_player() const {
	return *cur_player;
}
