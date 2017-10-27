#include "CombinedEvent.h"

CombinedEvent::CombinedEvent(Event *first, Event *second) :
	first(first),
	second(second)
{}

void CombinedEvent::occur(Player &player) {
	first->occur(player);
	second->occur(player);
}

CombinedEvent::~CombinedEvent() {
	delete first;
	delete second;
}
