#include "CombinedEvent.h"

CombinedEvent::CombinedEvent(
	std::unique_ptr<Event> first,
	std::unique_ptr<Event> second
) :
	first(std::move(first)),
	second(std::move(second))
{}

void CombinedEvent::occur() {
	Event::occur();
	first->set_board(board);
	first->occur();
	second->set_board(board);
	second->occur();
}
