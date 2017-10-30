#include "CombinedEvent.h"

CombinedEvent::CombinedEvent(
	std::unique_ptr<Event> first,
	std::unique_ptr<Event> second
) :
	first(std::move(first)),
	second(std::move(second))
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
