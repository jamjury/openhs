#include "Board.h"
#include "TriggerContainer.h"

Board::Board() :
	player1(),
	player2(),
	cur_player(&player1),
	triggers(*this)
{}

Player &Board::get_cur_opp() {
	return cur_player == &player1 ? player2 : player1;
}

void Board::switch_player() {
	cur_player = &get_cur_opp();
}

Player &Board::get_cur_player() {
	return *cur_player;
}
