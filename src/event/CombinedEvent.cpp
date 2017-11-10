#include "CombinedEvent.h"

CombinedEvent::CombinedEvent(
	Event *first,
	Event *second
) :
	first(first),
	second(second)
{}

void CombinedEvent::act() {
	first->occur();
	second->occur();
}

void CombinedEvent::set_board(Board *board) {
	Event::set_board(board);
	first->set_board(board);
	second->set_board(board);
}

CombinedEvent::~CombinedEvent() {
	delete first;
	delete second;
}
