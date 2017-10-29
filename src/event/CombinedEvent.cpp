#include "CombinedEvent.h"

CombinedEvent::CombinedEvent(
	std::unique_ptr<Event> first,
	std::unique_ptr<Event> second
) :
	first(std::move(first)),
	second(std::move(second))
{}

void CombinedEvent::occur(Player &player) {
	first->occur(player);
	second->occur(player);
}
