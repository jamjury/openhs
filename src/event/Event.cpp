#include "Event.h"
#include <stdexcept>

Event::Event() :
	board(nullptr)
{}

Event::Event(Board *board) :
	board(board)
{}

void Event::occur() {
	if (!board)
		throw std::runtime_error("Event can't occur without board");
}

void Event::set_board(Board *board) {
	Event::board = board;
}
