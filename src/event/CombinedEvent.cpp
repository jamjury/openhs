#include "CombinedEvent.h"

CombinedEvent::CombinedEvent(
	std::unique_ptr<Event> first,
	std::unique_ptr<Event> second
) :
	first(std::move(first)),
	second(std::move(second))
{}

void CombinedEvent::occur(Board &board) {
	first->occur(board);
	second->occur(board);
}
