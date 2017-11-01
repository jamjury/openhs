#include "Event.h"
#include "Board.h"

Event::Event() :
	board(nullptr)
{}

Event::Event(Board *board) :
	board(board)
{}

void Event::set_board(Board *board) {
	Event::board = board;
}

void Event::occur() {
	if (!board)
		throw std::runtime_error("Event can't occur without board."
			"You should call set_board() first");
	act();
	resolve();
}

void Event::resolve() {
	board->trigger_conseq(this);
}
