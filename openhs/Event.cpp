#include "Event.h"

void Event::occur(Board &board) {
	act(board);
}

Event::~Event() {}
